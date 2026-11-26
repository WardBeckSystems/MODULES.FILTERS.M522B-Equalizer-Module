#pragma once
#include "PluginProcessor.hpp"

namespace wbs::m522b {

class M522BPluginEditor {
public:
    explicit M522BPluginEditor(M522BPluginProcessor& processor)
        : processor_(processor) {}

    void paint() const noexcept;
    void resized() noexcept;

    int getWidth() const noexcept { return 320; }
    int getHeight() const noexcept { return 680; }

private:
    M522BPluginProcessor& processor_;
};

} // namespace wbs::m522b
