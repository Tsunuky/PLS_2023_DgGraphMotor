#pragma once

//#include <precompile.hpp>
#include <string>

namespace dg {

class shader {
public:
    shader();
    shader(const std::string &path);
    shader(const std::string &vertex, const std::string &fragment) {
        createShader(vertex, fragment);
    };
    ~shader() = default;
public:
    u_int getShader() {return _shader_id;};
    void printId() const;
private:
    void createShader(const std::string &vertex, const std::string &fragment);
    void attachShader() const;
private:
    u_int _shader_id;
    u_int _vertex_id;
    u_int _fragment_id;
};

};