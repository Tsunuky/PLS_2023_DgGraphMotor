#pragma once

#include <renderer/buffer.hpp>

namespace dg {

class vertexArray {
public:
    virtual ~vertexArray() {}
public:
    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    virtual void addVertexBuffer(const std::shared_ptr<vertexBuffer> &vertexBuffer) = 0;
    virtual void setIndexBuffer(const std::shared_ptr<indexBuffer> &indexBuffer) = 0;

    virtual const std::vector<std::shared_ptr<vertexBuffer>> &getVertexBuffer() const = 0;
    virtual const std::shared_ptr<indexBuffer> &getIndexBuffer() const = 0;

    static vertexArray* create();
};

}