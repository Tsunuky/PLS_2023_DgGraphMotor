#pragma once

#include <glad/glad.hpp>
#include <log.hpp>

#include <eventApplication.hpp>
#include <window_gl.hpp>
#include <layerStack.hpp>
#include <imGui/imGuiLayer.hpp>

#define BIND_EVENT_FN(x) std::bind_front(&x, this)

namespace dg {
struct appliSpecification {
    std::string Name = "Hazel Application";
    std::string WorkingDirectory;
};
class application {
public:
    application(std::string name = "Window") {
        dg::log::init();
    
        // mettre ca dans init
        dg::keyMap::initKeymap();
        dg::buttonMap::initButtonmap();
        
        DG_CORE_ASSERT(!_instance, "Application already exist");
        _instance = this;
        _win.reset(dg::window_API::create(dg::window(name)));
        _win->setEventCallback(BIND_EVENT_FN(application::onEvent));
    };
    virtual ~application() {};
public:
    application *createApplication();
public:
    void onEvent(dg::event &e);
    void run();
    bool onEventClose(dg::windowCloseEvent &e);
    void pushLayer(dg::layer *layer);
    void pushOverlay(dg::layer *overlay);
public:
    inline static application &get() {return *_instance;}
    inline dg::window_API &getWindow() {return *_win;};
private:
    std::unique_ptr<dg::window_API> _win;
    dg::layerStack _layerStack;
    static application *_instance;
    bool isRunning = true;
};

inline application *application::_instance = nullptr;

}