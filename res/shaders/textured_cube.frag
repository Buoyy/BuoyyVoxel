#version 330 core 

in vec2 v_uv;
uniform sampler2D tex;

out vec4 final_color;

void main()
{
	final_color = texture(tex, v_uv);
}