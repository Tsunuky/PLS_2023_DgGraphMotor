#pragma once

#include <log.hpp>

#include <window_gl.hpp>

#define BIND_EVENT_FN(x) std::bind_front(&application::x, this)
class application {
public:
    application() {
        _win.reset(dg::window_API::create(dg::window("doggo")));
        _win->setEventCallback(BIND_EVENT_FN(onEvent));
    };
    virtual ~application() {};
public:
    application *createApplication();
public:
    void onEvent(dg::event &e) {
        DG_CORE_TRACE("{0}",e.toString());
    }
    void run(int argc, char **argv, bool lgio = false) {
        _win->run(argc, argv, lgio);
    };
private:
    std::unique_ptr<dg::window_API> _win;
};