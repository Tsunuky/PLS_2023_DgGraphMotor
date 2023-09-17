#pragma once

#include <renderer/renderCommand.hpp>
#include <renderer/orthographiCamera.hpp>
#include <OpenGL/OpenGLShader.hpp>

namespace dg {

class renderer {
public:
    static void beginScene(orthographiCamera &camera);
    static void endScene();

    static void submit(const std::shared_ptr<shaderOpenGL> &shader, const std::shared_ptr<vertexArray> &vertexArray, const glm::mat4 &transform = glm::mat4(1.0f));
public:
    inline static rendererAPI::API getAPI() {return rendererAPI::getAPI();};
private:
    struct sceneData {
        glm::mat4 viewProjectionMatrix;
    };

    static sceneData *_sceneData;
};

}
