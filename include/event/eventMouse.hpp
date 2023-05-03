#pragma once

#include <input.hpp>
#include <event.hpp>

namespace dg {

class mouseMoved: public event {
public:
    mouseMoved(int x, int y): _userFunc(NULL), _x(x), _y(y) {};
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Mousse move in x: "<< _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(mouseMoved)
	EVENT_CLASS_CATEGORY(eventCategoryMouse)
public:
    inline int getX() const {return _x;};
    inline int getY() const {return _y;};
private:
    std::function<void(void *)> _userFunc;
    int _x;
    int _y;
};

class mouseMovedClick: public event {
public:
    mouseMovedClick(int x, int y): _userFunc(NULL), _x(x), _y(y) {};
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Mousse move with click button in x: "<< _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(mouseMovedClick)
	EVENT_CLASS_CATEGORY(eventCategoryMouse)
public:
    inline int getX() const {return _x;};
    inline int getY() const {return _y;};
private:
    std::function<void(void *)> _userFunc;
    int _x;
    int _y;
};

class mouseScrolled: public event {
public:
    mouseScrolled(int button, int x, int y): _userFunc(NULL), _button(button), _x(x), _y(y) {
        buttonMap::setButtonInMap(button, true);
    };
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Mousse scrolled "<< _button <<" x: "<< _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(mouseScrolled)
	EVENT_CLASS_CATEGORY(eventCategoryMouse)
public:
    inline int getButton() const {return _button;};
    inline int getX() const {return _x;};
    inline int getY() const {return _y;};
private:
    std::function<void(void *)> _userFunc;
    int _button;
    int _x;
    int _y;
};

class mouseButtonPressed: public event {
public:
    mouseButtonPressed(int button, int x, int y): _userFunc(NULL), _button(button), _x(x), _y(y) {
        buttonMap::setButtonInMap(button, true);
    };
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Mousse button pressed "<< _button <<" x: "<< _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(mouseButtonPressed)
	EVENT_CLASS_CATEGORY(eventCategoryMouse)
public:
    inline int getButton() const {return _button;};
    inline int getX() const {return _x;};
    inline int getY() const {return _y;};
private:
    std::function<void(void *)> _userFunc;
    int _button;
    int _x;
    int _y;
};

class mouseButtonReleased: public event {
public:
    mouseButtonReleased(int button, int x, int y): _userFunc(NULL), _button(button), _x(x), _y(y) {
        buttonMap::setButtonInMap(button, false);
    };
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Mousse button released "<< _button <<" x: "<< _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(mouseButtonReleased)
	EVENT_CLASS_CATEGORY(eventCategoryMouse)
public:
    inline int getButton() const {return _button;};
    inline int getX() const {return _x;};
    inline int getY() const {return _y;};
private:
    std::function<void(void *)> _userFunc;
    int _button;
    int _x;
    int _y;
};

}
