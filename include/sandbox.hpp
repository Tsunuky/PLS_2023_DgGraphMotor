#include <application.hpp>

class exampleLayer: public dg::layer {
public:
    exampleLayer(): layer("example") {}
public:
    void onUpdate() override {
        DG_INFO("exampleLayer: update");
    }
    void onEvent(dg::event &e) override {
        DG_TRACE(e.toString());
    }
};

class sandbox: public application {
public:
    sandbox() {
        pushLayer(new exampleLayer());
    }
    ~sandbox() = default;
};

inline application *createApplication() {
    return new sandbox();
}