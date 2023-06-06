#define GL_GLEXT_PROTOTYPES

#include <GLFW/glfw3.h>
#include <GL/glx.h>
//#include <GL/glext.h>
//#include <GL/freeglut.h>
//#include <GL/freeglut_std.h>
//#include <GL/glut.h>

#include <window_gl.hpp>
#include <shader.hpp>
#include <core.hpp>
#include <log.hpp>

//dg::core *dgCorePtr;
//dg::window_GL *currentWin;

// a regrader pour se faire une lib math
//#include <emmintrin.h>

std::string vertexshader =
    "#version 440 core\n"
    "#pragma debug(on)\n"
    "layout(location = 0) in vec4 position;\n"
    "\n"
    "void main()\n" 
    "{\n"
    "gl_Position = position;\n"
    "}\n";

std::string fragmentshader =
    "#version 440 core\n"
    "#pragma debug(on)\n"
    "layout(location = 0) out vec4 color;\n"
    "\n"
    "void main()\n"
    "{\n"
    "color = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";

float position[6] = { //test
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f,  -0.5f
};
 

 // shader lek memory ne pas creer a chaque fois ou trouver comment les free

/*void dg::core::display() {
    //dg::shader shad(vertexshader, fragmentshader);
    //glUseProgram(shad.getShader());
    glDrawArrays(GL_TRIANGLES, 0, 3);//test

}*/

/*void dg::core::idleDisplay() {
    //dg::shader shad(vertexshader, fragmentshader);
    //glUseProgram(shad.getShader());
    glDrawArrays(GL_TRIANGLES, 0, 3);//test
    for (layer *layer: *getWinPointer(glutGetWindow())->getLayerStack()) {
        //DG_TRACE(layer->getName());
        layer->onUpdate();
    }
}*/

void dg::setCorePointer(core *pointer) {
    _coreUser.pointer = pointer;
}

dg::core *dg::getCorePointer() {
    return dg::_coreUser.pointer;
}

/*void dg::window_GL::run(layerStack *stack, bool debug) {
    dg::core dgcore(debug);

    _layerStack = stack;
    dg::setCorePointer(&dgcore);
    //dgCorePtr = &dgcore;
    //dg::getCorePointer()->glutAllInit(argc, argv);
    if (debug)
        DG_CORE_INFO((char *)glGetString(GL_VERSION));
    //glfwSetWindowUserPointer();
    //dg::getCorePointer()->setWin(glutGetWindow());
    //dg::setWinPointer(glutGetWindow(), this);
    //dg::getCorePointer()->initGlutCallback();
}*/

void dg::core::checkDevice() {
    /*if (glutDeviceGet(GLUT_HAS_KEYBOARD))
        DG_CORE_INFO("Keyboard was found !");
    else
        DG_CORE_WARN("No keyboard was found !");
    if (glutDeviceGet(GLUT_HAS_MOUSE))
        DG_CORE_INFO("Mouse with {0} button was found !", glutDeviceGet(GLUT_NUM_MOUSE_BUTTONS));
    else
        DG_CORE_WARN("No mouse was found !");
    DG_CORE_WARN("check button box {0}", glutDeviceGet(GLUT_NUM_BUTTON_BOX_BUTTONS));
    DG_CORE_WARN("check tablet button {0}", glutDeviceGet(GLUT_NUM_TABLET_BUTTONS));
    DG_CORE_WARN("check dial {0}", glutDeviceGet(GLUT_NUM_DIALS));
    DG_CORE_WARN("check joystick {0}", glutDeviceGet(GLUT_HAS_JOYSTICK));
    DG_CORE_WARN("check axes joystick {0}", glutDeviceGet(GLUT_JOYSTICK_AXES));
    DG_CORE_WARN("check button joystick {0}", glutDeviceGet(GLUT_JOYSTICK_BUTTONS));
    */
}

void dg::core::glAllInit() {
    //glutInit(&argc, argv);
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable (GL_DEBUG_OUTPUT);
    //checkDevice();
}

/*static void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    dg::getCorePointer()->display();
    glutSwapBuffers();
    glutPostRedisplay();
}

static void idleRender() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    dg::getCorePointer()->idleDisplay();
    glutSwapBuffers();
    glutPostRedisplay();
}*/

/*
//mettre en place pour la fenetre actuelle et decouper
static void mousseClick(int button, int state, int x, int y) {
    //DG_CORE_INFO("button use {0} state  {1} x: {2}, y: {3}", button, state, x, y);
    if ((button == 3 || button == 4) && state == 1) {
        dg::mouseScrolled event(button, x, y);
        //dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
    } else if ((button == 3 || button == 4) && state == 0) {
        dg::buttonMap::setButtonInMap(button, false);
    } else if (state == 1) {
        dg::mouseButtonPressed event(button, x, y);
        dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
    } else if (state == 0 && button != 3 && button != 4) {
        dg::mouseButtonReleased event(button, x, y);
        dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
    }
}*/

/*static void mousseMove(int x, int y) {
    //DG_CORE_INFO("move x: {0}, y: {1}", x, y);
    dg::mouseMovedClick event(x, y);
    dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
}*/

/*static void moussePassivMove(int x, int y) {
    //DG_CORE_INFO("passiv move x: {0}, y: {1}", x, y);
    dg::mouseMoved event(x, y);
    dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
}*/

/*static void reshape(int width, int height) {
    //DG_CORE_INFO("reshape width: {0}, height: {1}", width, height);
    dg::getWinPointer(glutGetWindow())->reshape(width, height); // a bouger
    glutReshapeWindow(width, height);
    dg::windowResizEvent event(width, height);
    dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
    //currentWin->getWinData().eventCallback(event);
}*/

/*static void entry(int state) {
    //DG_CORE_INFO("state: {0}", state);
    if (state == 1) {
        // surement a depacer
        dg::getCorePointer()->setWin(glutGetWindow());
        glutSetWindow(dg::getCorePointer()->getWin());
        //
        dg::windowFocus event;
        dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
    } else {
        dg::windowLostFocus event;
        dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
    }
}*/

/*static void keyboard(unsigned char key, int x, int y) {
    //DG_CORE_INFO("key: {0} pos (x:{1} y:{2})", key, x, y);
    dg::KeyPressed event(key, x, y);
    dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
    //if (key == 113)
    //    glutCreateSubWindow(dg::getCorePointer()->getWin(), 200/dg::getCorePointer()->getWin(), 200/dg::getCorePointer()->getWin(), 256/dg::getCorePointer()->getWin(), 256/dg::getCorePointer()->getWin());
    //dg::getCorePointer()->initGlutCallback();
    //glutMainLoop();
    //if (key == 27)
    //    glutDestroyWindow(dg::getCorePointer()->getWin());
}*/

/*static void keyboardSpe(int key, int x, int y) {
    //DG_CORE_INFO("Spekey: {0} pos (x:{1} y:{2})", key, x, y);
    dg::keySpePressed event(key, x, y);
    dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
}*/

/*static void keyboardSpeUp(int key, int x, int y) {
    //DG_CORE_INFO("Up Spekey: {0} pos (x:{1} y:{2})", key, x, y);
    dg::keySpeReleased event(key, x, y);
    dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
}*/

/*static void windowStatus(int state) {
    //DG_CORE_INFO("WindowStatus: {0}", state); // id window
    dg::windowId event(state);
    dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
}*/

/*static void windowClose() {
    //DG_CORE_WARN("WindowClose");
    dg::windowCloseEvent event;
    dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);
}*/

/*static void keyboardUp(unsigned char key, int x, int y) {
    //DG_CORE_INFO("Up key: {0} pos (x:{1} y:{2})", key, x, y);
    dg::keyReleased event(key, x, y);
    dg::getWinPointer(glutGetWindow())->getWinData().eventCallback(event);

    //a bouger
    if (key == 27)
        exit(0);
}*/
/*
// a faire plus tard
static void joystick(u_int ButtonMask, int x, int y, int z) {
    DG_CORE_INFO("joystick: mask {0} x {1} y {2} z {3}", ButtonMask, x, y, z);
}*/

void MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam) {
    (void)source; (void)id; (void)length; (void)userParam;
    DG_CORE_ERROR("GL CALLBACK: {0} type = 0x{1}, severity = 0x{2}, message = {3}\n", (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "") , type, severity, message);
}

void dg::core::initGlutCallback() {
    u_int buffer; //test

    glEnableVertexAttribArray(0);//test
    glGenBuffers(1, &buffer);//test
    glBindBuffer(GL_ARRAY_BUFFER, buffer);//test
    glBufferData(GL_ARRAY_BUFFER, 6 *sizeof(float), position, GL_STATIC_DRAW);//test
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);//test

    //glutDisplayFunc(render);
    //glutIdleFunc(idleRender);
    //glutKeyboardFunc(keyboard);
    //glutKeyboardUpFunc(keyboardUp);
    //glutSpecialFunc(keyboardSpe);
    //glutSpecialUpFunc(keyboardSpeUp);
    //glutEntryFunc(entry);
    //glutReshapeFunc(reshape);
    //glutMouseFunc(mousseClick);
    //glutMotionFunc(mousseMove);
    //glutPassiveMotionFunc(moussePassivMove);
    //glutWindowStatusFunc(windowStatus);
    //glutCloseFunc(windowClose);
    glDebugMessageCallback(MessageCallback, 0);

    //glutJoystickFunc(joystick, 200);
}