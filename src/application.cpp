#include <application.hpp>

#define GLFW_EXPOSE_NATIVE_X11
#include <GLFW/glfw3native.h>

void dg::application::onEvent(dg::event &e) {
    dg::eventDispatcher dispatcher(e);

    dispatcher.Dispatch<dg::windowCloseEvent>(BIND_EVENT_FN(application::onEventClose));
    //DG_CORE_TRACE("{0}",e.toString());
    for (auto it = _layerStack.end(); it != _layerStack.begin();) {
        if (e.handled)
            break;
        (*--it)->onEvent(e);
    }
}

void dg::application::run() {
    //GLFWwindow yolo = glfwGetX11Window(&yolo);

    while (isRunning) {
        if (input::istKeyPress(DG_KEY_A) == true)
            DG_TRACE("a press");
        if (input::whileKeyPress(DG_KEY_Q) == true)
            DG_CORE_TRACE("q press");

        //tmp test hangement de lib
        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (layer *layer: _layerStack) {
            layer->onUpdate();
        }
        _win.get()->onUpdate();
    }
};

bool dg::application::onEventClose(dg::windowCloseEvent &e) {
    (void)e;
    isRunning = false;
    return true;
}

void dg::application::pushLayer(dg::layer *layer) {
    _layerStack.pushLayer(layer);
    layer->onAttach();
}

void dg::application::pushOverlay(dg::layer *overlay) {
    _layerStack.pushOverlay(overlay);
    overlay->onAttach();
}