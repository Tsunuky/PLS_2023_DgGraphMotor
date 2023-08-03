#define GL_GLEXT_PROTOTYPES

#include <glad/glad.hpp>
#include <window_gl.hpp>
#include <core.hpp>
#include <log.hpp>

/**
std::string vertexshader =
    "#version 440 core\n"
    "#pragma debug(on)\n"
    "layout(location = 0) in vec4 position;\n"
    "\n"
    "void main()\n" 
    "{\n"
    "gl_Position = position;\n"
    "}\n";

std::string fragmentshader =
    "#version 440 core\n"
    "#pragma debug(on)\n"
    "layout(location = 0) out vec4 color;\n"
    "\n"
    "void main()\n"
    "{\n"
    "color = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";

float position[6] = { //test
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f,  -0.5f
};
 
// shader lek memory ne pas creer a chaque fois ou trouver comment les free les program

void MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam) {
    (void)source; (void)id; (void)length; (void)userParam;
    DG_CORE_ERROR("GL CALLBACK: {0} type = 0x{1}, severity = 0x{2}, message = {3}\n", (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "") , type, severity, message);
}

void dg::core::glAllInit() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable (GL_DEBUG_OUTPUT);

    glDebugMessageCallback(MessageCallback, 0);
    //all for test
    u_int buffer; //test

    glEnableVertexAttribArray(0);//test
    glGenBuffers(1, &buffer);//test
    glBindBuffer(GL_ARRAY_BUFFER, buffer);//test
    glBufferData(GL_ARRAY_BUFFER, 6 *sizeof(float), position, GL_STATIC_DRAW);//test
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//test

}
*/