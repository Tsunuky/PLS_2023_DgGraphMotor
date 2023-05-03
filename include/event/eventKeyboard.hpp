#pragma once

#include <sstream>
#include <functional>
#include <event.hpp>
#include <input.hpp>

namespace dg {

class KeyPressed: public event {
public:
    KeyPressed(u_int key, int x, int y): _userFunc(NULL), _key(key), _x(x), _y(y) {
        keyMap::setKeyInMap(key, true);
    };
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

class keySpePressed: public event {
public:
    keySpePressed(u_int key, int x, int y): _userFunc(NULL), _key(key), _x(x), _y(y) {
        keyMap::setKeyInMap(256 + key, true);
    };
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Key special pressed "<< _key << " at x: " << _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(keySpePressed)
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
    keyReleased(u_int key, int x, int y): _userFunc(NULL), _key(key), _x(x), _y(y) {
        keyMap::setKeyInMap(key, false);
    };
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

class keySpeReleased: public event {
public:
    keySpeReleased(u_int key, int x, int y): _userFunc(NULL), _key(key), _x(x), _y(y) {
        keyMap::setKeyInMap(256 + key, true);
    };
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Key special released "<< _key << " at x: " << _x << " y: " << _y;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(keySpeReleased)
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
