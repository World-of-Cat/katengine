#pragma once
#include "kat/enums.hpp"

#include "kat/color.hpp"

namespace kat {
    struct system_colors {
        system_theme theme;
        color        foreground;
        color        background;
        color        accent;
        color        complement;
    };
} // namespace kat
