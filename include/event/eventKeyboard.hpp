#pragma once

#include <sstream>
#include <functional>
#include <event.hpp>
#include <input.hpp>

namespace dg {

class KeyPressed: public event {
public:
    KeyPressed(u_int key): _userFunc(NULL), _key(key) {
        //keyMap::setKeyInMap(key, true);
    };
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Key pressed "<< _key;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(KeyPressed)
	EVENT_CLASS_CATEGORY(eventCategoryKeyboard)
public:
    inline u_int getKey() const {return _key;};
private:
    std::function<void(void *)> _userFunc;
    u_int _key;
};

class keyReleased: public event {
public:
    keyReleased(u_int key): _userFunc(NULL), _key(key) {
        //keyMap::setKeyInMap(key, false);
    };
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Key released "<< _key;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(keyReleased)
	EVENT_CLASS_CATEGORY(eventCategoryKeyboard) 
public:
    inline u_int getKey() const {return _key;};
private:
    std::function<void(void *)> _userFunc;
    u_int _key;
};

}
