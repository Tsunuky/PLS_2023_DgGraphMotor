#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

namespace dg {

class orthographiCamera {
public:
    orthographiCamera(float left, float right, float bottom, float top)
        : _projectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), _viewMatrix(1.0f) {
        _viewProjectionMatrix = _projectionMatrix * _viewMatrix;
    }
public:
    void setPosition(const glm::vec3 &position) {_position = position; recalculateViewMatrix();}
    void setRotation(float rotation) {_rotation = rotation; recalculateViewMatrix();}
public:
    const glm::vec3 &getPosition() const {return _position;}
    float getRotation() const {return _rotation;}

    const glm::mat4 &getProjectionMatrix() const {return _projectionMatrix;}
    const glm::mat4 &getviewMatrix() const {return _viewMatrix;}
    const glm::mat4 &getviewProjectionMatrix() const {return _viewProjectionMatrix;}
private:
    void recalculateViewMatrix();
private:
    glm::mat4 _projectionMatrix;
    glm::mat4 _viewMatrix;
    glm::mat4 _viewProjectionMatrix;
    // multiplication des deux du dessus pour eviter le calcul a chaque appel
    // mais utilise 64 bits de memory en plus

    glm::vec3 _position = {0, 0, 0};
    float _rotation = 0.0f;
};

}