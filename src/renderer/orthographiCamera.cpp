#include <renderer/orthographiCamera.hpp>

namespace dg {

void orthographiCamera::recalculateViewMatrix() {
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), _position) *
        glm::rotate(glm::mat4(1.0f), glm::radians(_rotation), glm::vec3(0, 0, 1));
    _viewMatrix = glm::inverse(transform);
    _viewProjectionMatrix = _projectionMatrix * _viewMatrix;
}

}