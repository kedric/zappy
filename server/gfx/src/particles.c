/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 13:20:51 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/09 17:57:22 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static GLuint	set_vao(float *vv, float *vt, int particle_count)
{
	GLuint	velocity_vbo;
	GLuint	time_vbo;
	GLuint	vao;
	int		size;

	size = sizeof(GLfloat) * particle_count;
	glGenBuffers (1, &velocity_vbo);
	glBindBuffer (GL_ARRAY_BUFFER, velocity_vbo);
	glBufferData (GL_ARRAY_BUFFER, size * 3, vv, GL_STATIC_DRAW);
	glGenBuffers (1, &time_vbo);
	glBindBuffer (GL_ARRAY_BUFFER, time_vbo);
	glBufferData (GL_ARRAY_BUFFER, size, vt, GL_STATIC_DRAW);
	glGenVertexArrays (1, &vao);
	glBindVertexArray (vao);
	glBindBuffer (GL_ARRAY_BUFFER, velocity_vbo);
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer (GL_ARRAY_BUFFER, time_vbo);
	glVertexAttribPointer (1, 1, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray (0);
	glEnableVertexAttribArray (1);
	free(vv);
	free(vt);
	return (vao);
}

static GLuint	gen_particles(int particle_count)
{
	GLfloat	*vv;
	GLfloat	*vt;
	float	accum;
	int		j;
	int		i;

	vv = (GLfloat *)malloc(sizeof(GLfloat) * particle_count * 3);
	vt = (GLfloat *)malloc(sizeof(GLfloat) * particle_count);
	i = -1;
	j = 0;
	accum = 0.f;
	while (++i < particle_count)
	{
		vt[i] = accum;
		accum += 0.01f;
		vv[j] = ((float)rand() / (float)RAND_MAX) * 1.0f - 0.5f;
		vv[j + 1] = ((float)rand() / (float)RAND_MAX) * 1.0f - 0.5f;
		vv[j + 2] = ((float)rand() / (float)RAND_MAX) * 1.0f - 0.5f;
		j += 3;
	}
	return (set_vao(vv, vt, particle_count));
}

t_gldata	set_particle(int particle_count, char *file)
{
	t_gldata	particle;

	particle.vao = gen_particles(particle_count);
	particle.texture = load_texture(file);
	particle.program = get_shader("player");
	particle.point_count = particle_count;
	return (particle);
}

void	draw_particles(t_gldata particle)
{
	int	location;

	glEnable (GL_PROGRAM_POINT_SIZE);
	glEnable (GL_BLEND);
	glActiveTexture (GL_TEXTURE0);
	glBindTexture (GL_TEXTURE_2D, particle.texture);
	glUseProgram (particle.program);
	location = glGetUniformLocation(particle.program, "elapsed_time");
	glUniform1f(location, glfwGetTime());
	glBindVertexArray (particle.vao);
	glDrawArrays (GL_POINTS, 0, particle.point_count);
	glDisable (GL_BLEND);
	glDisable (GL_PROGRAM_POINT_SIZE);
}
