#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 800;

GLFWwindow* initGLFW();
bool initGLAD();
void renderLoop(GLFWwindow* window);

int main() {
    GLFWwindow* window = initGLFW();
    if (!window) return -1;

    if (!initGLAD()) return -1;

    renderLoop(window);

    glfwTerminate();
    return 0;
}

GLFWwindow* initGLFW() {
    if (!glfwInit()) {
        std::cout << "GLFW failed\n";
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Window", nullptr, nullptr);
    if (!window) {
        std::cout << "Window creation failed\n" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwSetWindowPos(window, 150, 150);
    glfwMakeContextCurrent(window);
    return window;
}

bool initGLAD() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "GLAD failed\n" << std::endl;
        return false;
    }
    return true;
}


void renderLoop(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window)) {
        glClearColor(42.0f/255, 42.0f/255, 53.0f/255, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}