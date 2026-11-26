// M522B: its block of 2030.env/vst/core/CircuitDiagramDefinitions.hpp.

        case 4: // M522B ST Broadcast EQ
            d.modelCode = "M522B";
            d.circuitTitle = "Ward-Beck M522B ST-Series High-Headroom Console EQ";
            d.theoreticalExplanation =
                "ST-Series high-headroom broadcast equalizer (+28 dBu output capability). Cascaded 18 dB/oct Butterworth high-pass cutoff "
                "filter precedes four precision swept EQ bands with dual-Q switching, driving high-speed discrete Bi-FET op-amps.";
            d.nodes = {
                { "IN",   "Bi-FET In",   "High-Z Buffer",  { 15, 20, 85, 48 }, true, Palette::CircuitBorder },
                { "HPF",  "18dB/o HPF",  "Butterworth",    { 110, 20, 95, 48 }, true, Palette::CircuitBorder },
                { "LF",   "LF Band",     "40-500Hz",       { 215, 12, 90, 36 }, true, Palette::TextGold },
                { "MF1",  "MF1 Swept",   "150-2500Hz",     { 215, 52, 90, 36 }, true, Palette::TextGold },
                { "MF2",  "MF2 Swept",   "1k-14kHz",       { 315, 12, 90, 36 }, true, Palette::TextGold },
                { "HF",   "HF Band",     "2k-18kHz",       { 315, 52, 90, 36 }, true, Palette::TextGold },
                { "OUT",  "Bi-FET Out",  "+28 dBu Line",   { 420, 20, 110, 48 }, true, Palette::LedGreen }
            };
            d.wires = {
                { "IN", "HPF", "" },
                { "HPF", "LF", "" },
                { "HPF", "MF1", "" },
                { "LF", "MF2", "" },
                { "MF1", "HF", "" },
                { "MF2", "OUT", "Summed" },
                { "HF", "OUT", "" }
            };
            break;
