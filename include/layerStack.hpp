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
public:
    inline u_int getSize() const {return _size;};
private:
    std::vector<layer*> _layers;
    u_int _layerInsertIndex = 0;
    u_int _size = 0;
};

}