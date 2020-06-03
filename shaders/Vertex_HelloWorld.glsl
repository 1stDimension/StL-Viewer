#version 330 core

uniform mat4  u_M;
uniform mat4  u_V;
uniform mat4  u_P;
uniform vec4  u_Color;

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 normal;

out vert_out{
    vec3 color;
} v_o;

//lightning
//TODO consider passing it as uniform
uniform vec3  light_position = vec3(100.0, 100.0, 100.0);
uniform vec3  specular_albedo = vec3(0.7);
uniform float specular_power = 128.0;
uniform vec3  ambient = vec3(0.1, 0.1, 0.1);


void main() {
    vec4 P = u_M * u_V * position;
    vec3 N = mat3(u_M * u_V) * normal;
    vec3 L = light_position - P.xyz;
    vec3 V = -P.xyz;

    N = normalize(N);
    L = normalize(L);
    V = normalize(V);

    vec3 R = reflect(-L, N);
    vec3 diffuse  = max(dot(N, L), 0.0) * u_Color.xyz;
    vec3 specular = pow(max(dot(R, V), 0.0), specular_power) * specular_albedo;

    v_o.color = ambient + diffuse + specular;
    gl_Position = u_P * u_V * u_M * position;
}