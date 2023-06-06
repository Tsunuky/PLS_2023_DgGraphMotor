#pragma once

#include <event/eventApplication.hpp>
#include <event/eventKeyboard.hpp>
#include <application.hpp>
#include <eventMouse.hpp>
#include <layer.hpp>

namespace dg {
class imGuiLayer: public layer {
public:
    imGuiLayer(): layer("imGuiLayer") {};
    ~imGuiLayer() = default;
public:
    void onDetach();
    void onAttach();
    void onUpdate();
    void onEvent(event &event);
private:
    bool onMouseButtonPressed(mouseButtonPressed &e);
    bool onMouseButtonReleased(mouseButtonReleased &e);
    bool onMouseScrolled(mouseScrolled &e);
    bool onMouseMove(mouseMoved &e);
    bool onKeyPressed(KeyPressed &e);
    bool onKeyReleased(keyReleased &e);
    //bool onKeyType(keyType &e);
    bool onWindowRezise(windowResizEvent &e);
private:
    float _time = 0.0f;
};
}