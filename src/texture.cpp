#define STB_IMAGE_IMPLEMENTATION
#include "texture.hpp"

//faire texture / shader
//loggin pour debugging 

#include <iostream>

dg::texture::texture(const std::string &filePath): _filePath(filePath), _localBuffer(nullptr), _textId(0), _height(0), _width(0), _BPP(0) {
    //use flip if the start of opengl draw is left bottom corner
    //stbi_set_flip_vertically_on_load(1);
    _localBuffer = stbi_load(_filePath.c_str(), &_width, &_height, &_BPP, 4);
    glGenTextures(1, &_textId);
    glBindTexture(GL_TEXTURE_2D, _textId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _localBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);
    std::cout << _height << "  " << std::endl;
    std::cout << _width << std::endl;
    if (_localBuffer)
        stbi_image_free(_localBuffer);
}

dg::texture::~texture() {
    glDeleteTextures(1, &_textId);
}

void dg::texture::bind(u_int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, _textId);
}

void dg::texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
