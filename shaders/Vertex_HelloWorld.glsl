#version 330 core

uniform mat4  u_M_V_P;

layout(location = 0) in vec4 position;

void main() {
    gl_Position = u_M_V_P * position;
}
