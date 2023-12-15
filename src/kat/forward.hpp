#pragma once

#include "kat/config.hpp"

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#ifdef UNICODE
#undef UNICODE
#endif
#include <Windows.h>

#define INCLUDE_GLFW_NATIVE
#define GLFW_EXPOSE_NATIVE_WIN32
#endif

#include <vulkan/vulkan.hpp>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>

#ifdef INCLUDE_GLFW_NATIVE
#include <GLFW/glfw3native.h>
#endif
