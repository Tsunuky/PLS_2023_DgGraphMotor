#include <application.hpp>

#define GLFW_EXPOSE_NATIVE_X11
#include <GLFW/glfw3native.h>

#include <renderer/renderer.hpp>

void dg::application::onEvent(dg::event &e) {
    dg::eventDispatcher dispatcher(e);

    dispatcher.Dispatch<dg::windowCloseEvent>(BIND_EVENT_FN(application::onEventClose));
    //DG_CORE_TRACE("{0}",e.toString());
    for (auto it = _layerStack.end(); it != _layerStack.begin();) {
        if (e.handled)
            break;
        (*--it)->onEvent(e);
    }
}

void dg::application::run() {
    while (isRunning) {
        //DG_CORE_INFO("thread concurenced :{0}", n);
        //if (input::istKeyPress(DG_KEY_A) == true)
        //    DG_TRACE("a press");
        //if (input::whileKeyPress(DG_KEY_Q) == true)
        //    DG_CORE_TRACE("q press");
        //tmp test hangement de lib
        //glClearColor(0.1f, 0.1f, 0.1f, 1);
        //glClear(GL_COLOR_BUFFER_BIT);

        renderCommand::setClearColor({0.1f, 0.1f, 0.1f, 1});
        renderCommand::clear();

        //_camera.setPosition({0.5f, 0.5f, 0.0f});
        //_camera.setRotation(45.0f);

        //DG_CORE_INFO("camera rotation :{0}", _camera.getRotation());

        renderer::beginScene(_camera); // add camera, light and environement
        
        //_shader2->bind();
        //_shader2->uploadUniformMat4("u_viewProjection", _camera.getviewProjectionMatrix());
        renderer::submit(_shader2 , _squareVertexArray); // overload pour send mesh ou vertex array
        
        //_shader->bind();
        //_shader->uploadUniformMat4("u_viewProjection", _camera.getviewProjectionMatrix());
        renderer::submit(_shader , _vertexArray); // overload pour send mesh ou vertex array

        renderer::endScene();

        //_shader2->bind();
        //_squareVertexArray->bind();
        //glDrawElements(GL_TRIANGLES, _squareVertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);

        //_shader->bind();
        //_vertexArray->bind();
        //glDrawElements(GL_TRIANGLES, _indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
        
        for (layer *layer: _layerStack) {
            layer->onUpdate();
        }
        _imguiLayer->begin();
        for (layer *layer: _layerStack) {
            layer->onImguiRender();
        }
        _imguiLayer->end();
        _win.get()->onUpdate();
    }
};

bool dg::application::onEventClose(dg::windowCloseEvent &e) {
    (void)e;
    isRunning = false;
    return true;
}

void dg::application::pushLayer(dg::layer *layer) {
    _layerStack.pushLayer(layer);
    layer->onAttach();
}

void dg::application::pushOverlay(dg::layer *overlay) {
    _layerStack.pushOverlay(overlay);
    overlay->onAttach();
}