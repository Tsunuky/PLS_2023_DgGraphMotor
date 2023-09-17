#pragma once

#include <event.hpp>
#include <core/timeStep.hpp>

namespace dg {

class layer {
public:
    layer(const std::string &name = "layer"): _debugName(name) {};
    virtual ~layer() = default;
public:
    virtual void onAttach() {};
    virtual void onDetach() {};
    virtual void onUpdate(timeStep ts) {(void)ts;};
    virtual void onImguiRender() {};
    virtual void onEvent(event &e) {(void)e;};
public:
    inline const std::string &getName() const {return _debugName;};
private:
    std::string _debugName;
};

}
