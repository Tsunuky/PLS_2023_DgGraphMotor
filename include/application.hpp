#pragma once

#include <log.hpp>

#include <window_gl.hpp>

class application {
public:
    application() {
        _win.reset(dg::window_API::create(dg::window("doggo")));
        _win->setEventCallback(std::bind_front(&application::onEvent, this));
    };
    virtual ~application() {};
public:
    application *createApplication();
public:
    void onEvent(dg::event &e) {

    }
    void run(int argc, char **argv, bool lgio = false) {
        _win->run(argc, argv, lgio);
    };
private:
    std::unique_ptr<dg::window_API> _win;
};