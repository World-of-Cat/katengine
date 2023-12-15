#### Include libraries which have valid CMakeLists files.

set(SPDLOG_USE_STD_FORMAT ON)

add_subdirectory(entt)
add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(spdlog)


#### stb interface library

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/stb/)
add_library(stb::stb ALIAS stb)