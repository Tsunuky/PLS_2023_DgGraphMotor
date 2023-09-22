#include <application.hpp>

#include <imgui.h>
#include <renderer/renderCommand.hpp>
#include <renderer/orthographiCamera.hpp>
#include <renderer/vertexArray.hpp>
#include <renderer/renderer.hpp>
#include <renderer/buffer.hpp>
#include <core/timeStep.hpp>

#include <OpenGL/OpenGLShader.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <GL/gl.h>

class exampleLayer: public dg::layer {
public:
    exampleLayer()
    : layer("example"), _camera(-1.6f, 1.6f, -0.9f, 0.9f), _cameraPosition(0.0f), _squarePosition(0.0f) {
        std::string vertexshader = R"(
            #version 440 core
            #pragma debug(on)
            
            layout(location = 0) in vec3 position;
            layout(location = 1) in vec4 color;
            
            uniform mat4 u_viewProjection;
            uniform mat4 u_transform;

            out vec3 v_Position;
            out vec4 v_color;
            
            void main() {
                v_Position = position;
                v_color = color;
                gl_Position = u_viewProjection * u_transform * vec4(position, 1.0);
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

        _squareVertexArray.reset(dg::vertexArray::create());

        std::string vshader = R"(
            #version 440 core
            #pragma debug(on)
            
            layout(location = 0) in vec3 position;

            uniform mat4 u_viewProjection;
            uniform mat4 u_transform;

            out vec3 v_Position;
            
            void main() {
                v_Position = position;
                gl_Position = u_viewProjection * u_transform * vec4(position, 1.0);
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

        _vertexArray.reset(dg::vertexArray::create());

        _shader2.reset(new dg::shaderOpenGL(vshader, fshader));

        float vertices[3*7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };
        float vertices2[4*3] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
        };

        std::shared_ptr<dg::vertexBuffer> square;
        square.reset(dg::vertexBuffer::create(vertices2, sizeof(vertices2)));
        square->setLayout({
            {dg::shaderDataType::Float3, "a_position"}
        });
        _squareVertexArray->addVertexBuffer(square);
        u_int sqindices[6] = {0, 1, 2, 2, 3, 0};
        std::shared_ptr<dg::indexBuffer> sqaure_ib;
        sqaure_ib.reset(dg::indexBuffer::create(sqindices, sizeof(sqindices)/ sizeof(u_int32_t)));
        _squareVertexArray->setIndexBuffer(sqaure_ib);

        _shader.reset(new dg::shaderOpenGL(vertexshader, fragmentshader));

        std::shared_ptr<dg::vertexBuffer> _vertexBuffer;
        _vertexBuffer.reset(dg::vertexBuffer::create(vertices, sizeof(vertices)));
        dg::bufferLayout layout = {
            {dg::shaderDataType::Float3, "a_Position"},
            {dg::shaderDataType::Float4, "a_Color"}
        };

        _vertexBuffer->setLayout(layout);

        _vertexArray->addVertexBuffer(_vertexBuffer);

        std::shared_ptr<dg::indexBuffer> _indexBuffer;
        _indexBuffer.reset(dg::indexBuffer::create(indices, sizeof(indices) / sizeof (u_int32_t)));
        _vertexArray->setIndexBuffer(_indexBuffer);
        torus(0.5, 2, 64, 64);
        //tmp pour le test        
    }
public:
    void onUpdate(dg::timeStep ts) override {
        //DG_TRACE("Delta time {0}", ts.getSeconds());
        if (dg::input::whileKeyPress(DG_KEY_LEFT))
            _cameraPosition.x += _cameraMoveSpeed * ts;
        if (dg::input::whileKeyPress(DG_KEY_RIGHT))
            _cameraPosition.x -= _cameraMoveSpeed * ts;
        if (dg::input::whileKeyPress(DG_KEY_DOWN))
            _cameraPosition.y += _cameraMoveSpeed * ts;
        if (dg::input::whileKeyPress(DG_KEY_UP))
            _cameraPosition.y -= _cameraMoveSpeed * ts;
        if (dg::input::whileKeyPress(DG_KEY_A))
            _cameraRotation -= _cameraRotationSpeed * ts;
        if (dg::input::whileKeyPress(DG_KEY_D))
            _cameraRotation += _cameraRotationSpeed * ts;
        //DG_INFO("exampleLayer: update");
        dg::renderCommand::setClearColor({0.1f, 0.1f, 0.1f, 1});
        dg::renderCommand::clear();
        
        _camera.setPosition(_cameraPosition);
        _camera.setRotation(_cameraRotation);

        dg::renderer::beginScene(_camera); // add camera, light and environement
        
        glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

        for (size_t y = 0; y < 20; y++) {
            for (size_t x = 0; x < 20; x++) {
                glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
                glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
                dg::renderer::submit(_shader2 , _squareVertexArray, transform); // overload pour send mesh ou vertex array
            }
        }
        dg::renderer::submit(_shader , _vertexArray); // overload pour send mesh ou vertex array
        geonetry();
        render();
        dg::renderer::endScene();

    }
    void onImguiRender() {
        ImGui::Begin("test");
        ImGui::Text("Hello neko !");
        ImGui::End();
    }
    void onEvent(dg::event &e) override {
        if (e.getEvenType() == dg::evenType::KeyPressed) {
            dg::KeyPressed &key = (dg::KeyPressed &)e;

            if (key.getKey() == DG_KEY_W)
                DG_TRACE("W was press");
        }
        //dg::eventDispatcher dispatcher(e);
        //dispatcher.Dispatch<dg::KeyPressed>(BIND_EVENT_FN(exampleLayer::onKeypressedEvent));
        //DG_TRACE(e.toString());
    }
    bool onKeypressedEvent(dg::KeyPressed &e) {
        (void)e;
        //if (e.getKey() == DG_KEY_LEFT)
        //    _cameraPosition.x += _cameraSpeed;
        //if (e.getKey() == DG_KEY_RIGHT)
        //    _cameraPosition.x -= _cameraSpeed;
        //if (e.getKey() == DG_KEY_DOWN)
        //    _cameraPosition.y += _cameraSpeed;
        //if (e.getKey() == DG_KEY_UP)
        //    _cameraPosition.y -= _cameraSpeed;
        return false;
    }
    void torus(float r, float R, int nr, int nR) {
        float du = 2 * M_PI / nR;
        float dv = 2 * M_PI / nr;

        for (int i = 0; i < nR; i++) {
            float u = i * du;
            for (int j = 0; j <= nr; j++) {
                float v = (j % nr) * dv;
                for (int k = 0; k < 2; k++) {
                    float uu = u + k * du;

                    float x = (R + r * cos(v)) * cos(uu);
                    float y = (R + r * cos(v)) * sin(uu);
                    float z = r * sin(v);

                    _vertices.push_back(x);
                    _vertices.push_back(y);
                    _vertices.push_back(z);

                    float nx = cos(v) * cos(uu);
                    float ny = cos(v) * sin(uu);
                    float nz = sin(v);

                    _normal.push_back(nx);
                    _normal.push_back(ny);
                    _normal.push_back(nz);

                    float tx = uu / (2 * M_PI);
                    float ty = v / (2 * M_PI);

                    _textCoord.push_back(tx);
                    _textCoord.push_back(ty);

                    glm::vec3 tg(
                    -(R + r * cos(v)) * sin(uu),
                     (R + r * cos(v)) * cos(uu),
                     0.0f);
                    tg = glm::normalize(tg);
                    _tang.push_back(tg);
                }
                v += dv;
            }
        }
    }
    void render() {
        glBindVertexArray(_vao);
        glPointSize(4.0);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, _vertexCount);
        glBindVertexArray(0);
    }
    void geonetry() {
        glCreateVertexArrays(1, &_vao);
        glBindVertexArray(_vao);

        for (auto &tg: _tang) {
            _tangents.push_back(tg.x);
            _tangents.push_back(tg.y);
            _tangents.push_back(tg.z);
        }

        _vertexCount = _vertices.size() / 3;

        GLuint buffer[4];

        glCreateBuffers(4, buffer);

        glNamedBufferStorage(buffer[0], sizeof(float) * _vertices.size(), _vertices.data(), 0);
        glVertexArrayVertexBuffer(_vao, 0, buffer[0], 0, 3 * sizeof(float));
        glVertexArrayAttribFormat(_vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribBinding(_vao, 0, 0);
        glEnableVertexArrayAttrib(_vao, 0);

        glNamedBufferStorage(buffer[1], sizeof(float) * _normal.size(), _normal.data(), 0);
        glVertexArrayVertexBuffer(_vao, 1, buffer[1], 0, 3 * sizeof(float));
        glVertexArrayAttribFormat(_vao, 1, 3, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribBinding(_vao, 1, 1);
        glEnableVertexArrayAttrib(_vao, 1);

        glNamedBufferStorage(buffer[2], sizeof(float) * _textCoord.size(), _textCoord.data(), 0);
        glVertexArrayVertexBuffer(_vao, 2, buffer[2], 0, 2 * sizeof(float));
        glVertexArrayAttribFormat(_vao, 2, 2, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribBinding(_vao, 2, 2);
        glEnableVertexArrayAttrib(_vao, 2);

        glNamedBufferStorage(buffer[3], sizeof(float) * _tangents.size(), _tangents.data(), 0);
        glVertexArrayVertexBuffer(_vao, 3, buffer[3], 0, 3 * sizeof(float));
        glVertexArrayAttribFormat(_vao, 3, 3, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribBinding(_vao, 3, 3);
        glEnableVertexArrayAttrib(_vao, 3);
        glBindVertexArray(0);

        _tangents.clear();
    }
private:
    std::shared_ptr<dg::vertexArray> _vertexArray;
    std::shared_ptr<dg::vertexArray> _squareVertexArray;
    std::shared_ptr<dg::shaderOpenGL> _shader;
    std::shared_ptr<dg::shaderOpenGL> _shader2;

    dg::orthographiCamera _camera;
    glm::vec3 _cameraPosition;
    float _cameraMoveSpeed = 4.0f;

    float _cameraRotationSpeed = 60.0f;
    float _cameraRotation = 0.0f;

    glm::vec3 _squarePosition;

    //torus
    std::vector<float> _vertices;
    std::vector<float> _normal;
    std::vector<float> _textCoord;
    std::vector<float> _tangents;
    std::vector<glm::vec3> _tang;

    uint32_t _vao;
    uint32_t _vertexCount;
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