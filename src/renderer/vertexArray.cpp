#include <renderer/renderer.hpp>
#include <renderer/vertexArray.hpp>
#include <renderer/OpenGLVertexArray.hpp>

namespace dg {

    vertexArray* vertexArray::create() {
        switch (renderer::getAPI()) {
            case renderAPI::none:       return nullptr;
            case renderAPI::openGL:     return new openGLVertexArray();
        }
        DG_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;   
    }
   
}