// Copyright (c) 2026 Ward-Beck Systems (Ward-Beck.com - Ward-Beck.ca). All rights reserved.
// M522B: its part of 2030.env/vst/clap_wrapper/ClapModuleRegistry.cpp (suite index 4).

// --- descriptor ---
static const clap_plugin_descriptor_t s_desc_m522b = {
    CLAP_VERSION,
    "ca.wbsps.m522b_st_console_eq",
    "Ward-Beck M522B ST Broadcast EQ",
    "Ward-Beck Systems Preservation Society",
    "https://wbsps.ca",
    "",
    "https://wbsps.ca/contact",
    "1.0.0",
    "High-headroom ST-series 4-band console EQ with Bi-FET discrete op-amp saturation",
    kEqFeatures
};

// --- parameters ---
std::vector<ParameterInfo> buildM522BParams() {
    std::vector<ParameterInfo> p;
    p.push_back({
        0, "HPF Engage", "Filter", 0.0, 1.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setHpfEngaged(val >= 0.5); },
        nullptr,
        [](double v) { return v >= 0.5 ? "Engaged" : "Off"; },
        nullptr
    });
    p.push_back({
        1, "LF Frequency", "LF Band", 40.0, 500.0, 100.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setLfFreq(static_cast<float>(val)); },
        nullptr,
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%.1f Hz", v); return std::string(buf); },
        nullptr
    });
    p.push_back({
        2, "LF Gain", "LF Band", -15.0, 15.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setLfGain(static_cast<float>(val)); },
        nullptr,
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%+.1f dB", v); return std::string(buf); },
        nullptr
    });
    p.push_back({
        3, "LF Bell / Shelf", "LF Band", 0.0, 1.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setLfBell(val >= 0.5); },
        nullptr,
        [](double v) { return v >= 0.5 ? "Bell" : "Shelf"; },
        nullptr
    });
    p.push_back({
        4, "MF1 Frequency", "MF1 Band", 150.0, 2500.0, 600.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setMf1Freq(static_cast<float>(val)); },
        nullptr,
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%.0f Hz", v); return std::string(buf); },
        nullptr
    });
    p.push_back({
        5, "MF1 Gain", "MF1 Band", -15.0, 15.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setMf1Gain(static_cast<float>(val)); },
        nullptr,
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%+.1f dB", v); return std::string(buf); },
        nullptr
    });
    p.push_back({
        6, "MF1 Q Mode", "MF1 Band", 0.0, 1.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setMf1Narrow(val >= 0.5); },
        nullptr,
        [](double v) { return v >= 0.5 ? "Narrow (2.5)" : "Wide (0.8)"; },
        nullptr
    });
    p.push_back({
        7, "MF2 Frequency", "MF2 Band", 1000.0, 14000.0, 3500.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setMf2Freq(static_cast<float>(val)); },
        nullptr,
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%.0f Hz", v); return std::string(buf); },
        nullptr
    });
    p.push_back({
        8, "MF2 Gain", "MF2 Band", -15.0, 15.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setMf2Gain(static_cast<float>(val)); },
        nullptr,
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%+.1f dB", v); return std::string(buf); },
        nullptr
    });
    p.push_back({
        9, "MF2 Q Mode", "MF2 Band", 0.0, 1.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setMf2Narrow(val >= 0.5); },
        nullptr,
        [](double v) { return v >= 0.5 ? "Narrow (2.5)" : "Wide (0.8)"; },
        nullptr
    });
    p.push_back({
        10, "HF Frequency", "HF Band", 2000.0, 18000.0, 10000.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setHfFreq(static_cast<float>(val)); },
        nullptr,
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%.0f Hz", v); return std::string(buf); },
        nullptr
    });
    p.push_back({
        11, "HF Gain", "HF Band", -15.0, 15.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setHfGain(static_cast<float>(val)); },
        nullptr,
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%+.1f dB", v); return std::string(buf); },
        nullptr
    });
    p.push_back({
        12, "HF Bell / Shelf", "HF Band", 0.0, 1.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setHfBell(val >= 0.5); },
        nullptr,
        [](double v) { return v >= 0.5 ? "Bell" : "Shelf"; },
        nullptr
    });
    p.push_back({
        13, "Bypass", "Master", 0.0, 1.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED | CLAP_PARAM_IS_BYPASS,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m522b::M522BPluginProcessor*>(f)->setBypass(val >= 0.5); },
        nullptr,
        [](double v) { return v >= 0.5 ? "Bypassed" : "Active"; },
        nullptr
    });
    return p;
}

// --- instance ---
        case 4:
            inst = new ClapPluginInstance(
                &s_desc_m522b, host,
                []() { return std::make_unique<m522b::M522BPluginProcessor>(); },
                buildM522BParams(),
                4
            );
            break;

