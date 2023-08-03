#pragma once

#include <log.hpp>
#include <string>

namespace dg {

enum class shaderDataType {
    None = 0,
    Float,
    Float2,
    Float3,
    Float4,
    Mat3,
    Mat4,
    Int,
    Int2,
    Int3,
    Int4,
    Bool
};

static u_int32_t ShaderDataTypeSize(shaderDataType type) {
    switch (type) {
        case shaderDataType::Float:     return 4;
        case shaderDataType::Float2:    return 4 * 2;
        case shaderDataType::Float3:    return 4 * 3;
        case shaderDataType::Float4:    return 4 * 4;
        case shaderDataType::Mat3:      return 4 * 3 * 3;
        case shaderDataType::Mat4:      return 4 * 4 * 4;
        case shaderDataType::Int:       return 4;
        case shaderDataType::Int2:      return 4 * 2;
        case shaderDataType::Int3:      return 4 * 3;
        case shaderDataType::Int4:      return 4 * 4;
        case shaderDataType::Bool:      return 1;
        case shaderDataType::None:      break;
    }
    DG_CORE_ASSERT(false, "Unknown shaderDataTypa !");
    return 0;
}

struct bufferElement {
    std::string name;
    shaderDataType type;
    u_int32_t size;
    u_int32_t offset;
    bool normalized;

    bufferElement() {}

    bufferElement(shaderDataType Type, const std::string &Name, bool Normalized = false)
        : name(Name), type(Type), size(ShaderDataTypeSize(type)), offset(0), normalized(Normalized) {}

    u_int32_t getCompementCount() const {
        switch (type) {
        case shaderDataType::Float:     return 1;
        case shaderDataType::Float2:    return 2;
        case shaderDataType::Float3:    return 3;
        case shaderDataType::Float4:    return 4;
        case shaderDataType::Mat3:      return 3 * 3;
        case shaderDataType::Mat4:      return 4 * 4;
        case shaderDataType::Int:       return 1;
        case shaderDataType::Int2:      return 2;
        case shaderDataType::Int3:      return 3;
        case shaderDataType::Int4:      return 4;
        case shaderDataType::Bool:      return 1;
        case shaderDataType::None:      break;
        }

        DG_CORE_ASSERT(false, "Unknown shaderDataTypa !");
        return 0;
    }
};

class bufferLayout {
public:
    bufferLayout() {}
    bufferLayout(const std::initializer_list<bufferElement> &elements)
        : _elements(elements) {
        calculateOffsetsAndStride();
    }
public:
inline u_int32_t getStride() const {return _stride;}
    inline const std::vector<bufferElement> &getElements() const {return _elements;};

    std::vector<bufferElement>::iterator begin() {return _elements.begin();}
    std::vector<bufferElement>::iterator end() {return _elements.end();}
    std::vector<bufferElement>::const_iterator begin() const {return _elements.begin();}
    std::vector<bufferElement>::const_iterator end() const {return _elements.end();}
private:
    void calculateOffsetsAndStride() {
        u_int32_t offset = 0;
        _stride = 0;

        for (auto &element :_elements) {
            element.offset = offset;
            offset += element.size;
            _stride += element.size;
        }
    }

private:
    std::vector<bufferElement> _elements;
    u_int32_t _stride = 0;
};

class vertexBuffer {
public:
    virtual ~vertexBuffer() {}
public:
    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    virtual void setLayout(const bufferLayout &layout) = 0;
    virtual const bufferLayout &getLayout() = 0;

    static vertexBuffer* create(float *vertices, u_int32_t size);
};

class indexBuffer {
public:
    virtual ~indexBuffer() {}
public:
    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    virtual u_int32_t getCount() const = 0;

    static indexBuffer* create(u_int32_t *indices, u_int32_t size);
};

}