#pragma once

#include "kat/engine.hpp"

#include <string>
#include <variant>

#pragma once

#include <optional>

#include <string>
#include <string_view>

#include "kat/math.hpp"

namespace kat {

    struct window_settings {
        glm::uvec2  size      = { 800, 600 };
        std::string title     = "Window";
        bool        resizable = false;
    };

    struct window_frame_size {
        int left;
        int right;
        int bottom;
        int top;
    };

    struct window_icon {
        std::vector<GLFWimage> images;
    };

    enum class client_api : int { none = GLFW_NO_API, opengl = GLFW_OPENGL_API, opengl_es = GLFW_OPENGL_ES_API };

    enum class context_creation_api : int {
        native  = GLFW_NATIVE_CONTEXT_API,
        egl     = GLFW_EGL_CONTEXT_API,
        os_mesa = GLFW_OSMESA_CONTEXT_API,
    };

    enum class opengl_profile : int {
        any           = GLFW_OPENGL_ANY_PROFILE,
        core          = GLFW_OPENGL_CORE_PROFILE,
        compatibility = GLFW_OPENGL_COMPAT_PROFILE,
    };

    enum class context_release_behavior : int {
        any   = GLFW_ANY_RELEASE_BEHAVIOR,
        flush = GLFW_RELEASE_BEHAVIOR_FLUSH,
        none  = GLFW_RELEASE_BEHAVIOR_NONE,
    };

    enum class context_robustness : int {
        none                  = GLFW_NO_ROBUSTNESS,
        lose_on_reset         = GLFW_LOSE_CONTEXT_ON_RESET,
        no_reset_notification = GLFW_NO_RESET_NOTIFICATION
    };

    enum class key : int {
        unknown         = GLFW_KEY_UNKNOWN,
        space           = GLFW_KEY_SPACE,
        apostrophe      = GLFW_KEY_APOSTROPHE,
        comma           = GLFW_KEY_COMMA,
        minus           = GLFW_KEY_MINUS,
        period          = GLFW_KEY_PERIOD,
        slash           = GLFW_KEY_SLASH,
        num_0           = GLFW_KEY_0,
        num_1           = GLFW_KEY_1,
        num_2           = GLFW_KEY_2,
        num_3           = GLFW_KEY_3,
        num_4           = GLFW_KEY_4,
        num_5           = GLFW_KEY_5,
        num_6           = GLFW_KEY_6,
        num_7           = GLFW_KEY_7,
        num_8           = GLFW_KEY_8,
        num_9           = GLFW_KEY_9,
        semicolon       = GLFW_KEY_SEMICOLON,
        equal           = GLFW_KEY_EQUAL,
        a               = GLFW_KEY_A,
        b               = GLFW_KEY_B,
        c               = GLFW_KEY_C,
        d               = GLFW_KEY_D,
        e               = GLFW_KEY_E,
        f               = GLFW_KEY_F,
        g               = GLFW_KEY_G,
        h               = GLFW_KEY_H,
        i               = GLFW_KEY_I,
        j               = GLFW_KEY_J,
        k               = GLFW_KEY_K,
        l               = GLFW_KEY_L,
        m               = GLFW_KEY_M,
        n               = GLFW_KEY_N,
        o               = GLFW_KEY_O,
        p               = GLFW_KEY_P,
        q               = GLFW_KEY_Q,
        r               = GLFW_KEY_R,
        s               = GLFW_KEY_S,
        t               = GLFW_KEY_T,
        u               = GLFW_KEY_U,
        v               = GLFW_KEY_V,
        w               = GLFW_KEY_W,
        x               = GLFW_KEY_X,
        y               = GLFW_KEY_Y,
        z               = GLFW_KEY_Z,
        left_bracket    = GLFW_KEY_LEFT_BRACKET,
        backslash       = GLFW_KEY_BACKSLASH,
        right_bracket   = GLFW_KEY_RIGHT_BRACKET,
        grave           = GLFW_KEY_GRAVE_ACCENT,
        world_1         = GLFW_KEY_WORLD_1,
        world_2         = GLFW_KEY_WORLD_2,
        escape          = GLFW_KEY_ESCAPE,
        enter           = GLFW_KEY_ENTER,
        tab             = GLFW_KEY_TAB,
        backspace       = GLFW_KEY_BACKSPACE,
        insert          = GLFW_KEY_INSERT,
        del             = GLFW_KEY_DELETE,
        right           = GLFW_KEY_RIGHT,
        left            = GLFW_KEY_LEFT,
        down            = GLFW_KEY_DOWN,
        up              = GLFW_KEY_UP,
        page_up         = GLFW_KEY_PAGE_UP,
        page_down       = GLFW_KEY_PAGE_DOWN,
        home            = GLFW_KEY_HOME,
        end             = GLFW_KEY_END,
        caps_lock       = GLFW_KEY_CAPS_LOCK,
        num_lock        = GLFW_KEY_NUM_LOCK,
        print_screen    = GLFW_KEY_PRINT_SCREEN,
        pause           = GLFW_KEY_PAUSE,
        f1              = GLFW_KEY_F1,
        f2              = GLFW_KEY_F2,
        f3              = GLFW_KEY_F3,
        f4              = GLFW_KEY_F4,
        f5              = GLFW_KEY_F5,
        f6              = GLFW_KEY_F6,
        f7              = GLFW_KEY_F7,
        f8              = GLFW_KEY_F8,
        f9              = GLFW_KEY_F9,
        f10             = GLFW_KEY_F10,
        f11             = GLFW_KEY_F11,
        f12             = GLFW_KEY_F12,
        f13             = GLFW_KEY_F13,
        f14             = GLFW_KEY_F14,
        f15             = GLFW_KEY_F15,
        f16             = GLFW_KEY_F16,
        f17             = GLFW_KEY_F17,
        f18             = GLFW_KEY_F18,
        f19             = GLFW_KEY_F19,
        f20             = GLFW_KEY_F20,
        f21             = GLFW_KEY_F21,
        f22             = GLFW_KEY_F22,
        f23             = GLFW_KEY_F23,
        f24             = GLFW_KEY_F24,
        f25             = GLFW_KEY_F25,
        keypad_0        = GLFW_KEY_KP_0,
        keypad_1        = GLFW_KEY_KP_1,
        keypad_2        = GLFW_KEY_KP_2,
        keypad_3        = GLFW_KEY_KP_3,
        keypad_4        = GLFW_KEY_KP_4,
        keypad_5        = GLFW_KEY_KP_5,
        keypad_6        = GLFW_KEY_KP_6,
        keypad_7        = GLFW_KEY_KP_7,
        keypad_8        = GLFW_KEY_KP_8,
        keypad_9        = GLFW_KEY_KP_9,
        keypad_decimal  = GLFW_KEY_KP_DECIMAL,
        keypad_divide   = GLFW_KEY_KP_DIVIDE,
        keypad_multiply = GLFW_KEY_KP_MULTIPLY,
        keypad_subtract = GLFW_KEY_KP_SUBTRACT,
        keypad_add      = GLFW_KEY_KP_ADD,
        keypad_enter    = GLFW_KEY_KP_ENTER,
        keypad_equal    = GLFW_KEY_KP_EQUAL,
        left_shift      = GLFW_KEY_LEFT_SHIFT,
        left_control    = GLFW_KEY_LEFT_CONTROL,
        left_alt        = GLFW_KEY_LEFT_ALT,
        left_super      = GLFW_KEY_LEFT_SUPER,
        right_shift     = GLFW_KEY_RIGHT_SHIFT,
        right_control   = GLFW_KEY_RIGHT_CONTROL,
        right_alt       = GLFW_KEY_RIGHT_ALT,
        right_super     = GLFW_KEY_RIGHT_SUPER,
        menu            = GLFW_KEY_MENU,
    };

    typedef int key_mods;

    enum class key_mod_bits : key_mods {
        shift     = GLFW_MOD_SHIFT,
        control   = GLFW_MOD_CONTROL,
        alt       = GLFW_MOD_ALT,
        super     = GLFW_MOD_SUPER,
        caps_lock = GLFW_MOD_CAPS_LOCK,
        num_lock  = GLFW_MOD_NUM_LOCK,
    };


    constexpr key_mods operator|(key_mod_bits a, key_mod_bits b) {
        return static_cast<key_mods>(a) | static_cast<key_mods>(b);
    }

    constexpr key_mods operator|(key_mod_bits a, key_mods b) { return static_cast<key_mods>(a) | b; }

    constexpr key_mods operator|(key_mods a, key_mod_bits b) { return a | static_cast<key_mods>(b); }

    constexpr key_mods operator&(key_mods a, key_mod_bits b) { return a & static_cast<key_mods>(b); }


    enum class window_attrib : int {
        focused                  = GLFW_FOCUSED,
        iconified                = GLFW_ICONIFIED,
        resizable                = GLFW_RESIZABLE,
        visible                  = GLFW_VISIBLE,
        decorated                = GLFW_DECORATED,
        floating                 = GLFW_FLOATING,
        maximized                = GLFW_MAXIMIZED,
        transparent_framebuffer  = GLFW_TRANSPARENT_FRAMEBUFFER,
        hovered                  = GLFW_HOVERED,
        auto_iconify             = GLFW_AUTO_ICONIFY,
        focus_on_show            = GLFW_FOCUS_ON_SHOW,
        client_api               = GLFW_CLIENT_API,
        context_version_major    = GLFW_CONTEXT_VERSION_MAJOR,
        context_version_minor    = GLFW_CONTEXT_VERSION_MINOR,
        context_revision         = GLFW_CONTEXT_REVISION,
        context_robustness       = GLFW_CONTEXT_ROBUSTNESS,
        opengl_forward_compat    = GLFW_OPENGL_FORWARD_COMPAT,
        opengl_debug_context     = GLFW_OPENGL_DEBUG_CONTEXT,
        opengl_profile           = GLFW_OPENGL_PROFILE,
        context_release_behavior = GLFW_CONTEXT_RELEASE_BEHAVIOR,
        context_no_error         = GLFW_CONTEXT_NO_ERROR,
        context_creation_api     = GLFW_CONTEXT_CREATION_API,
    };

    enum class input_mode : int {
        cursor               = GLFW_CURSOR,
        sticky_keys          = GLFW_STICKY_KEYS,
        sticky_mouse_buttons = GLFW_STICKY_MOUSE_BUTTONS,
        lock_key_mods        = GLFW_LOCK_KEY_MODS,
        raw_mouse_motion     = GLFW_RAW_MOUSE_MOTION,
    };

    enum class standard_cursor_shape : int {
        arrow     = GLFW_ARROW_CURSOR,
        i_beam    = GLFW_IBEAM_CURSOR,
        crosshair = GLFW_CROSSHAIR_CURSOR,
        hand      = GLFW_HAND_CURSOR,
        h_resize  = GLFW_HRESIZE_CURSOR,
        v_resize  = GLFW_VRESIZE_CURSOR,
    };

    enum class cursor_mode : int {
        normal   = GLFW_CURSOR_NORMAL,
        hidden   = GLFW_CURSOR_HIDDEN,
        disabled = GLFW_CURSOR_DISABLED,
    };

    enum class gamepad_button : int {
        a            = GLFW_GAMEPAD_BUTTON_A,
        b            = GLFW_GAMEPAD_BUTTON_B,
        x            = GLFW_GAMEPAD_BUTTON_X,
        y            = GLFW_GAMEPAD_BUTTON_Y,
        left_bumper  = GLFW_GAMEPAD_BUTTON_LEFT_BUMPER,
        right_bumper = GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER,
        back         = GLFW_GAMEPAD_BUTTON_BACK,
        start        = GLFW_GAMEPAD_BUTTON_START,
        guide        = GLFW_GAMEPAD_BUTTON_GUIDE,
        left_thumb   = GLFW_GAMEPAD_BUTTON_LEFT_THUMB,
        right_thumb  = GLFW_GAMEPAD_BUTTON_RIGHT_THUMB,
        dpad_up      = GLFW_GAMEPAD_BUTTON_DPAD_UP,
        dpad_right   = GLFW_GAMEPAD_BUTTON_DPAD_RIGHT,
        dpad_down    = GLFW_GAMEPAD_BUTTON_DPAD_DOWN,
        dpad_left    = GLFW_GAMEPAD_BUTTON_DPAD_LEFT,
        cross        = GLFW_GAMEPAD_BUTTON_CROSS,
        circle       = GLFW_GAMEPAD_BUTTON_CIRCLE,
        square       = GLFW_GAMEPAD_BUTTON_SQUARE,
        triangle     = GLFW_GAMEPAD_BUTTON_TRIANGLE,
    };

    enum class gamepad_axis : int {
        left_x        = GLFW_GAMEPAD_AXIS_LEFT_X,
        left_y        = GLFW_GAMEPAD_AXIS_LEFT_Y,
        right_x       = GLFW_GAMEPAD_AXIS_RIGHT_X,
        right_y       = GLFW_GAMEPAD_AXIS_RIGHT_Y,
        left_trigger  = GLFW_GAMEPAD_AXIS_LEFT_TRIGGER,
        right_trigger = GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER,
    };

    enum class joystick_hat_state : unsigned char {
        centered   = GLFW_HAT_CENTERED,
        up         = GLFW_HAT_UP,
        right      = GLFW_HAT_RIGHT,
        down       = GLFW_HAT_DOWN,
        left       = GLFW_HAT_LEFT,
        right_up   = GLFW_HAT_RIGHT_UP,
        right_down = GLFW_HAT_RIGHT_DOWN,
        left_up    = GLFW_HAT_LEFT_UP,
        left_down  = GLFW_HAT_LEFT_DOWN,
    };

    class cursor {
    public:
                 cursor(const GLFWimage &image, const glm::ivec2 &hotspot);
        explicit cursor(standard_cursor_shape shape);

        [[nodiscard]] GLFWcursor *get_handle() const noexcept;

    private:
        GLFWcursor *m_handle;
    };

    class window {
    public:
        ~window();

        [[nodiscard]] bool                     is_open() const;
        [[nodiscard]] glm::uvec2               get_framebuffer_size() const;
        [[nodiscard]] glm::uvec2               get_size() const;
        [[nodiscard]] window_frame_size        get_frame_size() const;
        [[nodiscard]] glm::ivec2               get_position() const;
        [[nodiscard]] glm::vec2                get_content_scale() const;
        [[nodiscard]] GLFWwindow              *get_handle() const noexcept;
        [[nodiscard]] float                    get_opacity() const;
        [[nodiscard]] GLFWmonitor             *get_monitor() const;
        [[nodiscard]] int                      get_attrib(window_attrib attrib) const;
        [[nodiscard]] bool                     is_focused() const;
        [[nodiscard]] bool                     is_iconified() const;
        [[nodiscard]] bool                     is_maximized() const;
        [[nodiscard]] bool                     is_hovered() const;
        [[nodiscard]] bool                     is_visible() const;
        [[nodiscard]] bool                     is_resizable() const;
        [[nodiscard]] bool                     is_decorated() const;
        [[nodiscard]] bool                     is_auto_iconify() const;
        [[nodiscard]] bool                     is_floating() const;
        [[nodiscard]] bool                     is_transparent_framebuffer() const;
        [[nodiscard]] bool                     is_focus_on_show() const;
        [[nodiscard]] client_api               get_client_api() const;
        [[nodiscard]] context_creation_api     get_context_creation_api() const;
        [[nodiscard]] int                      get_context_version_major() const;
        [[nodiscard]] int                      get_context_version_minor() const;
        [[nodiscard]] int                      get_context_version_revision() const;
        [[nodiscard]] bool                     is_opengl_forward_compat() const;
        [[nodiscard]] bool                     is_opengl_debug_context() const;
        [[nodiscard]] opengl_profile           get_opengl_profile() const;
        [[nodiscard]] context_release_behavior get_context_release_behavior() const;
        [[nodiscard]] bool                     is_context_no_error() const;
        [[nodiscard]] context_robustness       get_context_robustness() const;
        [[nodiscard]] int                      get_input_mode(input_mode mode) const;
        [[nodiscard]] glm::dvec2               get_cursor_position() const;
        [[nodiscard]] bool                     get_key(key key) const;
        [[nodiscard]] bool                     get_mouse_button(int button) const;
        [[nodiscard]] std::string              get_clipboard_string() const;
        [[nodiscard]] cursor_mode              get_cursor_mode() const;
        [[nodiscard]] bool                     is_sticky_keys() const;
        [[nodiscard]] bool                     is_sticky_mouse_buttons() const;
        [[nodiscard]] bool                     is_lock_key_mods() const;
        [[nodiscard]] bool                     is_raw_mouse_motion() const;


        void close() const;
        void set_should_close(bool should_close) const;
        void set_position(const glm::ivec2 &pos) const;
        void set_title(std::string_view title) const;
        void set_icon(const window_icon &icon) const;
        void set_size_limits(const glm::uvec2 &min, const glm::uvec2 &max) const;
        void set_aspect_ratio(unsigned int numer, unsigned int denom) const;
        void set_size(const glm::uvec2 &size) const;
        void set_opacity(float opacity) const;
        void iconify() const;
        void restore() const;
        void maximize() const;
        void show() const;
        void hide() const;
        void focus() const;
        void request_attention() const;
        void set_monitor(GLFWmonitor *monitor, const glm::ivec2 &pos, const glm::uvec2 &size, int refresh_rate) const;
        void set_attrib(window_attrib attrib, int value) const;
        void set_decorated(bool decorated) const;
        void set_resizable(bool resizable) const;
        void set_floating(bool floating) const;
        void set_auto_iconify(bool auto_iconify) const;
        void set_focus_on_show(bool focus_on_show) const;
        void swap_buffers() const;
        void set_input_mode(input_mode mode, int value) const;
        void set_cursor_pos(const glm::dvec2 &pos) const;
        void set_cursor(const cursor *cursor) const;
        void set_cursor(const std::shared_ptr<cursor> &cursor) const;
        void set_cursor(const std::unique_ptr<cursor> &cursor) const;
        void set_clipboard_string(std::string_view str) const;
        void set_cursor_mode(cursor_mode mode) const;
        void set_sticky_keys(bool sticky_keys) const;
        void set_sticky_mouse_buttons(bool sticky_mouse_buttons) const;
        void set_lock_key_mods(bool lock_key_mods) const;
        void set_raw_mouse_motion(bool raw_mouse_motion) const;

        vk::SurfaceKHR create_window_surface(vk::Instance instance) const;

        static std::shared_ptr<window> create(const window_settings &settings = {});

    private:
        explicit window(const window_settings &settings = {});

        GLFWwindow *m_handle;
    };

    void                      poll_events();
    void                      wait_events();
    void                      wait_events(double timeout);
    void                      post_empty_event();
    bool                      is_raw_mouse_motion_supported();
    int                       get_key_scancode(key key);
    std::string               get_key_name(key key);
    std::string               get_scancode_name(int scancode);
    double                    get_time();
    void                      set_time(double time);
    uint64_t                  get_timer_value();
    uint64_t                  get_timer_frequency();
    bool                      is_vulkan_supported();
    std::vector<const char *> get_required_instance_extensions();
    bool get_physical_device_presentation_support(vk::Instance instance, vk::PhysicalDevice physical_device,
                                                  uint32_t queue_family);

    struct gamepad_state {
        [[nodiscard]] bool  get_button(gamepad_button button) const;
        [[nodiscard]] float get_axis(gamepad_axis axis) const;

        GLFWgamepadstate state;
    };

    class joystick {
    public:
        explicit joystick(int jid);

        [[nodiscard]] bool                            is_present() const;
        [[nodiscard]] std::vector<float>              get_axes() const;
        [[nodiscard]] std::vector<unsigned char>      get_buttons() const;
        [[nodiscard]] std::vector<joystick_hat_state> get_hats() const;
        [[nodiscard]] std::string                     get_name() const;
        [[nodiscard]] std::string                     get_guid() const;
        [[nodiscard]] bool                            is_gamepad() const;
        [[nodiscard]] gamepad_state                   get_gamepad_state() const;

    private:
        int m_jid;
    };

    class monitor {
    public:
        explicit monitor(GLFWmonitor *monitor);


        [[nodiscard]] GLFWmonitor             *get_handle() const noexcept;
        [[nodiscard]] glm::ivec2               get_pos() const;
        [[nodiscard]] rect<int>                get_workarea() const;
        [[nodiscard]] glm::ivec2               get_physical_size() const;
        [[nodiscard]] glm::vec2                get_content_scale() const;
        [[nodiscard]] std::string              get_name() const;
        [[nodiscard]] std::vector<GLFWvidmode> get_video_modes() const;
        [[nodiscard]] GLFWvidmode              get_video_mode() const;
        [[nodiscard]] const GLFWgammaramp     *get_gamma_ramp() const;

        void set_gamma(float gamma) const;
        void set_gamma_ramp(const GLFWgammaramp *ramp) const;

        static monitor                get_primary();
        static std::vector<monitor>   get_all();
        static monitor                get(size_t index, size_t fallback = 0);
        static std::optional<monitor> try_get(size_t index);
        static monitor                get_last();

    private:
        GLFWmonitor *m_handle;
    };


} // namespace kat
