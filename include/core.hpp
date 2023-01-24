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
    void display();
    void idleDisplay();
private:
    bool _debug;
};

}