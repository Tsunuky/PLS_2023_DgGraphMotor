#include <application.hpp>

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

void dg::application::run(int argc, char **argv, bool lgio) {
    _win->run(&_layerStack, argc, argv, lgio);
};

bool dg::application::onEventClose(dg::windowCloseEvent &e) {
    (void)e;
    DG_CORE_ERROR("call back event after dispatch");
    //glutHideWindow();
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