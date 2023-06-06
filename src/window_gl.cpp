//#include <precompile.hpp>
#include <glad/glad.hpp>

#include <log.hpp>
#include <window_gl.hpp>

#include <eventApplication.hpp>
#include <eventInput.hpp>
#include <eventKeyboard.hpp>
#include <eventMouse.hpp>
#include <inputLinux.hpp>

static int _id = 0;

void dg::setWinPointer(int id, dg::window_GL *pointer) {
    if (id <= 0)
        DG_CORE_FATAL("Error id given in setWinOinter");
    _winUser.currentWin = pointer;
    _id = id;
}

dg::window_GL *dg::getWinPointer(int id) {
    if (id <= 0)
        DG_CORE_FATAL("Error id given in getWinPointer");
    if (_winUser.id > 0)
        if (id != _winUser.id)
            DG_CORE_FATAL("Error id concordances in getWinPointer");
    return _winUser.currentWin;
}

void dg::setWinUserPointer(int id, void *pointer) {
    if (id <= 0)
        DG_CORE_FATAL("Error id given in setWinUserPointer");
    if (_winUser.id > 0)
        if (id != _winUser.id)
            DG_CORE_FATAL("Error id concordances in setWinUserPointer");
    _winUser.data = pointer;
    _winUser.id = id;
}

void *dg::getUserWinPointer(int id) {
    if (id <= 0)
        DG_CORE_FATAL("Error id given in getWinUserPointer");
    if (_winUser.id > 0)
        if (id != _winUser.id)
            DG_CORE_FATAL("Error id concordances in getWinUserPointer");
    return _winUser.data;
}

dg::window_API *dg::window_API::create(const window &props) {
    return new dg::window_GL(props);
}

void dg::window_GL::setCallback() {
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
            dg::keyReleased event(key);
            data.eventCallback(event);
            break;
        }
        case GLFW_PRESS: {
            dg::KeyPressed event(key);
            data.eventCallback(event);
            break;
        }
        // case 2  modif possible
        case GLFW_REPEAT: {
            dg::KeyPressed event(key);
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
        (void)window;(void)codepoint;(void)mods;
        //add event
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
    DG_CORE_ASSERT(glfwInit(), "Error initialisation of glfw");
	_window = glfwCreateWindow((int)_data.width, (int)_data.height, _data.title.c_str(), nullptr, nullptr);
    DG_CORE_INFO("Creating Window '{0}' width: {1}, height: {2}", _data.title, _data.width, _data.height);
    glfwMakeContextCurrent(_window);
    DG_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Error initialisation of glad");
    glfwSetWindowUserPointer(_window, &_data);
    setVsync(true);
    setCallback();
}

void dg::window_GL::onUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(_window);
}

void dg::window_GL::setVsync(bool enable) {
    if (enable)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
    _data.sync = enable;
}

void dg::window_GL::clearColor(const dg::rgba &color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

void dg::window_GL::scalePixel(float scale) {
    glPointSize(scale);
}