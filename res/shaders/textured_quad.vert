#version 330 core 

layout (location = 0) in vec3 _pos;
layout (location = 1) in vec2 _uv;

out vec2 v_uv;

void main()
{
    gl_Position = vec4(_pos, 1.0);
    v_uv = _uv;
}