cmake_minimum_required(VERSION 3.6)
project(fractalviewer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -fno-exceptions")

add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad SYSTEM PUBLIC glad/include)

find_package(OpenGL REQUIRED)
add_library(GL INTERFACE)
target_link_libraries(GL INTERFACE ${OPENGL_gl_LIBRARY})

find_package(glfw3 3.0 REQUIRED)

add_executable(mandelbrot mandelbrot.cpp)
target_link_libraries(mandelbrot glad glfw GL)