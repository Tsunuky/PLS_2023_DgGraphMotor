#pragma once

namespace dg {

class timeStep {
public:
    timeStep(float time = 0.0f): _time(time) {

    }
public:
    operator float() const {return _time;}
public:
    float getSeconds() const {return _time;}
    float getMilliseconds() const {return _time * 1000.f;}
private:
    float _time;
};

}