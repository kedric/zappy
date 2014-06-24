/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:58:06 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/10 19:22:44 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_vec	new_vector(float x, float y, float z)
{
	t_vec	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vec2	new_vec2(int x, int y)
{
	t_vec2	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	translate_cam(GLuint shader_prog, t_cam cam, int sky)
{
	t_mat4	rot_y;

	cam.view_mat_location = glGetUniformLocation(shader_prog, "view");
	if (sky)
	{
		rot_y = rot_y_matrix(-cam.yaw * 10);
		glUniformMatrix4fv(cam.view_mat_location, 1, GL_FALSE, rot_y.m);
	}
	else
		glUniformMatrix4fv(cam.view_mat_location, 1, GL_FALSE, cam.view_matrix.m);
	cam.proj_mat_location = glGetUniformLocation(shader_prog, "proj");
	glUniformMatrix4fv(cam.proj_mat_location, 1, GL_FALSE, cam.proj_matrix.m);
}

void	translate_obj(GLuint shader_prog, t_vec pos, int type)
{
	t_mat4	matrix;
	int		location;

	location = glGetUniformLocation(shader_prog, "move");

//	printf("location = %d\n", location);
	if (type == 1)
	{
		matrix = translation_matrix(pos);
		glUniformMatrix4fv(location, 1, GL_FALSE, matrix.m);
	}
	else
		glUniform3f(location, pos.x, pos.y, pos.z);
}
