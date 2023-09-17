#include <renderer/renderer.hpp>
#include <log.hpp>

namespace dg {

renderer::sceneData *renderer::_sceneData = new renderer::sceneData();

void renderer::beginScene(orthographiCamera &camera) {
    _sceneData->viewProjectionMatrix = camera.getviewProjectionMatrix();
}

void renderer::endScene() {

}

void renderer::submit(const std::shared_ptr<shaderOpenGL> &shader, const std::shared_ptr<vertexArray> &vertexArray) {
    shader->bind();
    shader->uploadUniformMat4("u_viewProjection", _sceneData->viewProjectionMatrix);
    
    vertexArray->bind();
    renderCommand::drawIndexed(vertexArray);
}

}