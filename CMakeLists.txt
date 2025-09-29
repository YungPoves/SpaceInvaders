cmake_minimum_required(VERSION 3.15...4.0)

project(SpaceInvaders VERSION 1.0 LANGUAGES C CXX)

add_executable(App main.cpp)

find_package(OpenGL REQUIRED)

target_compile_features(App PRIVATE cxx_std_11)

target_link_libraries(App PRIVATE glfw)
target_link_libraries(App PRIVATE GLEW)
target_link_libraries(App PRIVATE GL)
