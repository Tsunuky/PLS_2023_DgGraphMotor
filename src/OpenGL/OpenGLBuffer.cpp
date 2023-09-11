#include <OpenGL/OpenGLBuffer.hpp>

void dg::openGLVertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, _renderedId);
}

void dg::openGLVertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void dg::openGLIndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderedId);
}

void dg::openGLIndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}