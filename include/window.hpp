#pragma once

//#include <precompile.hpp>

#include <string>
#include <struct.hpp>

namespace dg {

//faire une encapsulation de window sans aucun call opengl pour la draw quand le core se lance
struct window {
public:
    window(const std::string &name = "Window", u_int sw = 1024, u_int sh = 512): _sw(sw), _sh(sh), _name(name) {};
public:
    u_int _sw;
    u_int _sh;
    std::string _name;
};

class window_GL: protected window{
public:
    window_GL() {};
    ~window_GL() = default;
public:
    void initWindow();
    void setOrtho();
public:
    void start(int, char **, bool);
    void clearColor(const dg::rgba &);
    void setOrtho(double, double, double, double);
    void scalePixel(float);
public:
    u_int getsizeWidth() {return this->_sw;};
    u_int getsizeHeight() {return this->_sh;};
};

}
//glutReshapeWindow(dgCorePtr->getsizeWidth(), dgCorePtr->getsizeHeight());
