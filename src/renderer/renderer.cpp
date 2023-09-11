#include <renderer/renderer.hpp>

namespace dg {

void renderer::beginScene() {

}

void renderer::endScene() {

}

void renderer::submit(const std::shared_ptr<vertexArray> &vertexArray) {
    vertexArray->bind();
    renderCommand::drawIndexed(vertexArray);
}

}