#pragma once

#include <string>
#include <glad/glad.hpp>
#include <glm/glm.hpp>

namespace dg {

class shaderOpenGL {
public:
    shaderOpenGL(const std::string &vertex, const std::string &fragment) {
        createShader(vertex,fragment);
    };
    ~shaderOpenGL() {
        glDeleteProgram(_rendererId);
    };
public:
    void bind() const;
    void unbind() const;
    void uploadUniformMat4(const std::string &name, const glm::mat4 &matrix);
private:
    void createShader(const std::string &vertex, const std::string &fragment);
    void attachShader() const;
    void printId() const;
private:
    u_int32_t _rendererId;
    u_int32_t _vertex_id;
    u_int32_t _fragment_id;
};

}