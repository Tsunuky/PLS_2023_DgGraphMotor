#include <layerStack.hpp>

#include <algorithm>

dg::layerStack::layerStack() {
}

dg::layerStack::~layerStack() {
    for (auto &layer : _layers)
        delete layer;
}

void dg::layerStack::pushLayer(layer *layer) {
    _layers.emplace(_layers.begin() + _layerInsertIndex, layer);
    _layerInsertIndex++;
    _size++;
}

void dg::layerStack::pushOverlay(layer *overlay) {
    _layers.emplace_back(overlay);
    _size++;
}

void dg::layerStack::popLayer(layer *layer) {
    auto it = std::find(_layers.begin(), _layers.end(), layer);
    if (it == _layers.end())
        return;
    _layers.erase(it);
    _layerInsertIndex--;
    _size--;
}

void dg::layerStack::popOverlay(layer *overlay) {
    auto it = std::find(_layers.begin(), _layers.end(), overlay);
    if (it != _layers.end())
        _layers.erase(it);
}