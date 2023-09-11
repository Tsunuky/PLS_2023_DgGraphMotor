#pragma once

#include <string>
#include <glad/glad.hpp>

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