#include "PluginProcessor.hpp"
#include <cmath>

namespace wbs::m522b {

M522BPluginProcessor::M522BPluginProcessor()
    : engine::SharedPluginFrame("Ward-Beck M522B ST Broadcast EQ", "M522B") {
    defaultOversampling_ = engine::OversamplingRate::TwoX;
}

void M522BPluginProcessor::prepareModule(double hostRate, double oversampledRate, size_t maxBlockSize, size_t numChannels) {
    for (size_t ch = 0; ch < numChannels; ++ch) {
        biFetStage_[ch].prepare(hostRate);
        for (size_t s = 0; s < 2; ++s) {
            hpfFilter_[ch][s].prepare(oversampledRate);
        }
        lfBand_[ch].prepare(oversampledRate);
        mf1Band_[ch].prepare(oversampledRate);
        mf2Band_[ch].prepare(oversampledRate);
        hfBand_[ch].prepare(oversampledRate);
    }
    updateParametersFromHost();
}

void M522BPluginProcessor::releaseModule() {
    for (size_t ch = 0; ch < numChannels_; ++ch) {
        biFetStage_[ch].reset();
        for (size_t s = 0; s < 2; ++s) {
            hpfFilter_[ch][s].reset();
        }
        lfBand_[ch].reset();
        mf1Band_[ch].reset();
        mf2Band_[ch].reset();
        hfBand_[ch].reset();
    }
}

void M522BPluginProcessor::updateParametersFromHost() noexcept {
    for (size_t ch = 0; ch < numChannels_; ++ch) {
        // 80 Hz 18 dB/oct HPF
        hpfFilter_[ch][0].update(80.0, 1.0, 0.0, engine::FilterType::HighPass18dB);
        hpfFilter_[ch][1].update(80.0, 0.5, 0.0, engine::FilterType::HighPass18dB);

        const auto lfType = lfBell_ ? engine::FilterType::PeakingBell : engine::FilterType::LowShelf;
        lfBand_[ch].update(lfFreq_, 0.707, lfGain_, lfType);

        const float q1 = mf1Narrow_ ? 2.5f : 0.8f;
        mf1Band_[ch].update(mf1Freq_, q1, mf1Gain_, engine::FilterType::PeakingBell);

        const float q2 = mf2Narrow_ ? 2.5f : 0.8f;
        mf2Band_[ch].update(mf2Freq_, q2, mf2Gain_, engine::FilterType::PeakingBell);

        const auto hfType = hfBell_ ? engine::FilterType::PeakingBell : engine::FilterType::HighShelf;
        hfBand_[ch].update(hfFreq_, 0.707, hfGain_, hfType);
    }
}

void M522BPluginProcessor::processModuleSlice(engine::AudioBlock& slice) noexcept {
    if (bypass_) return;

    for (size_t ch = 0; ch < slice.numChannels; ++ch) {
        float* channelData = slice.getChannelPointer(ch);

        for (size_t i = 0; i < slice.numSamples; ++i) {
            float s = channelData[i];

            // 1. Optional 80 Hz 18 dB/oct high-pass
            if (hpfEngaged_) {
                s = hpfFilter_[ch][0].processSample(s);
                s = hpfFilter_[ch][1].processSample(s);
            }

            // 2. LF band
            s = lfBand_[ch].processSample(s);

            // 3. Switched-Q Mid 1
            s = mf1Band_[ch].processSample(s);

            // 4. Switched-Q Mid 2
            s = mf2Band_[ch].processSample(s);

            // 5. HF band
            s = hfBand_[ch].processSample(s);

            // 6. ST-series high-headroom Bi-FET output saturation (+28 dBu)
            s = biFetStage_[ch].processSample(s, 1.0f, 0.05f);

            channelData[i] = s;
        }
    }
}

void M522BPluginProcessor::updateMeters(const engine::AudioBlock& audioBlock) noexcept {
    for (size_t ch = 0; ch < audioBlock.numChannels; ++ch) {
        const float* data = audioBlock.getChannelPointer(ch);
        float peak = 0.0f;
        for (size_t i = 0; i < audioBlock.numSamples; ++i) {
            peak = std::max(peak, std::abs(data[i]));
        }
        peakMeter_[ch] = (peakMeter_[ch] * 0.90f) + (peak * 0.10f);
    }
}

void M522BPluginProcessor::setHpfEngaged(bool engaged) noexcept {
    hpfEngaged_ = engaged;
}

void M522BPluginProcessor::setLfParams(float freqHz, float gainDb, bool isBell) noexcept {
    lfFreq_ = std::clamp(freqHz, 40.0f, 500.0f);
    lfGain_ = std::clamp(gainDb, -15.0f, 15.0f);
    lfBell_ = isBell;
}

void M522BPluginProcessor::setMf1Params(float freqHz, float gainDb, bool narrowQ) noexcept {
    mf1Freq_ = std::clamp(freqHz, 150.0f, 2500.0f);
    mf1Gain_ = std::clamp(gainDb, -15.0f, 15.0f);
    mf1Narrow_ = narrowQ;
}

void M522BPluginProcessor::setMf2Params(float freqHz, float gainDb, bool narrowQ) noexcept {
    mf2Freq_ = std::clamp(freqHz, 1000.0f, 14000.0f);
    mf2Gain_ = std::clamp(gainDb, -15.0f, 15.0f);
    mf2Narrow_ = narrowQ;
}

void M522BPluginProcessor::setHfParams(float freqHz, float gainDb, bool isBell) noexcept {
    hfFreq_ = std::clamp(freqHz, 2000.0f, 18000.0f);
    hfGain_ = std::clamp(gainDb, -15.0f, 15.0f);
    hfBell_ = isBell;
}

void M522BPluginProcessor::setBypass(bool bypassed) noexcept {
    bypass_ = bypassed;
}

} // namespace wbs::m522b
