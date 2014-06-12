#version 410

layout(location = 0)in vec3 vertex_pos;
layout(location = 1)in vec3 vertex_normals;
layout(location = 2)in vec2 vertex_texture;

uniform mat4 view, proj, move;
out vec3 texture_coords;

void	main()
{
	texture_coords = vertex_pos;
	gl_Position = proj * view * vec4(vertex_pos, 1.0);
}
