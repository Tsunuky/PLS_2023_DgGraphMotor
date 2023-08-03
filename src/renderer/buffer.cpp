#include <renderer/buffer.hpp>
#include <renderer/renderer.hpp>
#include <renderer/openGlBuffer.hpp>


#include <log.hpp>

namespace dg {

vertexBuffer* vertexBuffer::create(float *vertices, u_int32_t size) {
    switch (renderer::getAPI()) {
        case renderAPI::none:       return nullptr;
        case renderAPI::openGL:     return new openGLVertexBuffer(vertices, size);
    }
    DG_CORE_ASSERT(false, "Unknown RendererAPI");
    return nullptr;
}

indexBuffer* indexBuffer::create(u_int32_t *indices, u_int32_t size) {
    switch (renderer::getAPI()) {
        case renderAPI::none:       return nullptr;
        case renderAPI::openGL:     return new openGLIndexBuffer(indices, size);
    }
    DG_CORE_ASSERT(false, "Unknown RendererAPI");
    return nullptr;
}


}