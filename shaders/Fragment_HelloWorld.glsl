#version 330 core

// In world cordinates
// Will be transformed into eye position
uniform vec4  light_pos = vec4(100.0, 100.0, 100.0, 1.0);
uniform int shininess = 32;
uniform vec3  ambient = vec3(0.1, 0.1, 0.1);//0.1, 0.1, 0.1
uniform vec3  light_colour = vec3(1.0,1.0,1.0);
uniform float specularStrength = 0.5;
uniform vec3 view_pos = vec3(0.0,0.0,0.0);
layout (location = 0) out vec4 color;

in mat4 model_view_matrix;
in vec3 FragPos;  
in vert_out{
    vec3 color;
    vec3 Normal;
} v_in;

void main() {
    // color = vec4(v_in.color, 1.0);
    vec3 light_position_eye_cordinates = vec3(model_view_matrix * light_pos); 
    vec3 norm = normalize(v_in.Normal);
    vec3 light_dir = normalize(light_position_eye_cordinates - FragPos);  
    // 0.0 should be input
    float diff = max(dot(norm, light_dir), 0.0);
    vec3 diffuse = diff * light_colour;

    float specularStrength = 0.5;
    vec3 viewDir = normalize(view_pos - FragPos);
    vec3 reflectDir = reflect(-light_dir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * light_colour;

    vec3 result = (ambient + diffuse + specular) * v_in.color;
    color = vec4(result, 1.0);

}
