#pragma once

#include <functional>
#include <string>
#include <memory>

#include <layerStack.hpp>
#include <struct.hpp>
#include <event.hpp>

namespace dg {

struct window {
public:
    window(const std::string &name = "Window", u_int sw = 1024, u_int sh = 512): _sw(sw), _sh(sh), _name(name) {};
public:
    u_int _sw;
    u_int _sh;
    std::string _name;
};

class window_API {
public:
    virtual ~window_API() {}
public:
    using eventCallbackFn = std::function<void(event&)>;
public:
    virtual void setEventCallback(const eventCallbackFn &callback) = 0;
    virtual void setVsync(bool) = 0;
    virtual void onUpdate() = 0;
    virtual bool isVsync() const = 0;
    virtual void run(layerStack *stack, int, char **, bool) = 0;
public:
    virtual u_int getsizeWidth() const = 0;
    virtual u_int getsizeHeight() const = 0;

    virtual void pd() const = 0;
public:
    static window_API *create(const window &props = window());
};



}
//glutReshapeWindow(dgCorePtr->getsizeWidth(), dgCorePtr->getsizeHeight());
