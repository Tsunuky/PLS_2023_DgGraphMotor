#pragma once

#include <sstream>
#include <functional>
#include <event.hpp>
#include <input.hpp>

namespace dg {

class KeyPressed: public event {
public:
    KeyPressed(u_int key, u_int nativeKey): _userFunc(NULL), _key(key), _nativeKey(nativeKey) {
        keyMap::setKeyInMap(key, true);
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
    inline u_int getNativeCode() const {return _nativeKey;};
private:
    std::function<void(void *)> _userFunc;
    u_int _key;
    u_int _nativeKey;
};

class keyReleased: public event {
public:
    keyReleased(u_int key, u_int nativeKey): _userFunc(NULL), _key(key), _nativeKey(nativeKey) {
        keyMap::setKeyInMap(key, false);
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
    inline u_int getNativeCode() const {return _nativeKey;};
private:
    std::function<void(void *)> _userFunc;
    u_int _key;
    u_int _nativeKey;
};

class keyType: public event {
public:
    keyType(u_int keytype): _userFunc(NULL), _keytype(keytype) {
    };
public:
    std::string toString() const override {
        std::stringstream ss;

        ss << "Key Type " << _keytype;
        return ss.str();
    }
   	EVENT_CLASS_TYPE(keyType)
	EVENT_CLASS_CATEGORY(eventCategoryKeyboard) 
public:
    inline u_int getKeyType() const {return _keytype;};
private:
    std::function<void(void *)> _userFunc;
    u_int _keytype;
};

}
