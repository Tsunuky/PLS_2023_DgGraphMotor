#define GL_GLEXT_PROTOTYPES

#include <GL/glx.h>
//#include <GL/glext.h>

#include <log.hpp>
#include <shader.hpp>

static void errorShaderCompile(u_int id, u_int type, const std::string &mess) {
    int lenght = 0;
    char *message;

    if (mess == "shader") {
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
        message = (char *)alloca(sizeof(char) * lenght);
        glGetShaderInfoLog(id, lenght, &lenght, message);
        DG_CORE_WARN("Failed to compile {0} shader !!", (type == GL_VERTEX_SHADER  ? "vertex" : "fragment"));
        glDeleteShader(id);
    }
    if (mess == "link") {
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &lenght);
        message = (char *)alloca(sizeof(char) * lenght);
        glGetProgramInfoLog(id, lenght, &lenght, message);
        DG_CORE_WARN("Error link prog: {0}", lenght );
    }
    if (mess == "program") {
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &lenght);
        message = (char *)alloca(sizeof(char) * lenght);
        glGetProgramInfoLog(id, lenght, &lenght, message);
        DG_CORE_WARN("Invalid shader prog: {0} ", lenght);
        glDeleteProgram(id);
    }
    DG_CORE_WARN(message);
}

static u_int compileShader(u_int type, const std::string &source) {
    u_int id = glCreateShader(type);
    const char *src = source.c_str();
    int res;

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &res);
    if (res != GL_TRUE)
        errorShaderCompile(id, type, "shader");
    return id;
}

void dg::shader::attachShader() const {
    if (_vertex_id != 0)
        glAttachShader(_shader_id, _vertex_id);
    if (_fragment_id != 0)
        glAttachShader(_shader_id, _fragment_id);
}

void dg::shader::printId() const {
    DG_CORE_INFO("prog id {0}",  _shader_id);
    DG_CORE_INFO("u_int vs {0}",  _vertex_id);
    DG_CORE_INFO("u_int fs {0}",  _fragment_id);
};

void dg::shader::createShader(const std::string &vertex, const std::string &fragment) {
    int res = 0;

    _shader_id = glCreateProgram();
    _vertex_id = compileShader(GL_VERTEX_SHADER, vertex);
    _fragment_id = compileShader(GL_FRAGMENT_SHADER, fragment);
    //printId();
    attachShader();
    glLinkProgram(_shader_id);
    glGetProgramiv(_shader_id, GL_LINK_STATUS, &res);
    if (res != GL_TRUE)
        errorShaderCompile(_shader_id, 0, "link");  
    glValidateProgram(_shader_id);
    glGetProgramiv(_shader_id, GL_VALIDATE_STATUS, &res);
    if (res != GL_TRUE)
        errorShaderCompile(_shader_id, 0, "program");
    glDeleteShader(_vertex_id);
    glDeleteShader(_fragment_id);
}

//static void parseShader(const std::string &file) {}