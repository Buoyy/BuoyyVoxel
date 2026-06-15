#version 330 core 

in vec2 v_uv;
out vec4 result;

uniform sampler2D tex;

void main()
{
    result = texture(tex, v_uv);
}