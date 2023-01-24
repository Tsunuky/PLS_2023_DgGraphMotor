#include <functional>
#include <iostream>
#include <memory>
#include "core.hpp"
#include "window.hpp"

dg::core *dgCorePtr;

void dg::core::display() {
}

void dg::core::idleDisplay() {
}

void dg::window::start(int argc, char **argv, bool debug = false) {
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
    if (_debug)
        std::cout << glGetString(GL_VERSION) << std::endl;
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
    glutDisplayFunc(render);
    glutIdleFunc(idleRender);
    //glutKeyboardFunc(KeysDown);
    //glutKeyboardUpFunc(KeysUp);
    glutMainLoop();
}