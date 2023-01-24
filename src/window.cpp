#include <iostream>
#include "window.hpp"

void dg::window::initWindow() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(_sw, _sh);
    glutInitWindowPosition(_sw/2, _sh/2);
    if (glutCreateWindow(_name.c_str()) == 0)
        std::cerr << "Error creating window" << std::endl;
}

void dg::window::clearColor(const dg::rgba &color) {
    glClearColor (color.r, color.g, color.b, color.a);
}

void dg::window::setOrtho(double left, double right, double bottom, double top) {
    gluOrtho2D(left, right, bottom, top);
};

void dg::window::setOrtho() {
    gluOrtho2D(0, _sw, _sh, 0);
}

void dg::window::scalePixel(float scale) {
    glPointSize(scale);
}