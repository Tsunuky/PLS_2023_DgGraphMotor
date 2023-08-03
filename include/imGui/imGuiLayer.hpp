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
    virtual void onDetach() override;
    virtual void onAttach() override;
    virtual void onImguiRender() override;
public:
    void begin();
    void end();
private:
    float _time = 0.0f;
};
}