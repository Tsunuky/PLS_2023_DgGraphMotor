#include <renderer/renderer.hpp>
#include <renderer/vertexArray.hpp>
#include <OpenGL/OpenGLVertexArray.hpp>

namespace dg {

    vertexArray* vertexArray::create() {
        switch (renderer::getAPI()) {
            case rendererAPI::API::none:       return nullptr;
            case rendererAPI::API::openGL:     return new openGLVertexArray();
        }
        DG_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;   
    }
   
}