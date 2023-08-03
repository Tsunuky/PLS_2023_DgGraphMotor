#include <glad/glad.hpp>
#include <GLFW/glfw3.h>

#include <renderer/openGLContext.hpp>

namespace dg {

OpenGLContext::OpenGLContext(GLFWwindow* window): _windowHandler(window) {
    DG_CORE_ASSERT(_windowHandler, "window hanfler is null");
};

void OpenGLContext::init() {
    glfwMakeContextCurrent(_windowHandler);
    DG_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Error initialisation of glad");

    DG_CORE_INFO("Opengl Info:");
    DG_CORE_INFO("\tVendor: {0}", (char *)glGetString(GL_VENDOR));
    DG_CORE_INFO("\tRenderer: {0}", (char *)glGetString(GL_RENDERER));
    DG_CORE_INFO("\tVersion: {0}", (char *)glGetString(GL_VERSION));

}

void OpenGLContext::swaBuffer() {
    glfwSwapBuffers(_windowHandler);
}

}