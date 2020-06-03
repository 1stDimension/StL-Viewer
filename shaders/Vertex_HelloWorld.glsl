#version 430 core

uniform mat4  u_M;
uniform mat4  u_V;
uniform mat4  u_P;
uniform vec4  u_Color;

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 normal;

out mat4 model_view_matrix;
out vec3 FragPos;  
out vert_out{
    vec3 color;
    vec3 Normal;
} v_o;

//lightning
//TODO consider passing it as uniform
uniform vec3  specular_albedo = vec3(0.7);//0.7
// uniform float specular_power = 128.0;//128.0
// uniform vec3  ambient = vec3(0.1, 0.1, 0.1);//0.1, 0.1, 0.1


void main() {
    mat4 ModelView = u_V * u_M;
    model_view_matrix = ModelView;

    v_o.color = u_Color.xyz;

    v_o.Normal = mat3(transpose(inverse(ModelView))) * normal;
    FragPos = vec3( ModelView * position);
    gl_Position = u_P * u_V * u_M * position;
}