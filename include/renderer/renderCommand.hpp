#pragma once

#include <renderer/rendererAPI.hpp>

namespace dg {

class renderCommand {
public:
    inline static void setClearColor(const glm::vec4 &color) {
        _rendererAPI->setClearColor(color);
    }
    inline static void clear() {
        _rendererAPI->clear();
    }
    inline static void drawIndexed(const std::shared_ptr<vertexArray> &vertexArray) {
        _rendererAPI->drawIndexed(vertexArray);
    }
private:
    static rendererAPI *_rendererAPI;
};

}