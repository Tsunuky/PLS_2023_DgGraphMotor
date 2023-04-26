#pragma once

#include <GL/freeglut.h>
#include <log.hpp>

#include <eventApplication.hpp>
#include <window_gl.hpp>
#include <layerStack.hpp>
#include <imGui/imGuiLayer.hpp>

#define BIND_EVENT_FN(x) std::bind_front(&x, this)

namespace dg {

class application {
public:
    application() {
        dg::log::init();
    
        _instance = this;    
        _win.reset(dg::window_API::create(dg::window("doggo")));
        _win->setEventCallback(BIND_EVENT_FN(application::onEvent));
    };
    virtual ~application() {};
public:
    application *createApplication();
public:
    void onEvent(dg::event &e);
    void run(int argc, char **argv, bool lgio = false);
    bool onEventClose(dg::windowCloseEvent &e);
    void pushLayer(dg::layer *layer);
    void pushOverlay(dg::layer *overlay);
public:
    inline static application &get() {return *_instance;}
    inline std::unique_ptr<dg::window_API> &getWindow() {return _win;};
private:
    std::unique_ptr<dg::window_API> _win;
    dg::layerStack _layerStack;
    static application *_instance;
};

inline application *application::_instance = nullptr;

}