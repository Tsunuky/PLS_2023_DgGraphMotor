#pragma once

#include <GL/glut.h>
#include <string>

#include "struct.hpp"

namespace dg {

//faire une encapsulation de window sans aucun call opengl pour la draw quand le core se lance
class window {
public:
    window(const std::string &name = "Window", u_int sw = 1024, u_int sh = 512): _sw(sw), _sh(sh), _name(name) {};
    ~window() = default;
public:
    void initWindow();
    void setOrtho();
public:
    void start(int, char **, bool);
    void clearColor(const dg::rgba &);
    void setOrtho(double, double, double, double);
    void scalePixel(float);
public:
    u_int getsizeWidth() {return _sw;};
    u_int getsizeHeight() {return _sh;};
private:
    u_int _sw;
    u_int _sh;
    std::string _name;
};

}
//glutReshapeWindow(dgCorePtr->getsizeWidth(), dgCorePtr->getsizeHeight());
