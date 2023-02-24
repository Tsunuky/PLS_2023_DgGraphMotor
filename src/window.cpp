//#include <precompile.hpp>
#include <GL/glut.h>

#include <log.hpp>
#include <window.hpp>

void dg::window_GL::initWindow() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(this->_sw, this->_sh);
    glutInitWindowPosition(_sw/2, _sh/2);
    if (glutCreateWindow(_name.c_str()) == 0)
        DG_CORE_FATAL("Error creating window");
}

void dg::window_GL::clearColor(const dg::rgba &color) {
    glClearColor (color.r, color.g, color.b, color.a);
}

void dg::window_GL::setOrtho(double left, double right, double bottom, double top) {
    gluOrtho2D(left, right, bottom, top);
};

void dg::window_GL::setOrtho() {
    gluOrtho2D(0, _sw, _sh, 0);
}

void dg::window_GL::scalePixel(float scale) {
    glPointSize(scale);
}