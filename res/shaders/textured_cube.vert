#version 330 core

layout (location = 0) in vec3 _pos;
layout (location = 1) in vec2 _uv;

out vec2 v_uv;

uniform mat4 model, view, projection;

void main()
{
	gl_Position = projection * view * model * vec4(_pos, 1.0);
	v_uv = _uv;
}