#include "main.hpp"
#include <kat/window.hpp>


#include "kat/platform/platform.hpp"
#include "kat/platform/windows.hpp"


int main() {
    glfwInit();

    kat::platform::init<kat::windows_platform>();

    auto window = kat::window::create(kat::window_settings{ { 800, 800 }, "Test" });

    while (window->is_open()) {
        glfwPollEvents();
    }

    return 0;
}
