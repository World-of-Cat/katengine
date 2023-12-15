#pragma once
#ifdef WIN32

#endif
#include "kat/structs.hpp"
#include "platform.hpp"

namespace kat {
    class windows_platform : public platform {
    public:
        explicit windows_platform();

        inline void                         update_window(GLFWwindow *window) override;
        inline system_theme                 get_system_theme() override;
        inline void                         apply_theme(GLFWwindow *window, system_theme theme) override;
        inline std::optional<system_colors> get_system_colors() override;

        /////////////////////////////////////
        //// platform specific functions ////
        /////////////////////////////////////

        // Many of the following functions might be static, since they often don't need platform specific data.

        static void enable_dark_mode(HWND hwnd);
        static void enable_light_mode(HWND hwnd);
        static bool is_system_dark_mode();

    private:
        HINSTANCE m_hinstance;
    };
} // namespace kat
