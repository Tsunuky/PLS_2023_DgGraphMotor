#pragma once

#include <renderer/graphiContext.hpp>

#include <log.hpp>

struct GLFWwindow;

namespace dg {

class OpenGLContext: public GraphiContext {
public:
    OpenGLContext(GLFWwindow* window);
public:
    virtual void init() override;
    virtual void swapBuffer() override;
private:
    GLFWwindow *_windowHandler;
};

}