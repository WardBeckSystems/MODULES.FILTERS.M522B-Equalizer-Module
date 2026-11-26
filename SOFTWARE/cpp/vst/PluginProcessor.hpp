#pragma once
#include "../core/SharedPluginFrame.hpp"
#include "../core/StateVariableCore.hpp"
#include "../core/NonLinearCore.hpp"

namespace wbs::m522b {

class M522BPluginProcessor : public engine::SharedPluginFrame {
public:
    M522BPluginProcessor();
    ~M522BPluginProcessor() override = default;

    void prepareModule(double hostRate, double oversampledRate, size_t maxBlockSize, size_t numChannels) override;
    void releaseModule() override;
    void updateParametersFromHost() noexcept override;
    void processModuleSlice(engine::AudioBlock& slice) noexcept override;
    void updateMeters(const engine::AudioBlock& audioBlock) noexcept override;

    // Parameter setters
    void setHpfEngaged(bool engaged) noexcept;
    void setLfParams(float freqHz, float gainDb, bool isBell) noexcept;
    void setLfFreq(float freqHz) noexcept { lfFreq_ = std::clamp(freqHz, 40.0f, 500.0f); }
    void setLfGain(float gainDb) noexcept { lfGain_ = std::clamp(gainDb, -15.0f, 15.0f); }
    void setLfBell(bool isBell) noexcept { lfBell_ = isBell; }
    void setMf1Params(float freqHz, float gainDb, bool narrowQ) noexcept; // narrow: 2.5, wide: 0.8
    void setMf1Freq(float freqHz) noexcept { mf1Freq_ = std::clamp(freqHz, 150.0f, 2500.0f); }
    void setMf1Gain(float gainDb) noexcept { mf1Gain_ = std::clamp(gainDb, -15.0f, 15.0f); }
    void setMf1Narrow(bool narrowQ) noexcept { mf1Narrow_ = narrowQ; }
    void setMf2Params(float freqHz, float gainDb, bool narrowQ) noexcept;
    void setMf2Freq(float freqHz) noexcept { mf2Freq_ = std::clamp(freqHz, 1000.0f, 14000.0f); }
    void setMf2Gain(float gainDb) noexcept { mf2Gain_ = std::clamp(gainDb, -15.0f, 15.0f); }
    void setMf2Narrow(bool narrowQ) noexcept { mf2Narrow_ = narrowQ; }
    void setHfParams(float freqHz, float gainDb, bool isBell) noexcept;
    void setHfFreq(float freqHz) noexcept { hfFreq_ = std::clamp(freqHz, 2000.0f, 18000.0f); }
    void setHfGain(float gainDb) noexcept { hfGain_ = std::clamp(gainDb, -15.0f, 15.0f); }
    void setHfBell(bool isBell) noexcept { hfBell_ = isBell; }
    void setBypass(bool bypassed) noexcept;

private:
    engine::StateVariableFilterCore hpfFilter_[engine::kMaxChannels][2]; // 18 dB/oct Butterworth
    engine::StateVariableFilterCore lfBand_[engine::kMaxChannels];
    engine::StateVariableFilterCore mf1Band_[engine::kMaxChannels];
    engine::StateVariableFilterCore mf2Band_[engine::kMaxChannels];
    engine::StateVariableFilterCore hfBand_[engine::kMaxChannels];
    engine::NonLinearTransformerCore biFetStage_[engine::kMaxChannels];

    bool hpfEngaged_{ false };
    float lfFreq_{ 100.0f };
    float lfGain_{ 0.0f };
    bool lfBell_{ false };

    float mf1Freq_{ 600.0f };
    float mf1Gain_{ 0.0f };
    bool mf1Narrow_{ false };

    float mf2Freq_{ 3500.0f };
    float mf2Gain_{ 0.0f };
    bool mf2Narrow_{ false };

    float hfFreq_{ 12000.0f };
    float hfGain_{ 0.0f };
    bool hfBell_{ false };

    bool bypass_{ false };
    float peakMeter_[engine::kMaxChannels]{ 0.0f };
};

} // namespace wbs::m522b
