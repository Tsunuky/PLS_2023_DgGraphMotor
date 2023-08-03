#pragma once

#include <renderer/vertexArray.hpp>
#include <glad/glad.hpp>

namespace dg {

class openGLVertexArray: public vertexArray {
public:
    openGLVertexArray() {
        glCreateVertexArrays(1, &_rendererID);
    }
    virtual ~openGLVertexArray() {
        glDeleteVertexArrays(1, &_rendererID);
    }
public:
    virtual void bind() const override;
    virtual void unbind() const override;

    virtual void addVertexBuffer(const std::shared_ptr<vertexBuffer> &vertexBuffer) override;
    virtual void setIndexBuffer(const std::shared_ptr<indexBuffer> &indexBuffer) override;
public:
    virtual const std::vector<std::shared_ptr<vertexBuffer>> &getVertexBuffer() const override {return _vertexBuffers;};
    virtual const std::shared_ptr<indexBuffer> &getIndexBuffer() const override {return _indexBuffers;}
private:
    std::vector<std::shared_ptr<vertexBuffer>> _vertexBuffers;
    std::shared_ptr<indexBuffer> _indexBuffers;
    u_int32_t _rendererID;
};

}