#include <cstdio>

#include <log.hpp>

#include <inputLinux.hpp>

namespace dg {

input *input::_instance = new linuxInput();

bool linuxInput::isKeyPressImpl(int keycode) {
    std::pair<bool, bool> state = keyMap::getKeyInMap(keycode);
    
    if (state.second == true)
        return false;
    keyMap::setKeyInMap(keycode, state.first, true);
    return state.first;
}

bool linuxInput::whileKeyPressImpl(int keycode) {
    return keyMap::getKeyInMap(keycode).first;
}

bool linuxInput::isButtonPressImpl(int keycode) {
    std::pair<bool, bool> state = buttonMap::getButtonInMap(keycode);
    
    if (state.second == true)
        return false;
    buttonMap::setButtonInMap(keycode, state.first, true);
    return state.first;
}

bool linuxInput::whileButtonPressImpl(int button) {
    return buttonMap::getButtonInMap(button).first;
}

std::pair<int, int> linuxInput::getMousePosImpl() {
    return mouseDataPos::getMousePos();
}

int linuxInput::getMouseXImpl() {
    return mouseDataPos::getMousePos().first;
}

int linuxInput::getMouseYImpl() {
    return mouseDataPos::getMousePos().second;
}

void keyMap::initKeymap() {
    for (size_t i = 0; i != 256; i++) {
        _keymap.emplace(i, std::make_pair(false, false));
    }
    /*_keymap.emplace(256 + GLUT_KEY_PAGE_DOWN, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_PAGE_UP, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_INSERT, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_RIGHT, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_DOWN, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_HOME, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_LEFT, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_END, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_UP, std::make_pair(false, false));

    _keymap.emplace(256 + GLUT_KEY_F1, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F2, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F3, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F4, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F5, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F6, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F7, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F8, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F9, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F10, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F11, std::make_pair(false, false));
    _keymap.emplace(256 + GLUT_KEY_F12, std::make_pair(false, false));
    */
}

std::pair<bool, bool> keyMap::getKeyInMap(int keycode) {
    return _keymap.at(keycode);
}

void keyMap::setKeyInMap(int keycode, bool status, bool repeat) {
    _keymap[keycode].first = status;
    _keymap[keycode].second = repeat;
}

//faire par rapport au button get par glut
void buttonMap::initButtonmap() {
    for (size_t i = 0; i != 12; i++) {
        _buttonmap.emplace(i, std::make_pair(false, false));
    }
}

std::pair<bool, bool> buttonMap::getButtonInMap(int button) {
    return _buttonmap.at(button);
}

void buttonMap::setButtonInMap(int button, bool status, bool repeat) {
    _buttonmap[button].first = status;
    _buttonmap[button].second = repeat;
}

void mouseDataPos::initMousePos() {
    _MouseX = 0;
    _MouseY = 0;
}

std::pair<int, int> mouseDataPos::getMousePos() {
    return {_MouseX, _MouseY};
}

void mouseDataPos::setMousePos(int x, int y) {
    _MouseX = x;
    _MouseY = y;
}

}