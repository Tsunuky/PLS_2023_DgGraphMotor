#include <application.hpp>

#include <imgui.h>

class exampleLayer: public dg::layer {
public:
    exampleLayer(): layer("example") {}
public:
    void onUpdate() override {
        if (dg::input::isKeyPress(DG_KEY_TAB))
            DG_INFO("tab press in sand box");
        //DG_INFO("exampleLayer: update");
    }
    void onImguiRender() {
        ImGui::Begin("test");
        ImGui::Text("Hello neko !");
        ImGui::End();
    }
    void onEvent(dg::event &e) override {
        (void)e;
        //DG_TRACE(e.toString());
    }
};

class sandbox: public dg::application {
public:
    sandbox(): application() {
        pushLayer(new exampleLayer());
    }
    ~sandbox() = default;
};

inline dg::application *createApplication() {
    return new sandbox();
}