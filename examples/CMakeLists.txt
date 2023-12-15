
add_executable(katengine_example src/main.cpp src/main.hpp)
target_include_directories(katengine_example PRIVATE src)
target_link_libraries(katengine_example PRIVATE katengine::katengine)
target_compile_features(katengine_example PRIVATE cxx_std_20)