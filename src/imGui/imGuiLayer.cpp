#include <application.hpp>
#include <imGuiLayer.hpp>

#include <imgui.h>

#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

#include <imgui_internal.h>

#define GL_SILENCE_DEPRECATION

void dg::imGuiLayer::onAttach() {
    application &app = application::get();
    GLFWwindow *window = static_cast<GLFWwindow*>(app.getWindow().getNativeWindow());

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    if (!ImGui_ImplOpenGL3_Init("#version 430"))
        DG_CORE_ERROR("ImGui opengl3 init fail");
}

void dg::imGuiLayer::onDetach() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void dg::imGuiLayer::begin() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void dg::imGuiLayer::end() {
    application &app = application::get();
    ImGuiIO& io = ImGui::GetIO();

    io.DisplaySize = ImVec2(app.getWindow().getsizeWidth(), app.getWindow().getsizeHeight());
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glUseProgram(0);

    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
}

void dg::imGuiLayer::onImguiRender() {
    static bool show = true;
    ImGui::ShowDemoWindow(&show);
}
//

/*
void dg::imGuiLayer::onEvent(event &event) {
    dg::eventDispatcher dispatcher(event);


    dispatcher.Dispatch<mouseButtonReleased>(BIND_EVENT_FN(dg::imGuiLayer::onMouseButtonReleased));
    dispatcher.Dispatch<mouseButtonPressed>(BIND_EVENT_FN(dg::imGuiLayer::onMouseButtonPressed));
    dispatcher.Dispatch<windowResizEvent>(BIND_EVENT_FN(dg::imGuiLayer::onWindowRezise));
    dispatcher.Dispatch<mouseScrolled>(BIND_EVENT_FN(dg::imGuiLayer::onMouseScrolled));
    dispatcher.Dispatch<keyReleased>(BIND_EVENT_FN(dg::imGuiLayer::onKeyReleased));
    dispatcher.Dispatch<KeyPressed>(BIND_EVENT_FN(dg::imGuiLayer::onKeyPressed));
    dispatcher.Dispatch<mouseMoved>(BIND_EVENT_FN(dg::imGuiLayer::onMouseMove));
    dispatcher.Dispatch<keyType>(BIND_EVENT_FN(dg::imGuiLayer::onKeyType));
}

static ImGuiKey glgwtKeyToImGuiKey(int key) {
   switch (key) {
        case GLFW_KEY_TAB: return ImGuiKey_Tab;
        case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;
        case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;
        case GLFW_KEY_UP: return ImGuiKey_UpArrow;
        case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;
        case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;
        case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
        case GLFW_KEY_HOME: return ImGuiKey_Home;
        case GLFW_KEY_END: return ImGuiKey_End;
        case GLFW_KEY_INSERT: return ImGuiKey_Insert;
        case GLFW_KEY_DELETE: return ImGuiKey_Delete;
        case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;
        case GLFW_KEY_SPACE: return ImGuiKey_Space;
        case GLFW_KEY_ENTER: return ImGuiKey_Enter;
        case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;
        case GLFW_KEY_APOSTROPHE: return ImGuiKey_Apostrophe;
        case GLFW_KEY_COMMA: return ImGuiKey_Comma;
        case GLFW_KEY_MINUS: return ImGuiKey_Minus;
        case GLFW_KEY_PERIOD: return ImGuiKey_Period;
        case GLFW_KEY_SLASH: return ImGuiKey_Slash;
        case GLFW_KEY_SEMICOLON: return ImGuiKey_Semicolon;
        case GLFW_KEY_EQUAL: return ImGuiKey_Equal;
        case GLFW_KEY_LEFT_BRACKET: return ImGuiKey_LeftBracket;
        case GLFW_KEY_BACKSLASH: return ImGuiKey_Backslash;
        case GLFW_KEY_RIGHT_BRACKET: return ImGuiKey_RightBracket;
        case GLFW_KEY_GRAVE_ACCENT: return ImGuiKey_GraveAccent;
        case GLFW_KEY_CAPS_LOCK: return ImGuiKey_CapsLock;
        case GLFW_KEY_SCROLL_LOCK: return ImGuiKey_ScrollLock;
        case GLFW_KEY_NUM_LOCK: return ImGuiKey_NumLock;
        case GLFW_KEY_PRINT_SCREEN: return ImGuiKey_PrintScreen;
        case GLFW_KEY_PAUSE: return ImGuiKey_Pause;
        case GLFW_KEY_KP_0: return ImGuiKey_Keypad0;
        case GLFW_KEY_KP_1: return ImGuiKey_Keypad1;
        case GLFW_KEY_KP_2: return ImGuiKey_Keypad2;
        case GLFW_KEY_KP_3: return ImGuiKey_Keypad3;
        case GLFW_KEY_KP_4: return ImGuiKey_Keypad4;
        case GLFW_KEY_KP_5: return ImGuiKey_Keypad5;
        case GLFW_KEY_KP_6: return ImGuiKey_Keypad6;
        case GLFW_KEY_KP_7: return ImGuiKey_Keypad7;
        case GLFW_KEY_KP_8: return ImGuiKey_Keypad8;
        case GLFW_KEY_KP_9: return ImGuiKey_Keypad9;
        case GLFW_KEY_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
        case GLFW_KEY_KP_DIVIDE: return ImGuiKey_KeypadDivide;
        case GLFW_KEY_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
        case GLFW_KEY_KP_SUBTRACT: return ImGuiKey_KeypadSubtract;
        case GLFW_KEY_KP_ADD: return ImGuiKey_KeypadAdd;
        case GLFW_KEY_KP_ENTER: return ImGuiKey_KeypadEnter;
        case GLFW_KEY_KP_EQUAL: return ImGuiKey_KeypadEqual;
        case GLFW_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
        case GLFW_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
        case GLFW_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
        case GLFW_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;
        case GLFW_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
        case GLFW_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
        case GLFW_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
        case GLFW_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;
        case GLFW_KEY_MENU: return ImGuiKey_Menu;
        case GLFW_KEY_0: return ImGuiKey_0;
        case GLFW_KEY_1: return ImGuiKey_1;
        case GLFW_KEY_2: return ImGuiKey_2;
        case GLFW_KEY_3: return ImGuiKey_3;
        case GLFW_KEY_4: return ImGuiKey_4;
        case GLFW_KEY_5: return ImGuiKey_5;
        case GLFW_KEY_6: return ImGuiKey_6;
        case GLFW_KEY_7: return ImGuiKey_7;
        case GLFW_KEY_8: return ImGuiKey_8;
        case GLFW_KEY_9: return ImGuiKey_9;
        case GLFW_KEY_A: return ImGuiKey_A;
        case GLFW_KEY_B: return ImGuiKey_B;
        case GLFW_KEY_C: return ImGuiKey_C;
        case GLFW_KEY_D: return ImGuiKey_D;
        case GLFW_KEY_E: return ImGuiKey_E;
        case GLFW_KEY_F: return ImGuiKey_F;
        case GLFW_KEY_G: return ImGuiKey_G;
        case GLFW_KEY_H: return ImGuiKey_H;
        case GLFW_KEY_I: return ImGuiKey_I;
        case GLFW_KEY_J: return ImGuiKey_J;
        case GLFW_KEY_K: return ImGuiKey_K;
        case GLFW_KEY_L: return ImGuiKey_L;
        case GLFW_KEY_M: return ImGuiKey_M;
        case GLFW_KEY_N: return ImGuiKey_N;
        case GLFW_KEY_O: return ImGuiKey_O;
        case GLFW_KEY_P: return ImGuiKey_P;
        case GLFW_KEY_Q: return ImGuiKey_Q;
        case GLFW_KEY_R: return ImGuiKey_R;
        case GLFW_KEY_S: return ImGuiKey_S;
        case GLFW_KEY_T: return ImGuiKey_T;
        case GLFW_KEY_U: return ImGuiKey_U;
        case GLFW_KEY_V: return ImGuiKey_V;
        case GLFW_KEY_W: return ImGuiKey_W;
        case GLFW_KEY_X: return ImGuiKey_X;
        case GLFW_KEY_Y: return ImGuiKey_Y;
        case GLFW_KEY_Z: return ImGuiKey_Z;
        case GLFW_KEY_F1: return ImGuiKey_F1;
        case GLFW_KEY_F2: return ImGuiKey_F2;
        case GLFW_KEY_F3: return ImGuiKey_F3;
        case GLFW_KEY_F4: return ImGuiKey_F4;
        case GLFW_KEY_F5: return ImGuiKey_F5;
        case GLFW_KEY_F6: return ImGuiKey_F6;
        case GLFW_KEY_F7: return ImGuiKey_F7;
        case GLFW_KEY_F8: return ImGuiKey_F8;
        case GLFW_KEY_F9: return ImGuiKey_F9;
        case GLFW_KEY_F10: return ImGuiKey_F10;
        case GLFW_KEY_F11: return ImGuiKey_F11;
        case GLFW_KEY_F12: return ImGuiKey_F12;
        default: return ImGuiKey_None;
    }
}

/*
static ImGuiContext* imguiBackendData()
{
    return ImGui::GetCurrentContext() ? (ImGuiContext*)ImGui::GetIO().BackendPlatformUserData : nullptr;
}

static bool ImGui_ImplGlfw_ShouldChainCallback(GLFWwindow* window)
{
    (void)window;
    //ImGuiContext* bd = imguiBackendData();
    //return bd->CallbacksChainForAllWindows ? true : (window == bd->Window);
    return false;
}

bool dg::imGuiLayer::onMouseButtonPressed(mouseButtonPressed &e) {
    ImGuiIO &io = ImGui::GetIO();
    int button = e.getButton();
    
    //io.AddMousePosEvent(e.getX(), e.getY());
    io.AddMouseButtonEvent(button, true);
    return false;
}

bool dg::imGuiLayer::onMouseButtonReleased(mouseButtonReleased &e) {
    ImGuiIO &io = ImGui::GetIO();
    int button = e.getButton();
    
    //io.AddMousePosEvent(e.getX(), e.getY());
    io.AddMouseButtonEvent(button, false);
    return false;
}

bool dg::imGuiLayer::onMouseScrolled(mouseScrolled &e) {
    ImGuiIO &io = ImGui::GetIO();

    io.AddMouseWheelEvent(e.getX(), e.getY());
    return false;
}

static void imGuiKeyEvent(ImGuiKey key, bool down, int native_keycode) {
    ImGuiIO &io = ImGui::GetIO();

    io.AddKeyEvent(key, down);
    io.SetKeyEventNativeData(key, native_keycode, -1);
}


bool dg::imGuiLayer::onMouseMove(mouseMoved &e) {
    ImGuiIO &io = ImGui::GetIO();

    io.AddMousePosEvent(e.getX(), e.getY());
    return false;
}

bool dg::imGuiLayer::onKeyPressed(KeyPressed &e) {
    ImGuiIO &io = ImGui::GetIO();

    if (e.getKey() >= 32)
        io.AddInputCharacter((unsigned int)e.getKey());
    imGuiKeyEvent(glgwtKeyToImGuiKey(e.getKey()), true, e.getNativeCode());

    io.AddKeyEvent(ImGuiMod_Ctrl, (e.getKey() == GLFW_KEY_LEFT_CONTROL || e.getKey() == GLFW_KEY_RIGHT_CONTROL) ? GLFW_TRUE : GLFW_FALSE);
    io.AddKeyEvent(ImGuiMod_Shift, (e.getKey() ==  GLFW_KEY_LEFT_SHIFT || e.getKey() == GLFW_KEY_RIGHT_SHIFT) ? GLFW_TRUE : GLFW_FALSE);
    io.AddKeyEvent(ImGuiMod_Super, (e.getKey() == GLFW_KEY_LEFT_SUPER || e.getKey() == GLFW_KEY_RIGHT_SUPER) ? GLFW_TRUE : GLFW_FALSE);
    io.AddKeyEvent(ImGuiMod_Alt,  (e.getKey() == GLFW_KEY_LEFT_ALT || e.getKey() == GLFW_KEY_RIGHT_ALT) ? GLFW_TRUE : GLFW_FALSE);

    return false;
}

bool dg::imGuiLayer::onKeyReleased(keyReleased &e) {
    imGuiKeyEvent(glgwtKeyToImGuiKey(e.getKey()), false, e.getNativeCode());
    return false;
}

bool dg::imGuiLayer::onKeyType(keyType &e) {
    ImGuiIO &io = ImGui::GetIO();
    io.AddInputCharacter(e.getKeyType());
    return false;
}

bool dg::imGuiLayer::onWindowRezise(windowResizEvent &e) {
    ImGuiIO& io = ImGui::GetIO();

    io.DisplaySize = ImVec2(e.getWidth(), e.getHeight());
    glViewport(0, 0, e.getWidth(), e.getHeight());
    DG_CORE_ERROR("resize imGui {0} {1}", e.getWidth(), e.getHeight());
    return false;
}
*/