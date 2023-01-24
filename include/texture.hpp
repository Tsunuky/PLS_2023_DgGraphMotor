#pragma once

#include <GL/glut.h>
#include <string>

#include "stb_image.hpp"

namespace dg {

class texture {
public:
    texture(const std::string &filePath);
    ~texture();
public:
    void bind(u_int slot = 0) const;
    void unbind() const;
public:
    inline int getHeight() const {return _height;};
    inline int getWidth() const {return _width;};
private:
    std::string _filePath;
    u_char *_localBuffer;
    u_int _textId;
    int _height;
    int _width;
    int _BPP;
};

}