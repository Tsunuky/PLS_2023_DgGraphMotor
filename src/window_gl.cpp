//#include <precompile.hpp>
#include <GL/glut.h>

#include <log.hpp>
#include <window_gl.hpp>

dg::window_API *dg::window_API::create(const window &props) {
    return new dg::window_GL(props);
}

void dg::window_GL::initWindow() {

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(getsizeWidth(), getsizeHeight());
    glutInitWindowPosition(getsizeWidth()/2, getsizeHeight()/2);
    if (glutCreateWindow(_data.tittle.c_str()) == 0)
        DG_CORE_FATAL("Error creating window");
    DG_CORE_INFO("Creating Window '{0}' width: {1}, height: {2}", _data.tittle, _data.width, _data.height);
}

void dg::window_GL::update() {

}

void dg::window_GL::setVsync(bool enable) {
    _data.sync = enable;
}

void dg::window_GL::clearColor(const dg::rgba &color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

void dg::window_GL::setOrtho(double left, double right, double bottom, double top) {
    gluOrtho2D(left, right, bottom, top);
}

void dg::window_GL::setOrtho() {
    gluOrtho2D(0, getsizeWidth(), getsizeHeight(), 0);
}

void dg::window_GL::scalePixel(float scale) {
    glPointSize(scale);
}