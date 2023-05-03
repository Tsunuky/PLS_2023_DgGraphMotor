#include <GL/freeglut.h>
#include <cstdio>

#include <inputLinux.hpp>

namespace dg {

input *input::_instance = new linuxInput();

bool linuxInput::isKeyPressImpl(int keycode) {
    return keyMap::getKeyInMap(keycode);
}

bool linuxInput::isButtonPressImpl(int button) {
    return buttonMap::getButtonInMap(button);
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
        _keymap.emplace(i, false);
    }
    _keymap.emplace(256 + GLUT_KEY_PAGE_DOWN, false);
    _keymap.emplace(256 + GLUT_KEY_PAGE_UP, false);
    _keymap.emplace(256 + GLUT_KEY_INSERT, false);
    _keymap.emplace(256 + GLUT_KEY_RIGHT, false);
    _keymap.emplace(256 + GLUT_KEY_DOWN, false);
    _keymap.emplace(256 + GLUT_KEY_HOME, false);
    _keymap.emplace(256 + GLUT_KEY_LEFT, false);
    _keymap.emplace(256 + GLUT_KEY_END, false);
    _keymap.emplace(256 + GLUT_KEY_UP, false);


    _keymap.emplace(256 + GLUT_KEY_F1, false);
    _keymap.emplace(256 + GLUT_KEY_F2, false);
    _keymap.emplace(256 + GLUT_KEY_F3, false);
    _keymap.emplace(256 + GLUT_KEY_F4, false);
    _keymap.emplace(256 + GLUT_KEY_F5, false);
    _keymap.emplace(256 + GLUT_KEY_F6, false);
    _keymap.emplace(256 + GLUT_KEY_F7, false);
    _keymap.emplace(256 + GLUT_KEY_F8, false);
    _keymap.emplace(256 + GLUT_KEY_F9, false);
    _keymap.emplace(256 + GLUT_KEY_F10, false);
    _keymap.emplace(256 + GLUT_KEY_F11, false);
    _keymap.emplace(256 + GLUT_KEY_F12, false);
}

bool keyMap::getKeyInMap(int keycode) {
    return _keymap.at(keycode);
}

void keyMap::setKeyInMap(int keycode, bool status) {
    _keymap[keycode] = status;
}

//faire par rapport au button get par glut
void buttonMap::initButtonmap() {
    for (size_t i = 0; i != 12; i++) {
        _buttonmap.emplace(i, false);
    }
}

bool buttonMap::getButtonInMap(int button) {
    return _buttonmap.at(button);
}

void buttonMap::setButtonInMap(int button, bool status) {
    _buttonmap[button] = status;
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