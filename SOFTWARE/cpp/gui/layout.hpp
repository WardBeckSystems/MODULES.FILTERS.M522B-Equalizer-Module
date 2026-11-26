// M522B: its block of 2030.env/vst/core/ModuleGuiLayouts.hpp (176 x 770 = the faceplate).

        case 4: { // M522B ST Console EQ (176 x 770)
            m.title = "M522B Console EQ";
            m.subtitle = "Standard ST-Series Broadcast Channel Equalizer";
            m.modelCode = "M522B";

            // Top is Red
            m.knobs.push_back({ 4, "HF GAIN", "dB", 88.0f, 100.0f, 24.0f, -12.0, 12.0, 0.0, false, KnobStyle::WbsElmaWing, Palette::ElmaRed });
            // Mid is Yellow
            m.knobs.push_back({ 2, "MID FREQ", "Hz", 88.0f, 195.0f, 22.0f, 350.0, 5000.0, 1200.0, false, KnobStyle::WbsElmaPointer, Palette::ElmaYellow });
            m.knobs.push_back({ 3, "MID GAIN", "dB", 88.0f, 275.0f, 24.0f, -12.0, 12.0, 0.0, false, KnobStyle::WbsElmaWing, Palette::ElmaYellow });
            // Low is Green
            m.knobs.push_back({ 1, "LF GAIN", "dB", 88.0f, 370.0f, 24.0f, -12.0, 12.0, 0.0, false, KnobStyle::WbsElmaWing, Palette::ElmaGreen });
            m.knobs.push_back({ 0, "HPF CUT", "Hz", 88.0f, 465.0f, 22.0f, 20.0, 300.0, 20.0, false, KnobStyle::WbsElmaWing, Palette::ElmaSlate });

            // EQ In/Bypass - Red
            m.buttons.push_back({ 6, "EQ IN", { 43.0f, 550.0f, 90.0f, 28.0f }, true, ButtonStyle::LatchingPush, Palette::LedRed });

            m.themeToggleRect = { 25.0f, 726.0f, 126.0f, 22.0f };
            break;
        }
