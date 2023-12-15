#include "window.hpp"


#include "platform/platform.hpp"


namespace kat {

    cursor::cursor(const GLFWimage &image, const glm::ivec2 &hotspot) {
        m_handle = glfwCreateCursor(&image, hotspot.x, hotspot.y);
    }

    cursor::cursor(standard_cursor_shape shape) {
        m_handle = glfwCreateStandardCursor(static_cast<int>(shape));
    }

    GLFWcursor *cursor::get_handle() const noexcept {
        return m_handle;
    }

    window::~window() {
        glfwDestroyWindow(m_handle);
    }

    bool window::is_open() const {
        return !glfwWindowShouldClose(m_handle);
    }

    glm::uvec2 window::get_framebuffer_size() const {
        int x, y;
        glfwGetFramebufferSize(m_handle, &x, &y);
        return { x, y };
    }

    glm::uvec2 window::get_size() const {
        int x, y;
        glfwGetWindowSize(m_handle, &x, &y);
        return { x, y };
    }

    window_frame_size window::get_frame_size() const {
        window_frame_size v{};
        glfwGetWindowFrameSize(m_handle, &v.left, &v.top, &v.right, &v.bottom);
        return v;
    }

    glm::ivec2 window::get_position() const {
        glm::ivec2 v;
        glfwGetWindowPos(m_handle, &v.x, &v.y);
        return v;
    }

    glm::vec2 window::get_content_scale() const {
        glm::vec2 v;
        glfwGetWindowContentScale(m_handle, &v.x, &v.y);
        return v;
    }

    GLFWwindow *window::get_handle() const noexcept {
        return m_handle;
    }

    float window::get_opacity() const {
        return glfwGetWindowOpacity(m_handle);
    }

    GLFWmonitor *window::get_monitor() const {
        return glfwGetWindowMonitor(m_handle);
    }

    int window::get_attrib(window_attrib attrib) const {
        return glfwGetWindowAttrib(m_handle, static_cast<int>(attrib));
    }

    bool window::is_focused() const {
        return get_attrib(window_attrib::focused);
    }

    bool window::is_iconified() const {
        return get_attrib(window_attrib::iconified);
    }

    bool window::is_maximized() const {
        return get_attrib(window_attrib::maximized);
    }

    bool window::is_hovered() const {
        return get_attrib(window_attrib::hovered);
    }

    bool window::is_visible() const {
        return get_attrib(window_attrib::visible);
    }

    bool window::is_resizable() const {
        return get_attrib(window_attrib::resizable);
    }

    bool window::is_decorated() const {
        return get_attrib(window_attrib::decorated);
    }

    bool window::is_auto_iconify() const {
        return get_attrib(window_attrib::auto_iconify);
    }

    bool window::is_floating() const {
        return get_attrib(window_attrib::floating);
    }

    bool window::is_transparent_framebuffer() const {
        return get_attrib(window_attrib::transparent_framebuffer);
    }

    bool window::is_focus_on_show() const {
        return get_attrib(window_attrib::focus_on_show);
    }

    client_api window::get_client_api() const {
        return static_cast<client_api>(get_attrib(window_attrib::client_api));
    }

    context_creation_api window::get_context_creation_api() const {
        return static_cast<context_creation_api>(get_attrib(window_attrib::context_creation_api));
    }

    int window::get_context_version_major() const {
        return get_attrib(window_attrib::context_version_major);
    }

    int window::get_context_version_minor() const {
        return get_attrib(window_attrib::context_version_minor);
    }

    int window::get_context_version_revision() const {
        return get_attrib(window_attrib::context_revision);
    }

    bool window::is_opengl_forward_compat() const {
        return get_attrib(window_attrib::opengl_forward_compat);
    }

    bool window::is_opengl_debug_context() const {
        return get_attrib(window_attrib::opengl_debug_context);
    }

    opengl_profile window::get_opengl_profile() const {
        return static_cast<opengl_profile>(get_attrib(window_attrib::opengl_profile));
    }

    context_release_behavior window::get_context_release_behavior() const {
        return static_cast<context_release_behavior>(get_attrib(window_attrib::context_release_behavior));
    }

    bool window::is_context_no_error() const {
        return get_attrib(window_attrib::context_no_error);
    }

    context_robustness window::get_context_robustness() const {
        return static_cast<context_robustness>(get_attrib(window_attrib::context_robustness));
    }

    int window::get_input_mode(input_mode mode) const {
        return glfwGetInputMode(m_handle, static_cast<int>(mode));
    }

    glm::dvec2 window::get_cursor_position() const {
        glm::dvec2 v;
        glfwGetCursorPos(m_handle, &v.x, &v.y);
        return v;
    }

    bool window::get_key(key key) const {
        return glfwGetKey(m_handle, static_cast<int>(key));
    }

    bool window::get_mouse_button(int button) const {
        return glfwGetMouseButton(m_handle, button);
    }

    std::string window::get_clipboard_string() const {
        return glfwGetClipboardString(m_handle);
    }

    cursor_mode window::get_cursor_mode() const {
        return static_cast<cursor_mode>(get_input_mode(input_mode::cursor));
    }

    bool window::is_sticky_keys() const {
        return get_input_mode(input_mode::sticky_keys);
    }

    bool window::is_sticky_mouse_buttons() const {
        return get_input_mode(input_mode::sticky_mouse_buttons);
    }

    bool window::is_lock_key_mods() const {
        return get_input_mode(input_mode::lock_key_mods);
    }

    bool window::is_raw_mouse_motion() const {
        return get_input_mode(input_mode::raw_mouse_motion);
    }

    void window::close() const {
        set_should_close(true);
    }

    void window::set_should_close(bool should_close) const {
        glfwSetWindowShouldClose(m_handle, should_close);
    }

    void window::set_position(const glm::ivec2 &pos) const {
        glfwSetWindowPos(m_handle, pos.x, pos.y);
    }

    void window::set_title(const std::string_view title) const {
        glfwSetWindowTitle(m_handle, title.data());
    }

    void window::set_icon(const window_icon &icon) const {
        glfwSetWindowIcon(m_handle, icon.images.size(), icon.images.data());
    }

    void window::set_size_limits(const glm::uvec2 &min, const glm::uvec2 &max) const {
        glfwSetWindowSizeLimits(m_handle, min.x, min.y, max.x, max.y);
    }

    void window::set_aspect_ratio(unsigned numer, unsigned denom) const {
        glfwSetWindowAspectRatio(m_handle, numer, denom);
    }

    void window::set_size(const glm::uvec2 &size) const {
        glfwSetWindowSize(m_handle, size.x, size.y);
    }

    void window::set_opacity(float opacity) const {
        glfwSetWindowOpacity(m_handle, opacity);
    }

    void window::iconify() const {
        glfwIconifyWindow(m_handle);
    }

    void window::restore() const {
        glfwRestoreWindow(m_handle);
    }

    void window::maximize() const {
        glfwMaximizeWindow(m_handle);
    }

    void window::show() const {
        glfwShowWindow(m_handle);
    }

    void window::hide() const {
        glfwHideWindow(m_handle);
    }

    void window::focus() const {
        glfwFocusWindow(m_handle);
    }

    void window::request_attention() const {
        glfwRequestWindowAttention(m_handle);
    }

    void window::set_monitor(GLFWmonitor *monitor, const glm::ivec2 &pos, const glm::uvec2 &size,
                             int refresh_rate) const {
        glfwSetWindowMonitor(m_handle, monitor, pos.x, pos.y, size.x, size.y, refresh_rate);
    }

    void window::set_attrib(window_attrib attrib, int value) const {
        glfwSetWindowAttrib(m_handle, static_cast<int>(attrib), value);
    }

    void window::set_decorated(bool decorated) const {
        set_attrib(window_attrib::decorated, decorated);
    }

    void window::set_resizable(bool resizable) const {
        set_attrib(window_attrib::resizable, resizable);
    }

    void window::set_floating(bool floating) const {
        set_attrib(window_attrib::floating, floating);
    }

    void window::set_auto_iconify(bool auto_iconify) const {
        set_attrib(window_attrib::auto_iconify, auto_iconify);
    }

    void window::set_focus_on_show(bool focus_on_show) const {
        set_attrib(window_attrib::focus_on_show, focus_on_show);
    }

    void window::swap_buffers() const {
        glfwSwapBuffers(m_handle);
    }

    void window::set_input_mode(input_mode mode, int value) const {
        glfwSetInputMode(m_handle, static_cast<int>(mode), value);
    }

    void window::set_cursor_pos(const glm::dvec2 &pos) const {
        glfwSetCursorPos(m_handle, pos.x, pos.y);
    }

    void window::set_cursor(const cursor *cursor) const {
        glfwSetCursor(m_handle, cursor->get_handle());
    }

    void window::set_cursor(const std::shared_ptr<cursor> &cursor) const {
        set_cursor(cursor.get());
    }

    void window::set_cursor(const std::unique_ptr<cursor> &cursor) const {
        set_cursor(cursor.get());
    }

    void window::set_clipboard_string(const std::string_view str) const {
        glfwSetClipboardString(m_handle, str.data());
    }

    void window::set_cursor_mode(cursor_mode mode) const {
        set_input_mode(input_mode::cursor, static_cast<int>(mode));
    }

    void window::set_sticky_keys(bool sticky_keys) const {
        set_input_mode(input_mode::sticky_keys, true);
    }

    void window::set_sticky_mouse_buttons(bool sticky_mouse_buttons) const {
        set_input_mode(input_mode::sticky_mouse_buttons, true);
    }

    void window::set_lock_key_mods(bool lock_key_mods) const {
        set_input_mode(input_mode::lock_key_mods, true);
    }

    void window::set_raw_mouse_motion(bool raw_mouse_motion) const {
        set_input_mode(input_mode::raw_mouse_motion, true);
    }

    vk::SurfaceKHR window::create_window_surface(vk::Instance instance) const {
        VkSurfaceKHR surface;
        glfwCreateWindowSurface(instance, m_handle, nullptr, &surface);
        return surface;
    }

    std::shared_ptr<window> window::create(const window_settings &settings) {
        return std::shared_ptr<window>(new window(settings));
    }

    window::window(const window_settings &settings) {
        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_RESIZABLE, settings.resizable);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        m_handle = glfwCreateWindow(static_cast<int>(settings.size.x), static_cast<int>(settings.size.y),
                                    settings.title.c_str(), nullptr, nullptr);

        platform::get()->update_window(m_handle);
    }

    void poll_events() {
        glfwPollEvents();
    }

    void wait_events() {
        glfwWaitEvents();
    }

    void wait_events(double timeout) {
        glfwWaitEventsTimeout(timeout);
    }

    void post_empty_event() {
        glfwPostEmptyEvent();
    }

    bool is_raw_mouse_motion_supported() {
        return glfwRawMouseMotionSupported();
    }

    int get_key_scancode(key key) {
        return glfwGetKeyScancode(static_cast<int>(key));
    }

    std::string get_key_name(key key) {
        return glfwGetKeyName(static_cast<int>(key), 0);
    }

    std::string get_scancode_name(int scancode) {
        return glfwGetKeyName(GLFW_KEY_UNKNOWN, scancode);
    }

    double get_time() {
        return glfwGetTime();
    }

    void set_time(double time) {
        glfwSetTime(time);
    }

    uint64_t get_timer_value() {
        return glfwGetTimerValue();
    }

    uint64_t get_timer_frequency() {
        return glfwGetTimerFrequency();
    }

    bool is_vulkan_supported() {
        return glfwVulkanSupported();
    }

    std::vector<const char *> get_required_instance_extensions() {
        uint32_t     count;
        const char **ppnames = glfwGetRequiredInstanceExtensions(&count);

        return { ppnames, ppnames + count };
    }

    bool get_physical_device_presentation_support(vk::Instance instance, vk::PhysicalDevice physical_device,
                                                  uint32_t queue_family) {
        return glfwGetPhysicalDevicePresentationSupport(instance, physical_device, queue_family);
    }

    bool gamepad_state::get_button(gamepad_button button) const {
        return state.buttons[static_cast<int>(button)];
    }

    float gamepad_state::get_axis(gamepad_axis axis) const {
        return state.axes[static_cast<int>(axis)];
    }

    joystick::joystick(int jid) : m_jid(jid) {}

    bool joystick::is_present() const {
        return glfwJoystickPresent(m_jid);
    }

    std::vector<float> joystick::get_axes() const {
        int          count;
        const float *pv = glfwGetJoystickAxes(m_jid, &count);
        return std::vector(pv, pv + count);
    }

    std::vector<unsigned char> joystick::get_buttons() const {
        std::vector<unsigned char> buttons;
        int                        count;
        const unsigned char       *pv = glfwGetJoystickButtons(m_jid, &count);
        buttons.assign(pv, pv + count);
        return std::vector(pv, pv + count);
    }

    std::vector<joystick_hat_state> joystick::get_hats() const {
        std::vector<joystick_hat_state> hats;
        int                             count;
        const joystick_hat_state *pv = reinterpret_cast<const joystick_hat_state *>(glfwGetJoystickHats(m_jid, &count));
        return std::vector(pv, pv + count);
    }

    std::string joystick::get_name() const {
        return glfwGetJoystickName(m_jid);
    }

    std::string joystick::get_guid() const {
        return glfwGetJoystickGUID(m_jid);
    }

    bool joystick::is_gamepad() const {
        return glfwJoystickIsGamepad(m_jid);
    }

    gamepad_state joystick::get_gamepad_state() const {
        gamepad_state state{};
        glfwGetGamepadState(m_jid, &state.state);
        return state;
    }

    monitor::monitor(GLFWmonitor *monitor) : m_handle(monitor) {}

    GLFWmonitor *monitor::get_handle() const noexcept {
        return m_handle;
    }

    glm::ivec2 monitor::get_pos() const {
        glm::ivec2 v;
        glfwGetMonitorPos(m_handle, &v.x, &v.y);
        return v;
    }

    rect<int> monitor::get_workarea() const {
        rect<int> v;
        glfwGetMonitorWorkarea(m_handle, &v.position.x, &v.position.y, &v.size.x, &v.size.y);
        return v;
    }

    glm::ivec2 monitor::get_physical_size() const {
        glm::ivec2 v;
        glfwGetMonitorPhysicalSize(m_handle, &v.x, &v.y);
        return v;
    }

    glm::vec2 monitor::get_content_scale() const {
        glm::vec2 v;
        glfwGetMonitorContentScale(m_handle, &v.x, &v.y);
        return v;
    }

    std::string monitor::get_name() const {
        return glfwGetMonitorName(m_handle);
    }

    std::vector<GLFWvidmode> monitor::get_video_modes() const {
        int                count;
        const GLFWvidmode *pvms = glfwGetVideoModes(m_handle, &count);

        return std::vector(pvms, pvms + count);
    }

    GLFWvidmode monitor::get_video_mode() const {
        return *glfwGetVideoMode(m_handle);
    }

    const GLFWgammaramp *monitor::get_gamma_ramp() const {
        return glfwGetGammaRamp(m_handle);
    }

    void monitor::set_gamma(float gamma) const {
        glfwSetGamma(m_handle, gamma);
    }

    void monitor::set_gamma_ramp(const GLFWgammaramp *ramp) const {
        glfwSetGammaRamp(m_handle, ramp);
    }

    monitor monitor::get_primary() {
        return monitor(glfwGetPrimaryMonitor());
    }

    std::vector<monitor> monitor::get_all() {
        int                  count;
        std::vector<monitor> ms;
        GLFWmonitor        **ppms = glfwGetMonitors(&count);

        ms.reserve(count);
        for (int i = 0; i < count; i++) {
            ms.push_back(monitor(ppms[i]));
        }

        return ms;
    }

    monitor monitor::get(size_t index, size_t fallback) {
        return try_get(index).value_or(try_get(fallback).value_or(get_primary()));
    }

    std::optional<monitor> monitor::try_get(size_t index) {
        auto all = get_all();
        if (index < all.size())
            return all[index];
        return std::nullopt;
    }

    monitor monitor::get_last() {
        return get_all().back();
    }
} // namespace kat
