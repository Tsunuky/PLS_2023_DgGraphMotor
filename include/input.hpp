#pragma once

#include <unordered_map>
#include <utility>

namespace dg {

class input {
public:
    inline static bool istKeyPress(int keycode) {return _instance->isKeyPressImpl(keycode);}
    inline static bool isButtonPress(int button) {return _instance->isButtonPressImpl(button);};
    inline static bool whileKeyPress(int keycode) {return _instance->whileKeyPressImpl(keycode);}
    inline static bool whileButtonPress(int button) {return _instance->whileButtonPressImpl(button);};


    inline static std::pair<int, int> getMousePos() {return _instance->getMousePosImpl();};
    inline static int getMouseX() {return _instance->getMouseXImpl();};
    inline static int getMouseY() {return _instance->getMouseYImpl();};
protected:
    virtual bool isKeyPressImpl(int keycode)  = 0;
    virtual bool isButtonPressImpl(int button) = 0;
    virtual bool whileKeyPressImpl(int keycode) = 0;
    virtual bool whileButtonPressImpl(int button) = 0;

    virtual std::pair<int, int> getMousePosImpl() = 0;
    virtual int getMouseXImpl() = 0;
    virtual int getMouseYImpl() = 0;
private:
    static input *_instance;
};

//peux transformer les namespace en class a voir

namespace keyMap {
//premier bool donne si key est presse deuxieme dit si on peut la repeter
inline std::unordered_map<int, std::pair<bool, bool>> _keymap;
//mettre un array de 512 en brut

void initKeymap();
std::pair<bool, bool> getKeyInMap(int keycode);
void setKeyInMap(int keycode, bool status, bool repeat = false);

}

namespace buttonMap {

inline std::unordered_map<int, std::pair<bool, bool>> _buttonmap;

void initButtonmap();
std::pair<bool, bool> getButtonInMap(int button);
void setButtonInMap(int button, bool status, bool repeat = false);

}

namespace mouseDataPos {

inline int _MouseX;
inline int _MouseY;

void initMousePos();
std::pair<int, int> getMousePos();
void setMousePos(int x, int y);

}

}