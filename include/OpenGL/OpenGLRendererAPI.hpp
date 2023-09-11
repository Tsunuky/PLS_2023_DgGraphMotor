#pragma once

#include <renderer/rendererAPI.hpp>

namespace dg {

class OpenGLRendererAPI : public rendererAPI {
public:
    virtual void setClearColor(const glm::vec4 &color) override;
    virtual void clear() override;

    virtual void drawIndexed(const std::shared_ptr<vertexArray> &vertexArray) override;
private:
};

}