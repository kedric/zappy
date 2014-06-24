#version 410

layout(location = 0)in vec3 vertex_pos;
layout(location = 1)in vec3 vertex_normals;
layout(location = 2)in vec2 vertex_texture;

uniform mat4 view, proj, move;
out vec2 texture_coords;
out vec3 color;

void	main()
{
	texture_coords = vertex_texture;
	color = vertex_normals;
	gl_Position = proj * view * move * vec4(vertex_pos, 1.0);
}
