#shader vertex
#pragma debug(on)
#version 450 core

layout(location = 0) in vec4 position;

void main() {
    gl_position = position;
};

#shader fragment
#pragma debug(on)
#version 450 core

layout(location = 0) out vec4 color;

void main() {
    color = vec4(1.0, 0.0, 0.0, 1.0);
};