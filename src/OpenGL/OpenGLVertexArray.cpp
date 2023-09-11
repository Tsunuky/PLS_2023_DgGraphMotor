#include <OpenGL/OpenGLVertexArray.hpp>

namespace dg {

    static GLenum shaderDataTypeToOpenglDataType(shaderDataType type) {
        switch (type) {
        case shaderDataType::Float:     return GL_FLOAT;
        case shaderDataType::Float2:    return GL_FLOAT;
        case shaderDataType::Float3:    return GL_FLOAT;
        case shaderDataType::Float4:    return GL_FLOAT;
        case shaderDataType::Mat3:      return GL_FLOAT;
        case shaderDataType::Mat4:      return GL_FLOAT;
        case shaderDataType::Int:       return GL_INT;
        case shaderDataType::Int2:      return GL_INT;
        case shaderDataType::Int3:      return GL_INT;
        case shaderDataType::Int4:      return GL_INT;
        case shaderDataType::Bool:      return GL_BOOL;
        case shaderDataType::None:      break;   
        }

        DG_CORE_ASSERT(false, "Unknown shaderDataTypa !");
        return 0;
    }

void openGLVertexArray::bind() const {
    glBindVertexArray(_rendererID);
}

void openGLVertexArray::unbind() const {
    glBindVertexArray(0);
}

void openGLVertexArray::addVertexBuffer(const std::shared_ptr<vertexBuffer> &vertexBuffer) {
    DG_CORE_ASSERT(vertexBuffer->getLayout().getElements().size(), "VertexBuffer has no layout !");
    glBindVertexArray(_rendererID);
    vertexBuffer->bind();
    
    u_int32_t index = 0;
    const auto &layout = vertexBuffer->getLayout();

    for (auto &element : layout) {
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, element.getCompementCount(),
            shaderDataTypeToOpenglDataType(element.type),
            element.normalized ? GL_TRUE : GL_FALSE,
            layout.getStride(), (const void *)(size_t)element.offset);
        index++;
    }
    _vertexBuffers.push_back(vertexBuffer);
}

void openGLVertexArray::setIndexBuffer(const std::shared_ptr<indexBuffer> &indexBuffer) {
    glBindVertexArray(_rendererID);
    indexBuffer->bind();

    _indexBuffers = indexBuffer;
}

}