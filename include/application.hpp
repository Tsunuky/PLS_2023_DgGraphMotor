#pragma once

#include <log.hpp>

#include <eventApplication.hpp>
#include <window_gl.hpp>
#include<layerStack.hpp>

#define BIND_EVENT_FN(x) std::bind_front(&x, this)
class application {
public:
    application() {
        _win.reset(dg::window_API::create(dg::window("doggo")));
        _win->setEventCallback(BIND_EVENT_FN(application::onEvent));
    };
    virtual ~application() {};
public:
    application *createApplication();
public:
    void onEvent(dg::event &e) {
        dg::eventDispatcher dispatcher(e);

        dispatcher.Dispatch<dg::windowCloseEvent>(BIND_EVENT_FN(application::onEventClose));
        DG_CORE_TRACE("{0}",e.toString());
        for (auto it = _layerStack.begin(); it != _layerStack.end(); ++it) {
            if (e.handled)
                break;
            (*it)->onEvent(e);
        }
    }
    void run(int argc, char **argv, bool lgio = false) {
        _win->run(&_layerStack, argc, argv, lgio);
    };
    bool onEventClose(dg::windowCloseEvent &e) {
        (void)e;
        DG_CORE_ERROR("call back event after dispatch");
        //glutHideWindow();
        return true;
    }
    void pushLayer(dg::layer *layer) {
        _layerStack.pushLayer(layer);
    }
    void pushOverlay(dg::layer *overlay) {
        _layerStack.pushOverlay(overlay);
    }
private:
    std::unique_ptr<dg::window_API> _win;
    dg::layerStack _layerStack;
};