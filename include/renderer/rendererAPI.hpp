#pragma once

#include <glm/glm.hpp>
#include <renderer/vertexArray.hpp>

namespace dg {

class rendererAPI {
public:
    enum class API {
        none = 0,
        openGL = 1
    };
public:
    virtual void setClearColor(const glm::vec4 &color) = 0;
    virtual void clear() = 0;

    virtual void drawIndexed(const std::shared_ptr<vertexArray> &vertexArray) = 0;
    inline static API getAPI() {return _API;};
private:
    static API _API;
};

}
