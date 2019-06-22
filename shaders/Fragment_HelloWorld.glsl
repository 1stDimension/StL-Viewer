#version 330 core


layout (location = 0) out vec4 color;

in vert_out{
    vec3 color;
} v_in;

void main() {
    color = vec4(v_in.color, 1.0);
}
