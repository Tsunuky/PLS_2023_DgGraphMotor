#pragma once

#include <sstream>
#include <event.hpp>
//#include <window_gl.hpp>

/*void function(void *data) {
    u_int *cc = (u_int *)data;
    DG_TRACE("hello je suis un chat de taille {0}", *cc);
}*/

namespace dg {

class windowResizEvent: public event {
public:
    windowResizEvent(u_int width, u_int height): _width(width), _height(height) {
        //_userFunc = function;
        //DG_ERROR("{0}" , fmt::ptr(&_winUser));
    }
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "WindowResizeEvent: " << _width << ", " << _height;
        //_userFunc((void *)&_width);
        return ss.str();
    }
	EVENT_CLASS_TYPE(windowResize)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
public:
    u_int getWidth() const {return _width;}
    u_int getHeight() const {return _height;}
private:
    std::function<void(void *)> _userFunc;
    u_int _width;
    u_int _height;
};


class windowCloseEvent: public event {
public:
    windowCloseEvent(): _userFunc(NULL) {};
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Close window";
        return ss.str();
    }
    EVENT_CLASS_TYPE(windowClose)
    EVENT_CLASS_CATEGORY(eventCategoryApplication)
private:
    std::function<void(void *)> _userFunc;
};

class windowFocus: public event {
public:
    windowFocus(): _userFunc(NULL) {}
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Get focus";
        return ss.str();
    }
	EVENT_CLASS_TYPE(windowFocus)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
private:
    std::function<void(void *)> _userFunc;
};

class windowLostFocus: public event {
public:
    windowLostFocus(): _userFunc(NULL) {}
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Lost focus";
        return ss.str();
    }
	EVENT_CLASS_TYPE(windowLostFocus)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
private:
    std::function<void(void *)> _userFunc;
};

class windowId: public event {
public:
    windowId(int state): _userFunc(NULL), _id(state) {}
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Current window id: " << _id;
        return ss.str();
    }
	EVENT_CLASS_TYPE(windowId)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
public:
    inline int getId() const {return _id;};
private:
    std::function<void(void *)> _userFunc;
    int _id;
};


}