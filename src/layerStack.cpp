#include <layerStack.hpp>

#include <algorithm>

dg::layerStack::layerStack() {
    _layerInsert = _layers.begin();
}

dg::layerStack::~layerStack() {
    for (auto &layer : _layers)
        delete layer;
}

void dg::layerStack::pushLayer(layer *layer) {
    _layerInsert = _layers.emplace(_layerInsert, layer);
}

void dg::layerStack::pushOverlay(layer *overlay) {
    _layers.emplace_back(overlay);
}

void dg::layerStack::popLayer(layer *layer) {
    auto it = std::find(_layers.begin(), _layers.end(), layer);
    if (it == _layers.end())
        return;
    _layers.erase(it);
    _layerInsert--;
}

void dg::layerStack::popOverlay(layer *overlay) {
    auto it = std::find(_layers.begin(), _layers.end(), overlay);
    if (it != _layers.end())
        _layers.erase(it);
}