#define GL_GLEXT_PROTOTYPES

#include <OpenGL/OpenGLShader.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <log.hpp>

void dg::shaderOpenGL::bind() const {
    glUseProgram(_rendererId);

}

void dg::shaderOpenGL::unbind() const {
    glUseProgram(0);
}

//si on bind pas avant crashhhh
void dg::shaderOpenGL::uploadUniformMat4(const std::string &name, const glm::mat4 &matrix) {
    GLint location = glGetUniformLocation(_rendererId, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

static void errorShaderCompile(u_int id, u_int type, const std::string &mess) {
    int lenght = 0;
    char *message;

    if (mess == "shader") {
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
        message = (char *)alloca(sizeof(char) * lenght);
        glGetShaderInfoLog(id, lenght, &lenght, message);
        DG_CORE_WARN("Failed to compile {0} shader de **** !!", (type == GL_VERTEX_SHADER  ? "vertex" : "fragment"));
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

static inline u_int compileShader(u_int type, const std::string &source) {
    u_int id = glCreateShader(type);
    const char *src = source.c_str();
    int res;

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &res);
    if (!res)
        errorShaderCompile(id, type, "shader");
    return id;
}

void dg::shaderOpenGL::attachShader() const {
    if (_vertex_id != 0)
        glAttachShader(_rendererId, _vertex_id);
    if (_fragment_id != 0)
        glAttachShader(_rendererId, _fragment_id);
}

void dg::shaderOpenGL::printId() const {
    DG_CORE_INFO("prog id {0}",  _rendererId);
    DG_CORE_INFO("u_int vs {0}",  _vertex_id);
    DG_CORE_INFO("u_int fs {0}",  _fragment_id);
};

void dg::shaderOpenGL::createShader(const std::string &vertex, const std::string &fragment) {
    int res = 0;

    _rendererId = glCreateProgram();
    _vertex_id = compileShader(GL_VERTEX_SHADER, vertex);
    _fragment_id = compileShader(GL_FRAGMENT_SHADER, fragment);
    //printId();
    attachShader();
    glLinkProgram(_rendererId);
    glGetProgramiv(_rendererId, GL_LINK_STATUS, &res);
    if (res != GL_TRUE)
        errorShaderCompile(_rendererId, 0, "link");  
    glValidateProgram(_rendererId);

    glGetProgramiv(_rendererId, GL_VALIDATE_STATUS, &res);
    if (res != GL_TRUE)
        errorShaderCompile(_rendererId, 0, "program");
    glDetachShader(_rendererId, _vertex_id);
    glDetachShader(_rendererId, _fragment_id);
    glDeleteShader(_vertex_id);
    glDeleteShader(_fragment_id);
}