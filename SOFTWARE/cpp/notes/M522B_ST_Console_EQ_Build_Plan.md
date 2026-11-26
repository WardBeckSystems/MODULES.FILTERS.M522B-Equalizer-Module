# Ward-Beck Systems M522B ST-Console Equalizer - VST/AU Plugin Build Plan

**Module Name:** WBS M522B Broadcast Television Console Equalizer  
**Hardware Reference:** Ward-Beck Systems M522B EQ Module (ST2442 / ST3642 Television Production Consoles, ca. 1980–1986)  
**Target Architecture:** VST3 / AU / AAX (JUCE 7 / C++20)  
**Shared Engine Dependency:** [`wbs::SharedPluginFrame`](file:///home/anthony/Documents/GitProjects/WBSps.ca/2030.env/engine/SharedPluginFrame.hpp), [`wbs::StateVariableCore`](file:///home/anthony/Documents/GitProjects/WBSps.ca/2030.env/engine/StateVariableCore.hpp), [`wbs::NonLinearCore`](file:///home/anthony/Documents/GitProjects/WBSps.ca/2030.env/engine/NonLinearCore.hpp)

---

## 1. Hardware Architecture & Circuit Analysis

In the early 1980s, Ward-Beck engineered the ST-series (ST2442, ST3642) specifically for live television broadcast trucks (CBC, ABC, Olympics) where speed of operation, acoustic clarity, and high headroom were critical. The M522B modernized the 400-series topology with:
- **$\pm25\text{ V}$ Bipolar Regulated Power Supply:** Providing an exceptional $+28\text{ dBu}$ internal clip ceiling.
- **Bi-FET & Low-Noise Op-Amps:** Precision Texas Instruments TL072/TL074 front-ends with Signetics NE5534 output drivers.
- **Dual Switched-Q Mid Bands:** Rather than continuous pots which were difficult to recall quickly during live telecasts, the M522B used pushbutton **Narrow ($Q = 2.5$) / Wide ($Q = 0.8$)** switches.
- **Dedicated 18 dB/octave High-Pass Filter:** Integrated $80\text{ Hz}$ Butterworth 3rd-order high-pass filter for eliminating stage rumble and HVAC noise.

### Band Topologies
1. **High-Pass Filter (HPF):** Switchable $80\text{ Hz}$ active 3-pole filter ($18\text{ dB/octave}$).
2. **Low Band (LF):** $40\text{ Hz}$ to $500\text{ Hz}$ continuous frequency; Bell / Shelf switch; $\pm15\text{ dB}$ gain.
3. **Low-Mid Band (MF1):** $150\text{ Hz}$ to $2.5\text{ kHz}$ continuous; Pushbutton Q ($0.8$ Wide / $2.5$ Narrow); $\pm15\text{ dB}$ gain.
4. **High-Mid Band (MF2):** $1.0\text{ kHz}$ to $14.0\text{ kHz}$ continuous; Pushbutton Q ($0.8$ Wide / $2.5$ Narrow); $\pm15\text{ dB}$ gain.
5. **High Band (HF):** $2.0\text{ kHz}$ to $18.0\text{ kHz}$ continuous; Bell / Shelf switch; $\pm15\text{ dB}$ gain.

---

## 2. DSP Architecture & Mathematical Model

### 2.1 18 dB/octave High-Pass Filter
The $80\text{ Hz}$ HPF is realized as a cascaded 1st-order real pole and a 2nd-order complex-conjugate pair (Butterworth alignment $Q = 1.0$ for the pair):
$$H_{HPF}(s) = \frac{s}{s + \omega_c} \cdot \frac{s^2}{s^2 + \omega_c s + \omega_c^2}, \quad \omega_c = 2\pi \cdot 80.0$$
Implemented in discrete form using Zero-Delay Feedback integration to preserve steep phase roll-off without digital cramping near Nyquist.

### 2.2 Switched-Q ZDF Mid Processing
The two mid bands use [`wbs::StateVariableCore`](file:///home/anthony/Documents/GitProjects/WBSps.ca/2030.env/engine/StateVariableCore.hpp) with discrete damping switches:
$$R_{narrow} = \frac{1}{2.5} = 0.40, \quad R_{wide} = \frac{1}{0.8} = 1.25$$
Smooth parameter ramping prevents switch-pop during live adjustment.

---

## 3. Parameter Mapping & State Architecture

| ID | Parameter Name | Range | Steps / Type | Default | Unit |
|---|---|---|---|---|---|
| `m522b_hpf_en` | 80 Hz HPF Switch | In / Out | Toggle | Out | Bool |
| `m522b_lf_freq` | LF Frequency | $40.0$ to $500.0$ | Continuous (Log) | 100.0 | Hz |
| `m522b_lf_gain` | LF Gain | $-15.0$ to $+15.0$ | Continuous | 0.0 | dB |
| `m522b_lf_shape` | LF Mode | Shelf / Bell | 2-way toggle | Shelf | Enum |
| `m522b_mf1_freq` | MF1 Frequency | $150.0$ to $2500.0$ | Continuous (Log) | 600.0 | Hz |
| `m522b_mf1_gain` | MF1 Gain | $-15.0$ to $+15.0$ | Continuous | 0.0 | dB |
| `m522b_mf1_q_mode`| MF1 Q Mode | Wide (0.8) / Narrow (2.5) | 2-way button | Wide | Enum |
| `m522b_mf2_freq` | MF2 Frequency | $1000.0$ to $14000.0$| Continuous (Log) | 3500.0 | Hz |
| `m522b_mf2_gain` | MF2 Gain | $-15.0$ to $+15.0$ | Continuous | 0.0 | dB |
| `m522b_mf2_q_mode`| MF2 Q Mode | Wide (0.8) / Narrow (2.5) | 2-way button | Wide | Enum |
| `m522b_hf_freq` | HF Frequency | $2000.0$ to $18000.0$| Continuous (Log) | 12000.0 | Hz |
| `m522b_hf_gain` | HF Gain | $-15.0$ to $+15.0$ | Continuous | 0.0 | dB |
| `m522b_hf_shape` | HF Mode | Shelf / Bell | 2-way toggle | Shelf | Enum |
| `m522b_bypass` | Master EQ In | In / Out | Toggle | In | Bool |

---

## 4. C++ Plugin Scaffolding

```cpp
// M522BEqualizerProcessor.hpp
#pragma once
#include "SharedPluginFrame.hpp"
#include "StateVariableCore.hpp"
#include "NonLinearCore.hpp"

namespace wbs {

class M522BEqualizerProcessor : public SharedPluginFrame {
public:
    M522BEqualizerProcessor();
    ~M522BEqualizerProcessor() override = default;

    const char* getPluginIdentifier() const noexcept override { return "WBS_M522B_ST_EQ"; }
    uint32_t getPluginVersion() const noexcept override { return 0x010000; }

    void prepareHardwareState(double sampleRate, uint32_t maxBlockSize) override;
    void resetHardwareState() override;
    void processAudioCore(AudioBlock<float>& block) override;

private:
    struct Hpf3Pole {
        float s1 = 0.0f, s2 = 0.0f, s3 = 0.0f;
    } hpf_[2];

    StateVariableCore lfCore_[2];
    StateVariableCore mf1Core_[2];
    StateVariableCore mf2Core_[2];
    StateVariableCore hfCore_[2];

    NonLinearCore biFetSaturation_;
};

} // namespace wbs
```

---

## 5. UI/UX Specification

- **Chassis Design:** ST-series warm bronze / champagne anodized aluminum finish (`#7B7366`) with recessed rectangular illuminated pushbuttons (EAO Series 04 style).
- **Control Layout:** Tall vertical broadcast strip matching ST3642 master channel bay.
- **Indicators:** Amber LEDs illuminated when Narrow Q or HPF are engaged; Green LED for EQ IN.

---

## 6. Verification & Test Plan

1. **HPF Slope Verification:** Measure attenuation slope below $80\text{ Hz}$; verify exactly $18\text{ dB/octave}$ roll-off ($> 36\text{ dB}$ down at $20\text{ Hz}$).
2. **Q-Switch Comparison:** Compare bandwidth at MF1 $1.0\text{ kHz}$ between Wide and Narrow; ensure $-3\text{ dB}$ bandwidth ratio matches $2.5 / 0.8 = 3.125$.
3. **Headroom Test:** Drive $+26\text{ dBu}$ through EQ; verify pristine unclipped throughput before onset of soft Bi-FET rail limiting.
