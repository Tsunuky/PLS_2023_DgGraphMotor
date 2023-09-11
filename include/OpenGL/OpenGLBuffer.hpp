#pragma once

#include <renderer/buffer.hpp>
#include <glad/glad.hpp>

namespace dg {

class openGLVertexBuffer: public vertexBuffer {
public:
    openGLVertexBuffer(float *vertices, u_int32_t size) {
        glCreateBuffers(1, &_renderedId);
        glBindBuffer(GL_ARRAY_BUFFER, _renderedId);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }
    virtual ~openGLVertexBuffer() {
        glDeleteBuffers(1, &_renderedId);
    }
public:
    virtual void bind() const override;
    virtual void unbind() const override;
public:
    virtual void setLayout(const bufferLayout &layout) override {_layout = layout;};
public:
    virtual const bufferLayout &getLayout() override {return _layout;};
private:
    u_int32_t _renderedId;
    bufferLayout _layout;
};

class openGLIndexBuffer: public indexBuffer {
public:
    openGLIndexBuffer(u_int32_t *indices, u_int32_t count): _count(count) {
        glCreateBuffers(1, &_renderedId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderedId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(u_int32_t), indices, GL_STATIC_DRAW);
    }
    virtual ~openGLIndexBuffer() {
        glDeleteBuffers(1, &_renderedId);
    }
public:
    virtual void bind() const override;
    virtual void unbind() const override;
public:
    virtual u_int32_t getCount() const {return _count;}
private:
    u_int32_t _renderedId;
    u_int32_t _count;
};

}