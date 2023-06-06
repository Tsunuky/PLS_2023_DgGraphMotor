#pragma once

namespace dg {

class core {
public:
    core(bool debug): _debug(debug) {};
    ~core() = default;
public:
    void glAllInit();
    void initGlutCallback();
    void display();
    void idleDisplay();
    void checkDevice();
private:
    bool _debug;
};

struct corePointer {
    core *pointer;
};
inline corePointer _coreUser{NULL};

void setCorePointer(core *pointer);
core *getCorePointer();

}