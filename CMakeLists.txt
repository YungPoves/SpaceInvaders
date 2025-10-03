cmake_minimum_required(VERSION 3.15...4.0)

project(SpaceInvaders VERSION 1.0 LANGUAGES C CXX)

add_executable(app main.cpp)

find_package(OpenGL REQUIRED)

target_link_libraries(app PRIVATE glfw)
target_link_libraries(app PRIVATE GLEW)
target_link_libraries(app PRIVATE GL)

target_compile_features(app PRIVATE cxx_std_11)

