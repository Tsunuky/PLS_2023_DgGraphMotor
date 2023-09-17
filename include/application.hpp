#pragma once

#include <log.hpp>

//#include <glad/glad.hpp>
#include <OpenGL/OpenGLShader.hpp>

#include <eventApplication.hpp>
#include <window_gl.hpp>
#include <layerStack.hpp>
#include <imGui/imGuiLayer.hpp>
#include <renderer/buffer.hpp>
#include <renderer/orthographiCamera.hpp>
#include <core/timeStep.hpp>

#define BIND_EVENT_FN(x) std::bind_front(&x, this)

namespace dg {
struct appliSpecification {
    std::string Name = "Doggo Application";
    std::string WorkingDirectory;
};


class application {
public:
    application(std::string name = "Window") {
        dg::log::init();
    
        // mettre ca dans init
        dg::keyMap::initKeymap();
        dg::buttonMap::initButtonmap();
        
        DG_CORE_ASSERT(!_instance, "Application already exist");
        _instance = this;
        _win.reset(dg::window_API::create(dg::window(name)));
        _win->setEventCallback(BIND_EVENT_FN(application::onEvent));
        //_win->setVsync(false);
        _imguiLayer = new imGuiLayer();
        pushOverlay(_imguiLayer);

        /*
        _vertexArray.reset(vertexArray::create());

        // tmp la pour test
        std::string vertexshader = R"(
            #version 440 core
            #pragma debug(on)
            
            layout(location = 0) in vec3 position;
            layout(location = 1) in vec4 color;
            
            uniform mat4 u_viewProjection;

            out vec3 v_Position;
            out vec4 v_color;
            
            void main() {
                v_Position = position;
                v_color = color;
                gl_Position = u_viewProjection * vec4(position, 1.0);
            }
        )";

        std::string fragmentshader = R"(
            #version 440 core
            #pragma debug(on)
            
            layout(location = 0) out vec4 color;
            
            in vec3 v_Position;
            in vec4 v_color;

            void main() {
                color = vec4(v_Position * 0.5 + 0.5, 1.0);
                color = v_color;
            }
        )";

        u_int indices[3] = {0, 1, 2};

        _squareVertexArray.reset(vertexArray::create());

        std::string vshader = R"(
            #version 440 core
            #pragma debug(on)
            
            layout(location = 0) in vec3 position;

            uniform mat4 u_viewProjection;

            out vec3 v_Position;
            
            void main() {
                v_Position = position;
                gl_Position = u_viewProjection * vec4(position, 1.0);
            }
        )";

        std::string fshader = R"(
            #version 440 core
            #pragma debug(on)
            
            layout(location = 0) out vec4 color;

            in vec3 v_Position;

            void main() {
                color = vec4(0.2, 0.3, 0.8, 1.0);
            }
        )";

        _shader2.reset(new shaderOpenGL(vshader, fshader));

        float vertices[3*7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };
        float vertices2[4*3] = {
            -0.75f, -0.75f, 0.0f,
             0.75f, -0.75f, 0.0f,
             0.75f,  0.75f, 0.0f,
            -0.75f,  0.75f, 0.0f
        };

        std::shared_ptr<vertexBuffer> square;
        square.reset(vertexBuffer::create(vertices2, sizeof(vertices2)));
        square->setLayout({
            {shaderDataType::Float3, "a_position"}
        });
        _squareVertexArray->addVertexBuffer(square);
        u_int sqindices[6] = {0, 1, 2, 2, 3, 0};
        std::shared_ptr<indexBuffer> sqaure_ib;
        sqaure_ib.reset(indexBuffer::create(sqindices, sizeof(sqindices)/ sizeof(u_int32_t)));
        _squareVertexArray->setIndexBuffer(sqaure_ib);

        _shader.reset(new shaderOpenGL(vertexshader, fragmentshader));

        _vertexBuffer.reset(vertexBuffer::create(vertices, sizeof(vertices)));
        bufferLayout layout = {
            {shaderDataType::Float3, "a_Position"},
            {shaderDataType::Float4, "a_Color"}
        };

        _vertexBuffer->setLayout(layout);
        _vertexArray->addVertexBuffer(_vertexBuffer);

        _indexBuffer.reset(indexBuffer::create(indices, sizeof(indices) / sizeof (u_int32_t)));
        _vertexArray->setIndexBuffer(_indexBuffer);
        //tmp pour le test
        */
    };
    virtual ~application() {};
public:
    application *createApplication();
public:
    void onEvent(dg::event &e);
    void run();
    bool onEventClose(dg::windowCloseEvent &e);
    void pushLayer(dg::layer *layer);
    void pushOverlay(dg::layer *overlay);
public:
    inline static application &get() {return *_instance;}
    inline dg::window_API &getWindow() {return *_win;};
private:
    std::shared_ptr<dg::window_API> _win;

    //std::shared_ptr<vertexBuffer> _vertexBuffer;
    //std::shared_ptr<indexBuffer> _indexBuffer;
    
    imGuiLayer *_imguiLayer;
    dg::layerStack _layerStack;
    static application *_instance;
    float _lastFrameTime = 0.0f;
    bool isRunning = true;
};

inline application *application::_instance = nullptr;

}