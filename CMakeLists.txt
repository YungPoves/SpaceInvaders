cmake_minimum_required(VERSION 3.15...4.0)

project(SpaceInvaders VERSION 1.0 LANGUAGES C CXX)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(app main.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenGL REQUIRED)

find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

set(LIBS ${GLFW3_LIBRARY} ${OPENGL_LIBRARY} GLEW)

include_directories(
	"${CMAKE_SOURCE_DIR}/src"
	"${CMAKE_SOURCE_DIR}/include"
	"${CMAKE_SOURCE_DIR}/include/glew"
)

target_link_libraries(app ${LIBS})

#target_link_libraries(app PRIVATE glfw)
#target_link_libraries(app PRIVATE GLEW)
#target_link_libraries(app PRIVATE GL)

target_compile_features(app PRIVATE cxx_std_11)

