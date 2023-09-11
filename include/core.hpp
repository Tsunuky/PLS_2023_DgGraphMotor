#pragma once

namespace dg {

class core {
public:
    core(bool debug): _debug(debug) {};
    ~core() = default;
public:
    void glAllInit();
private:
    bool _debug;
};

}