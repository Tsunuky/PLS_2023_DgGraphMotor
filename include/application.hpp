#pragma once

#include <log.hpp>
#include <window.hpp>

class application: public dg::window_GL {
public:
    application() {
        this->setOrtho();
    };
    ~application() = default;
//public:
//    application *createApplication();
public:
    void run(int argc, char **argv, bool lgio = false) {
        this->start(argc, argv, lgio);
    };
private:
};

/* a faire apres abstraction de window

#include <core.hpp>

class application: public dg::core {
public:
    application();
    virtual ~application();
public:
    application *createApplication();
public:
    void run();
private:
};
*/