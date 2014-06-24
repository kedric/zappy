#version 410

in vec2 texture_coords;
out vec4 fragment_color;
uniform sampler2D basic_texture;

in vec3 color;
void	main()
{
	vec4 texel = texture(basic_texture, texture_coords);
	fragment_color = texel;
}
