#version 410

in vec3 texture_coords;
out vec4 fragment_color;
uniform sampler2D basic_texture;
uniform samplerCube cube_texture;

void	main()
{
	vec4 texel = texture(cube_texture, texture_coords);
	fragment_color = texel;
}
