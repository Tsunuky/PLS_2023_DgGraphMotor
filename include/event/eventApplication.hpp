#pragma once

#include <sstream>
#include <event.hpp>

namespace dg {

class windowResizEvent: public event {
public:
    windowResizEvent(u_int width, u_int height): _width(width), _height(height) {}
public:
    std::string toString() const override {
        std::stringstream ss;
        ss << "WindowResizeEvent: " << _width << ", " << _height;
        return ss.str();
    }
	EVENT_CLASS_TYPE(windowResize)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
public:
    u_int getWidth() const {return _width;}
    u_int getHeight() const {return _height;}
private:
    u_int _width;
    u_int _height;
};


class windowCloseEvent: public event {
public:
    windowCloseEvent() = default;
    EVENT_CLASS_TYPE(windowClose)
    EVENT_CLASS_CATEGORY(eventCategoryApplication)
};

}