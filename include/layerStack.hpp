#pragma once

#include <vector>

#include <layer.hpp>

namespace dg {

class layerStack {
public:
    layerStack();
    ~layerStack();
public:
    void pushLayer(layer *layer);
    void pushOverlay(layer *overlay);
    void popLayer(layer *layer);
    void popOverlay(layer *overlay);
public:
    std::vector<layer*>::iterator begin() {return _layers.begin();};
    std::vector<layer*>::iterator end() {return _layers.end();};
private:
    std::vector<layer*> _layers;
    std::vector<layer*>::iterator _layerInsert;
};

}