//#include <precompile.hpp>
#include <window_gl.hpp>

#include <eventApplication.hpp>
#include <eventInput.hpp>
#include <eventKeyboard.hpp>
#include <eventMouse.hpp>
#include <inputLinux.hpp>

#include <OpenGL/OpenGLContext.hpp>

dg::window_API *dg::window_API::create(const window &props) {
    return new dg::window_GL(props);
}

void dg::window_GL::setCallbackGlfw() {
    glfwSetWindowSizeCallback(_window, [](GLFWwindow *window, int width , int height) {
        winData &data = *static_cast<winData *>(glfwGetWindowUserPointer(window));
        
        data.width = width;
        data.height = height;
        dg::windowResizEvent event(width, height);
        data.eventCallback(event);
    });
    glfwSetWindowCloseCallback(_window, [](GLFWwindow *window) {
        winData &data = *static_cast<winData *>(glfwGetWindowUserPointer(window));

        dg::windowCloseEvent event;
        data.eventCallback(event);
    });
    glfwSetWindowFocusCallback(_window, [](GLFWwindow *window, int focused) {
        winData &data = *static_cast<winData *>(glfwGetWindowUserPointer(window));
        switch (focused) {
            case GLFW_TRUE: {
                dg::windowFocus event;
                data.eventCallback(event);
                break;
            }
            case GLFW_FALSE: {
                dg::windowLostFocus event;
                data.eventCallback(event);
                break;
            }
        }
    });
    glfwSetWindowRefreshCallback(_window, [](GLFWwindow *window) {
        (void)window;
        // add le refresh event
    });
    glfwSetWindowPosCallback(_window, [](GLFWwindow *window, int xpos, int ypos) {
        winData &data = *static_cast<winData *>(glfwGetWindowUserPointer(window));

        dg::windowMoved event(xpos, ypos);
        data.eventCallback(event);
    });
    glfwSetWindowIconifyCallback(_window, [](GLFWwindow *window, int iconify) {
        (void)window; (void)iconify;
        //`GLFW_TRUE` if the window was iconified
        //`GLFW_FALSE` if it was restored.
        // add event
    });
    glfwSetWindowMaximizeCallback(_window, [](GLFWwindow *window, int maximized) {
        (void)window; (void)maximized;
        //`GLFW_TRUE` if the window was maximized
        //`GLFW_FALSE` if it was restored.
        // add event
    });
    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow *window, int width, int height) {
        (void)window; (void)width; (void)height;
        // add event
    });
    glfwSetWindowContentScaleCallback(_window, [](GLFWwindow *window, float xscale, float yscale) {
        (void)window;(void)xscale;(void)yscale;
        // add event
    });
    glfwSetKeyCallback(_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        (void)scancode;(void)mods;
        winData &data = *static_cast<winData *>(glfwGetWindowUserPointer(window));
        
        switch (action) {
        case GLFW_RELEASE: {
            dg::keyReleased event(key, scancode);
            data.eventCallback(event);
            break;
        }
        case GLFW_PRESS: {
            dg::KeyPressed event(key, scancode);
            data.eventCallback(event);
            break;
        }
        // case 2  modif possible
        case GLFW_REPEAT: {
            dg::KeyPressed event(key, scancode);
            data.eventCallback(event);
            break;
        }
        }
    });
    glfwSetCharCallback(_window, [](GLFWwindow *window, u_int codepoint) {
        (void)window;(void)codepoint;
        // add event
    });
    glfwSetCharModsCallback(_window, [](GLFWwindow *window, u_int codepoint, int mods) {
        (void)mods;
        winData &data = *static_cast<winData *>(glfwGetWindowUserPointer(window));

        dg::keyType event(codepoint);
        data.eventCallback(event);
    });
    glfwSetMouseButtonCallback(_window, [](GLFWwindow *window, int button, int action, int mods) {
        (void)mods;
        winData &data = *static_cast<winData *>(glfwGetWindowUserPointer(window));

        switch (action) {
        case GLFW_PRESS: {
            dg::mouseButtonPressed event(button);
            data.eventCallback(event);
            break;
        }
        case GLFW_RELEASE: {
            dg::mouseButtonReleased event(button);
            data.eventCallback(event);
            break;
        }
        }
    });
    glfwSetCursorPosCallback(_window, [](GLFWwindow *window, double xpose, double ypose) {
        winData &data = *static_cast<winData *>(glfwGetWindowUserPointer(window));

        dg::mouseMoved event(xpose, ypose);
        data.eventCallback(event);
    });
    glfwSetCursorEnterCallback(_window, [](GLFWwindow *window, int entered) {
        (void)window;(void)entered;
        // add event
    });
    glfwSetScrollCallback(_window, [](GLFWwindow *window, double xoffset, double yoffset) {
        winData &data = *static_cast<winData *>(glfwGetWindowUserPointer(window));

        dg::mouseScrolled event(xoffset, yoffset);
        data.eventCallback(event);
    });
    glfwSetDropCallback(_window, [](GLFWwindow *window, int pathCount, const char **paths) {
        (void)window;(void)pathCount;(void)paths;
        // path_count The number of dropped paths.
        // paths The UTF-8 encoded file and/or directory path names.
        // add event
    });
}

void dg::window_GL::initWindow() {
#ifdef _glfw3_h_
    DG_CORE_ASSERT(glfwInit(), "Error initialisation of glfw");
	_window = glfwCreateWindow((int)_data.width, (int)_data.height, _data.title.c_str(), nullptr, nullptr);
    DG_CORE_INFO("Creating Window '{0}' width: {1}, height: {2}", _data.title, _data.width, _data.height);
    glfwSetWindowUserPointer(_window, &_data);
    setCallbackGlfw();
#endif
    _context = new OpenGLContext(_window);
    _context->init();
    setVsync(true);
}

void dg::window_GL::onUpdate() {
#ifdef _glfw3_h_
    glfwPollEvents();
#endif
    _context->swapBuffer();
}

void dg::window_GL::setVsync(bool enable) {
#ifdef _glfw3_h_
    if (enable)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
#endif
    _data.sync = enable;
}