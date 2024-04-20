#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "lve_window.h"
#include<string>
using namespace std;

namespace lve {
    LveWindow::LveWindow(int w, int h, string name) :width{ w }, height{ h }, windowName{ name } {
        initWindow();
    }

    LveWindow::~LveWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();

    }

    void LveWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);

    }
}