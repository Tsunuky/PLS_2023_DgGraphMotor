#define GL_GLEXT_PROTOTYPES

#include <GL/glx.h>
//#include <GL/glext.h>
#include <GL/glut.h>

#include <window.hpp>
#include <shader.hpp>
#include <core.hpp>
#include <log.hpp>

#include <eventApplication.hpp>

dg::core *dgCorePtr;

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
 
void dg::core::display() {
    glDrawArrays(GL_TRIANGLES, 0, 3);//test
}

void dg::core::idleDisplay() {
    glDrawArrays(GL_TRIANGLES, 0, 3);//test
}

void dg::window_GL::start(int argc, char **argv, bool debug = false) {
    dg::core dgcore(debug);

    dgCorePtr = &dgcore;
    dgcore.glutAllInit(argc, argv);
    initWindow();
    dgcore.initGlutCallback();
}

void dg::core::glutAllInit(int argc, char **argv) {
    glutInit(&argc, argv);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

static void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    dgCorePtr->display();
    glutSwapBuffers();
}

static void idleRender() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    dgCorePtr->idleDisplay();
    glutSwapBuffers();
}

void dg::core::initGlutCallback() {
    u_int buffer; //test

    glEnableVertexAttribArray(0);//test
    glGenBuffers(1, &buffer);//test
    glBindBuffer(GL_ARRAY_BUFFER, buffer);//test
    glBufferData(GL_ARRAY_BUFFER, 6 *sizeof(float), position, GL_STATIC_DRAW);//test
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//test

    dg::shader shad(vertexshader, fragmentshader);
    if (_debug)
        DG_CORE_INFO((char *)glGetString(GL_VERSION));
    glutDisplayFunc(render);
    glutIdleFunc(idleRender);
    //glutKeyboardFunc(KeysDown);
    //glutKeyboardUpFunc(KeysUp);
    glUseProgram(shad.getShader());
    glutMainLoop();
}
