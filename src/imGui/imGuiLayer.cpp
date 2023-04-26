#define GL_GLEXT_PROTOTYPES

#include <application.hpp>
#include <imGuiLayer.hpp>
#include <imgui_impl_glut.hpp>
#include <imgui_impl_opengl3.hpp>
#include <GL/glext.h>

#include <imgui.h>

static bool show_demo_window = true;
static bool show_another_window = true;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

//juste a faire mon prorpe get time et on glut ingut peux degager

void dg::imGuiLayer::onAttach() {
    IMGUI_CHECKVERSION();
    //ImGuiContext *con = ImGui::CreateContext();
    ImGui::CreateContext();
    //DG_CORE_ERROR("===> {0}", fmt::ptr(con));
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    
    ImGui::StyleColorsDark();
    ImGui_ImplGLUT_Init();
    if (!ImGui_ImplOpenGL3_Init("#version 460"))
        DG_CORE_ERROR("ImGui opengl3 init fail");
}

void dg::imGuiLayer::onDetach() {
//    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();
}

void dg::imGuiLayer::onUpdate() {
    //DG_TRACE("ImGuiOverlay update");
    glUseProgram(0);
    //ImGuiContext *con = ImGui::GetCurrentContext();

    //DG_CORE_ERROR("===> {0}", fmt::ptr(con));
    //ImGui_ImplOpenGL2_NewFrame();
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(getWinPointer(glutGetWindow())->getsizeWidth(), getWinPointer(glutGetWindow())->getsizeHeight());

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGLUT_NewFrame();
    ImGui::NewFrame();

    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);
    if (show_another_window) {
        ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me"))
            show_another_window = false;
        ImGui::End();
        {}
    }
    static float f = 0.0f;
    static int counter = 0;

    ImGui::Begin("Hello, world!");

    ImGui::Text("This is some useful text.");
    ImGui::Checkbox("Demo Window", &show_demo_window);
    ImGui::Checkbox("Another Window", &show_another_window);

    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    ImGui::ColorEdit3("clear color", (float*)&clear_color);

    if (ImGui::Button("Button"))
        counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    ImGui::End();
    ImGui::Render();
    //ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void dg::imGuiLayer::onEvent(event &event) {
    dg::eventDispatcher dispatcher(event);
    
    dispatcher.Dispatch<mouseButtonPressed>(BIND_EVENT_FN(dg::imGuiLayer::onMouseButtonPressed));
    dispatcher.Dispatch<mouseButtonReleased>(BIND_EVENT_FN(dg::imGuiLayer::onMouseButtonReleased));
    dispatcher.Dispatch<mouseScrolled>(BIND_EVENT_FN(dg::imGuiLayer::onMouseScrolled));
    dispatcher.Dispatch<mouseMoved>(BIND_EVENT_FN(dg::imGuiLayer::onMouseMove));
    dispatcher.Dispatch<mouseMovedClick>(BIND_EVENT_FN(dg::imGuiLayer::onMouseMovedClick));
    dispatcher.Dispatch<KeyPressed>(BIND_EVENT_FN(dg::imGuiLayer::onKeyPressed));
    dispatcher.Dispatch<keySpePressed>(BIND_EVENT_FN(dg::imGuiLayer::onKeySpePressed));
    dispatcher.Dispatch<keyReleased>(BIND_EVENT_FN(dg::imGuiLayer::onKeyReleased));
    //dispatcher.Dispatch<onKeyType>(BIND_EVENT_FN(dg::imGuiLayer::onKeytype));
    dispatcher.Dispatch<windowResizEvent>(BIND_EVENT_FN(dg::imGuiLayer::onWindowRezise));
}

static ImGuiKey glutKeyToImGuiKey(int key) {
    switch (key) {
        case '\t':                      return ImGuiKey_Tab;
        case 256 + GLUT_KEY_LEFT:       return ImGuiKey_LeftArrow;
        case 256 + GLUT_KEY_RIGHT:      return ImGuiKey_RightArrow;
        case 256 + GLUT_KEY_UP:         return ImGuiKey_UpArrow;
        case 256 + GLUT_KEY_DOWN:       return ImGuiKey_DownArrow;
        case 256 + GLUT_KEY_PAGE_UP:    return ImGuiKey_PageUp;
        case 256 + GLUT_KEY_PAGE_DOWN:  return ImGuiKey_PageDown;
        case 256 + GLUT_KEY_HOME:       return ImGuiKey_Home;
        case 256 + GLUT_KEY_END:        return ImGuiKey_End;
        case 256 + GLUT_KEY_INSERT:     return ImGuiKey_Insert;
        case 127:                       return ImGuiKey_Delete;
        case 8:                         return ImGuiKey_Backspace;
        case ' ':                       return ImGuiKey_Space;
        case 13:                        return ImGuiKey_Enter;
        case 27:                        return ImGuiKey_Escape;
        case 39:                        return ImGuiKey_Apostrophe;
        case 44:                        return ImGuiKey_Comma;
        case 45:                        return ImGuiKey_Minus;
        case 46:                        return ImGuiKey_Period;
        case 47:                        return ImGuiKey_Slash;
        case 59:                        return ImGuiKey_Semicolon;
        case 61:                        return ImGuiKey_Equal;
        case 91:                        return ImGuiKey_LeftBracket;
        case 92:                        return ImGuiKey_Backslash;
        case 93:                        return ImGuiKey_RightBracket;
        case 96:                        return ImGuiKey_GraveAccent;
        //case 0:                         return ImGuiKey_CapsLock;
        //case 0:                         return ImGuiKey_ScrollLock;
        case 256 + 0x006D:              return ImGuiKey_NumLock;
        //case 0:                         return ImGuiKey_PrintScreen;
        //case 0:                         return ImGuiKey_Pause;
        //case '0':                       return ImGuiKey_Keypad0;
        //case '1':                       return ImGuiKey_Keypad1;
        //case '2':                       return ImGuiKey_Keypad2;
        //case '3':                       return ImGuiKey_Keypad3;
        //case '4':                       return ImGuiKey_Keypad4;
        //case '5':                       return ImGuiKey_Keypad5;
        //case '6':                       return ImGuiKey_Keypad6;
        //case '7':                       return ImGuiKey_Keypad7;
        //case '8':                       return ImGuiKey_Keypad8;
        //case '9':                       return ImGuiKey_Keypad9;
        //case 46:                        return ImGuiKey_KeypadDecimal;
        //case 47:                        return ImGuiKey_KeypadDivide;
        case 42:                        return ImGuiKey_KeypadMultiply;
        //case 45:                        return ImGuiKey_KeypadSubtract;
        case 43:                        return ImGuiKey_KeypadAdd;
        //case 13:                        return ImGuiKey_KeypadEnter;
        //case 0:                         return ImGuiKey_KeypadEqual;
        case 256 + 0x0072:              return ImGuiKey_LeftCtrl;
        case 256 + 0x0070:              return ImGuiKey_LeftShift;
        case 256 + 0x0074:              return ImGuiKey_LeftAlt;
        //case 0:                         return ImGuiKey_LeftSuper;
        case 256 + 0x0073:              return ImGuiKey_RightCtrl;
        case 256 + 0x0071:              return ImGuiKey_RightShift;
        case 256 + 0x0075:              return ImGuiKey_RightAlt;
        //case 0:                         return ImGuiKey_RightSuper;
        //case 0:                         return ImGuiKey_Menu;
        case '0':                       return ImGuiKey_0;
        case '1':                       return ImGuiKey_1;
        case '2':                       return ImGuiKey_2;
        case '3':                       return ImGuiKey_3;
        case '4':                       return ImGuiKey_4;
        case '5':                       return ImGuiKey_5;
        case '6':                       return ImGuiKey_6;
        case '7':                       return ImGuiKey_7;
        case '8':                       return ImGuiKey_8;
        case '9':                       return ImGuiKey_9;
        case 'A': case 'a':             return ImGuiKey_A;
        case 'B': case 'b':             return ImGuiKey_B;
        case 'C': case 'c':             return ImGuiKey_C;
        case 'D': case 'd':             return ImGuiKey_D;
        case 'E': case 'e':             return ImGuiKey_E;
        case 'F': case 'f':             return ImGuiKey_F;
        case 'G': case 'g':             return ImGuiKey_G;
        case 'H': case 'h':             return ImGuiKey_H;
        case 'I': case 'i':             return ImGuiKey_I;
        case 'J': case 'j':             return ImGuiKey_J;
        case 'K': case 'k':             return ImGuiKey_K;
        case 'L': case 'l':             return ImGuiKey_L;
        case 'M': case 'm':             return ImGuiKey_M;
        case 'N': case 'n':             return ImGuiKey_N;
        case 'O': case 'o':             return ImGuiKey_O;
        case 'P': case 'p':             return ImGuiKey_P;
        case 'Q': case 'q':             return ImGuiKey_Q;
        case 'R': case 'r':             return ImGuiKey_R;
        case 'S': case 's':             return ImGuiKey_S;
        case 'T': case 't':             return ImGuiKey_T;
        case 'U': case 'u':             return ImGuiKey_U;
        case 'V': case 'v':             return ImGuiKey_V;
        case 'W': case 'w':             return ImGuiKey_W;
        case 'X': case 'x':             return ImGuiKey_X;
        case 'Y': case 'y':             return ImGuiKey_Y;
        case 'Z': case 'z':             return ImGuiKey_Z;
        case 256 + GLUT_KEY_F1:         return ImGuiKey_F1;
        case 256 + GLUT_KEY_F2:         return ImGuiKey_F2;
        case 256 + GLUT_KEY_F3:         return ImGuiKey_F3;
        case 256 + GLUT_KEY_F4:         return ImGuiKey_F4;
        case 256 + GLUT_KEY_F5:         return ImGuiKey_F5;
        case 256 + GLUT_KEY_F6:         return ImGuiKey_F6;
        case 256 + GLUT_KEY_F7:         return ImGuiKey_F7;
        case 256 + GLUT_KEY_F8:         return ImGuiKey_F8;
        case 256 + GLUT_KEY_F9:         return ImGuiKey_F9;
        case 256 + GLUT_KEY_F10:        return ImGuiKey_F10;
        case 256 + GLUT_KEY_F11:        return ImGuiKey_F11;
        case 256 + GLUT_KEY_F12:        return ImGuiKey_F12;
        default:                        return ImGuiKey_None;
    }
}

static void updateKeyModif() {
    ImGuiIO& io = ImGui::GetIO();
    int glut_key_mods = glutGetModifiers();
    
    io.AddKeyEvent(ImGuiMod_Ctrl, (glut_key_mods & GLUT_ACTIVE_CTRL) != 0);
    io.AddKeyEvent(ImGuiMod_Shift, (glut_key_mods & GLUT_ACTIVE_SHIFT) != 0);
    io.AddKeyEvent(ImGuiMod_Alt, (glut_key_mods & GLUT_ACTIVE_ALT) != 0);
}

static inline int changeMouseButton(int glutButton) {
    switch (glutButton) {
        case GLUT_LEFT_BUTTON:
            return 0;
        case GLUT_RIGHT_BUTTON:
            return 1;
        case GLUT_MIDDLE_BUTTON:
            return 2;
        default:
            return -1;
    }
}

bool dg::imGuiLayer::onMouseButtonPressed(mouseButtonPressed &e) {
    ImGuiIO io = ImGui::GetIO();
    int button = changeMouseButton(e.getButton());
    
    io.AddMousePosEvent(e.getX(), e.getY());
    if (button != -1)
        io.AddMouseButtonEvent(button, false);
    return false;
}

bool dg::imGuiLayer::onMouseButtonReleased(mouseButtonReleased &e) {
    ImGuiIO &io = ImGui::GetIO();
    int button = changeMouseButton(e.getButton());
    
    io.AddMousePosEvent(e.getX(), e.getY());
    if (button != -1)
        io.AddMouseButtonEvent(button, true);
    return false;
}

bool dg::imGuiLayer::onMouseMovedClick(mouseMovedClick &e) {
    ImGuiIO &io = ImGui::GetIO();
    
    io.AddMousePosEvent(e.getX(), e.getY());
    io.AddMouseButtonEvent(0, true);
    return false;
}

bool dg::imGuiLayer::onMouseScrolled(mouseScrolled &e) {
    ImGuiIO& io = ImGui::GetIO();
    float dir;
    
    if (e.getButton() == 3)
        dir = 1.0f;
    else
        dir = -1.0f;
    io.AddMousePosEvent(e.getX(), e.getY());
    io.AddMouseWheelEvent(0.0f, dir);
    return false;
}

static void imGuiKeyEvent(ImGuiKey key, bool down, int native_keycode) {
    ImGuiIO& io = ImGui::GetIO();

    io.AddKeyEvent(key, down);
    io.SetKeyEventNativeData(key, native_keycode, -1);
}


bool dg::imGuiLayer::onMouseMove(mouseMoved &e) {
    ImGuiIO& io = ImGui::GetIO();

    io.AddMousePosEvent(e.getX(), e.getY());
    return false;
}

bool dg::imGuiLayer::onKeyPressed(KeyPressed &e) {
    ImGuiIO& io = ImGui::GetIO();

    if (e.getKey() >= 32)
        io.AddInputCharacter((unsigned int)e.getKey());
    imGuiKeyEvent(glutKeyToImGuiKey(e.getKey()), true, e.getKey());
    updateKeyModif();
    return false;
}

bool dg::imGuiLayer::onKeySpePressed(keySpePressed &e) {
    imGuiKeyEvent(glutKeyToImGuiKey(e.getKey()), true, e.getKey());
    updateKeyModif();
    return false;
}

bool dg::imGuiLayer::onKeyReleased(keyReleased &e) {
    imGuiKeyEvent(glutKeyToImGuiKey(e.getKey()), false, e.getKey());
    updateKeyModif();
    return false;
}

bool dg::imGuiLayer::onKeySpeReleased(keySpeReleased &e) {
    imGuiKeyEvent(glutKeyToImGuiKey(e.getKey()), false, e.getKey());
    updateKeyModif();
    return false;
}

//bool dg::imGuiLayer::onKeyType(keytype &e) {
//
//}

bool dg::imGuiLayer::onWindowRezise(windowResizEvent &e) {
    ImGuiIO& io = ImGui::GetIO();

    io.DisplaySize = ImVec2(e.getWidth(), e.getHeight());
    DG_CORE_ERROR("resize imGui {0} {1}", e.getWidth(), e.getHeight());
    return false;
}