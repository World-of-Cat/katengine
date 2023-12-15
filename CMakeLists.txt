cmake_minimum_required(VERSION 3.26)

project(katengine VERSION 0.0.1)

find_package(Git QUIET)

# update submodules. makes sure dependencies are present
if (GIT_FOUND)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif ()

find_package(Vulkan)
if (NOT VULKAN_FOUND)
    message(FATAL_ERROR "Failed to locate Vulkan SDK. Make sure you have installed it (can be found at https://vulkan.lunarg.com/sdk/home).")
endif ()

add_subdirectory(libs)

set(KATENGINE_ENABLE_DEBUGGING "DebugOnly" CACHE STRING "Enable building some debug features")
set_property(CACHE KATENGINE_ENABLE_DEBUGGING PROPERTY STRINGS ON OFF DebugOnly)

if (KATENGINE_ENABLE_DEBUGGING STREQUAL "DebugOnly")
    set(KATENGINE_DEBUG $<IF:$<CONFIG:Release>,TRUE,FALSE>)
else ()
    set(KATENGINE_DEBUG ${KATENGINE_ENABLE_DEBUGGING})
endif ()


add_library(katengine src/kat/engine.cpp src/kat/engine.hpp
        examples/src/main.cpp
        examples/src/main.hpp
        src/kat/forward.hpp
        src/kat/window.cpp
        src/kat/window.hpp
        src/kat/math.cpp
        src/kat/math.hpp
        src/kat/platform/platform.cpp
        src/kat/platform/platform.hpp
        src/kat/platform/windows.cpp
        src/kat/platform/windows.hpp
        src/kat/enums.hpp
        src/kat/structs.hpp
        src/kat/color.hpp)

configure_file(config.hpp.in generated_includes/kat/config.hpp @ONLY)
target_include_directories(katengine PUBLIC src/ "${CMAKE_CURRENT_BINARY_DIR}/generated_includes/")
target_link_libraries(katengine PUBLIC glm::glm glfw Vulkan::Vulkan spdlog::spdlog EnTT::EnTT stb::stb)
target_compile_features(katengine PUBLIC cxx_std_20)

if (WIN32)
    target_link_libraries(katengine PUBLIC Dwmapi.lib)
endif ()

add_library(katengine::katengine ALIAS katengine)


option(KATENGINE_BUILD_EXAMPLES OFF)
if (KATENGINE_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif ()