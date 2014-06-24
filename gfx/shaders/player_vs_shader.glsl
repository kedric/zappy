#version 410 core

layout (location = 0) in vec3 v_i;
layout (location = 1) in float start_time;

uniform mat4 view, proj;
uniform float elapsed_time;
uniform vec3 move;

out float opacity;

void main() {
	float t = elapsed_time - start_time;
	t = mod (t, 1.0);
	opacity = 0.0;
	vec3 p = move;
	vec3 a = vec3(0.0, 1.0, 0.0);
	p += v_i * t + 0.5 * a * t * t;
	opacity = 1.0 - (t / 1.5);
	gl_Position = proj * view * vec4(p, 1.0);
	gl_PointSize = 5.0; // size in pixels
}
