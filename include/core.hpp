#pragma once

namespace dg {

class core {
public:
    core(bool debug): _debug(debug) {};
    ~core() = default;
    //virtual ~core();
public:
    void glutAllInit(int argc, char **argv);
    void initGlutCallback();
    void start();
    void display();
    void idleDisplay();
    void checkDevice();
public:
    void setWin(int win) {_mainWin = win;}
public:
    int getWin() const {return this->_mainWin;};
private:
    int _mainWin;
    bool _debug;
};

struct corePointer {
    core *pointer;
};
inline corePointer _coreUser{NULL};

void setCorePointer(core *pointer);
core *getCorePointer();

}