#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>

static void update(double dt) {

}

static void draw() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main() {
    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "error: " << description << '\n';
        std::exit(1);
    });

    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Mandelbrot viewer", nullptr, nullptr);

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            if (key == GLFW_KEY_ESCAPE || (key == GLFW_KEY_W && (mods & GLFW_MOD_CONTROL))) {
                glfwSetWindowShouldClose(window, true);
            }
        }
    });

    glfwMakeContextCurrent(window);
    gladLoadGLES2Loader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    double time = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        double nextTime = glfwGetTime();
        glfwPollEvents();
        update(nextTime - time);
        time = nextTime;
        draw();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
