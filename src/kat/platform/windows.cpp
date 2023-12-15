#ifdef WIN32
#include "windows.hpp"

#include <dwmapi.h>
#include <winrt/Windows.UI.ViewManagement.h>

#ifndef DWMWA_USE_IMMERSIVE_DARK_MODE
#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#endif

static bool is_color_light(const winrt::Windows::UI::Color &clr) {
    return (((5 * clr.G) + (2 * clr.R) + clr.B) > (8 * 128));
}

namespace kat {
    windows_platform::windows_platform() : platform() {
        m_hinstance = GetModuleHandleA(nullptr);
    }

    void windows_platform::update_window(GLFWwindow *window) {
        platform::update_window(window);

        apply_theme(window, get_system_theme());
    }

    system_theme windows_platform::get_system_theme() {
        if (is_system_dark_mode()) {
            return system_theme::dark;
        }
        return system_theme::light;
    }

    void windows_platform::enable_dark_mode(HWND hwnd) {
        constexpr BOOL value = TRUE;
        if (DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &value, sizeof(value)) == S_OK) {
            UpdateWindow(hwnd);
        }
    }

    void windows_platform::enable_light_mode(HWND hwnd) {
        constexpr BOOL value = FALSE;
        if (DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &value, sizeof(value)) == S_OK) {
            UpdateWindow(hwnd);
        }
    }

    bool windows_platform::is_system_dark_mode() {
        using namespace winrt::Windows::UI::ViewManagement;
        const auto settings = UISettings();

        const auto foreground = settings.GetColorValue(UIColorType::Foreground);

        return is_color_light(foreground);
    }

    void windows_platform::apply_theme(GLFWwindow *window, system_theme theme) {
        platform::apply_theme(window, theme);

        switch (theme) {
        case system_theme::dark:
            enable_dark_mode(glfwGetWin32Window(window));
            break;
        case system_theme::light:
            enable_light_mode(glfwGetWin32Window(window));
            break;
        default:
            break;
        }
    }

    static color color_from_winrt_color(const winrt::Windows::UI::Color &c) {
        return color::from_unorm_bytes(c.R, c.G, c.B, c.A);
    }

    std::optional<system_colors> windows_platform::get_system_colors() {
        using namespace winrt::Windows::UI::ViewManagement;
        const auto settings = UISettings();

        const auto foreground = settings.GetColorValue(UIColorType::Foreground);

        system_colors colors{};
        colors.theme      = is_color_light(foreground) ? system_theme::light : system_theme::dark;
        colors.foreground = color_from_winrt_color(foreground);
        colors.background = color_from_winrt_color(settings.GetColorValue(UIColorType::Background));
        colors.accent     = color_from_winrt_color(settings.GetColorValue(UIColorType::Accent));
        colors.complement = color_from_winrt_color(settings.GetColorValue(UIColorType::Complement));
        return colors;
    }
} // namespace kat


#endif
