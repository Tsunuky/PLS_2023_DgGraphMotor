//#include <precompile.hpp>
#include <GL/glut.h>

#include <log.hpp>
#include <window_gl.hpp>

void dg::setWinPointer(int id, dg::window_GL *pointer) {
    if (id <= 0)
        DG_CORE_FATAL("Error id given in setWinOinter");
    _winUser.currentWin = pointer;
    _winUser.id = id;
}

dg::window_GL *dg::getWinPointer(int id) {
    if (id <= 0)
        DG_CORE_FATAL("Error id given in getWinPointer");
    if (_winUser.id > 0)
        if (id != _winUser.id)
            DG_CORE_FATAL("Error id concordances in getWinPointer");
    return _winUser.currentWin;
}

void dg::setWinUserPointer(int id, void *pointer) {
    if (id <= 0)
        DG_CORE_FATAL("Error id given in setWinUserPointer");
    if (_winUser.id > 0)
        if (id != _winUser.id)
            DG_CORE_FATAL("Error id concordances in setWinUserPointer");
    _winUser.data = pointer;
    _winUser.id = id;
}

void *dg::getUserWinPointer(int id) {
    if (id <= 0)
        DG_CORE_FATAL("Error id given in getWinUserPointer");
    if (_winUser.id > 0)
        if (id != _winUser.id)
            DG_CORE_FATAL("Error id concordances in getWinUserPointer");
    return _winUser.data;
}


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