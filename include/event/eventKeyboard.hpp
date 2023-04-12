#pragma once

#include <sstream>
#include <functional>
#include <event.hpp>

namespace dg {

class KeyPressed: public event {
public:
    KeyPressed(u_int key, int x, int y): _userFunc(NULL), _key(key), _x(x), _y(y) {};
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Key pressed "<< _key << " at x: " << _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(KeyPressed)
	EVENT_CLASS_CATEGORY(eventCategoryKeyboard)
public:
    inline u_int getKey() const {return _key;};
    inline int getX() const {return _x;};
    inline int getY() const {return _y;};
private:
    std::function<void(void *)> _userFunc;
    u_int _key;
    int _x;
    int _y;
};

class KeySpePressed: public event {
public:
    KeySpePressed(u_int key, int x, int y): _userFunc(NULL), _key(key), _x(x), _y(y) {};
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Key special pressed "<< _key << " at x: " << _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(KeySpePressed)
	EVENT_CLASS_CATEGORY(eventCategoryKeyboard) 
public:
    inline u_int getKey() const {return _key;};
    inline int getX() const {return _x;};
    inline int getY() const {return _y;};
private:
    std::function<void(void *)> _userFunc;
    u_int _key;
    int _x;
    int _y;
};

class keyReleased: public event {
public:
    keyReleased(u_int key, int x, int y): _userFunc(NULL), _key(key), _x(x), _y(y) {};
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Key released "<< _key << " at x: " << _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(keyReleased)
	EVENT_CLASS_CATEGORY(eventCategoryKeyboard) 
public:
    inline u_int getKey() const {return _key;};
    inline int getX() const {return _x;};
    inline int getY() const {return _y;};
private:
    std::function<void(void *)> _userFunc;
    u_int _key;
    int _x;
    int _y;
};

class KeySpeReleased: public event {
public:
    KeySpeReleased(u_int key, int x, int y): _userFunc(NULL), _key(key), _x(x), _y(y) {};
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Key special released "<< _key << " at x: " << _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(KeySpeReleased)
	EVENT_CLASS_CATEGORY(eventCategoryKeyboard)
public:
    inline u_int getKey() const {return _key;};
    inline int getX() const {return _x;};
    inline int getY() const {return _y;}; 
private:
    std::function<void(void *)> _userFunc;
    u_int _key;
    int _x;
    int _y;
};

}
