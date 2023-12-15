#pragma once

#include "kat/forward.hpp"

#include "kat/enums.hpp"
#include "kat/structs.hpp"

#include <optional>

namespace kat {
    class platform {
    public:
        virtual ~platform() = default;

        inline virtual void                         update_window(GLFWwindow *window){};
        inline virtual system_theme                 get_system_theme() { return system_theme::unknown; };
        inline virtual void                         apply_theme(GLFWwindow *window, system_theme theme){};
        inline virtual std::optional<system_colors> get_system_colors() { return std::nullopt; };

        static const std::shared_ptr<platform> &get();

        template <std::derived_from<platform> T>
        inline static void init() {
            s_platform = std::make_shared<T>();
        };


    private:
        static inline std::shared_ptr<platform> s_platform;
    };
} // namespace kat
