#pragma once

#include <GLFW/glfw3.h>
#include <window.hpp>

#include <log.hpp>
namespace dg {
class window_GL: public window_API {
public:
    struct winData {
        std::string title;
        u_int width;
        u_int height;
        bool sync;

        eventCallbackFn eventCallback;
    };
public:
    window_GL(const window &props) {
        _data.title = props._name;
        _data.width = props._sw;
        _data.height = props._sh;
        _data.sync = false;
        initWindow();
    };
    ~window_GL() = default;
public:
    void initWindow();
    void setOrtho();
public:
    void clearColor(const dg::rgba &);
    void scalePixel(float);
    void setVsync(bool enabled) override;
    void onUpdate() override;
    void setEventCallback(const eventCallbackFn &callback) override {_data.eventCallback = callback;};
    void reshape(int width, int height) {_data.height = height; _data.width = width;};
public:
    inline u_int getsizeWidth() const override {return this->_data.width;};
    inline u_int getsizeHeight() const override {return this->_data.height;};
    inline bool isVsync() const override {return this->_data.sync;};
    inline winData &getWinData() {return _data;};
    inline dg::layerStack *getLayerStack() {return _layerStack;};
private:
    void setCallback();
private:
    dg::layerStack *_layerStack;
    GLFWwindow* _window;
    winData _data; //peux faire un unique aui fait un suer pointeur
};

struct winUser {
    window_GL *currentWin;
    void *data;
    int id;
};

inline winUser _winUser{NULL, NULL, 0};

void setWinUserPointer(int id, void *pointer);
void setWinPointer(int id, dg::window_GL *pointer);
dg::window_GL *getWinPointer(int id);
void *getUserWinPointer(int id);
}