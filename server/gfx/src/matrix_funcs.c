/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 05:01:55 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/06 10:38:04 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_mat4	translation_matrix(t_vec p)
{
	t_mat4	mat4;

	mat4 = identity_matrix();
	mat4.m[12] = p.x;
	mat4.m[13] = p.y;
	mat4.m[14] = p.z;
	return (mat4);
}

t_mat4	rot_x_matrix(float angle)
{
	t_mat4		mat4;
	int			i;
	float		rad;

	i = -1;
	mat4 = identity_matrix();
	rad = angle * M_PI / 180;
	mat4.m[5] = cosf(rad);
	mat4.m[10] = cosf(rad);
	mat4.m[9] = -sinf(rad);
	mat4.m[6] = sinf(rad);
	return (mat4);
}

t_mat4	rot_y_matrix(float angle)
{
	t_mat4		mat4;
	int			i;
	float		rad;

	i = -1;
	mat4 = identity_matrix();
	rad = angle * M_PI / 180;
	mat4.m[0] = cosf(rad);
	mat4.m[10] = cosf(rad);
	mat4.m[2] = -sinf(rad);
	mat4.m[8] = sinf(rad);
	return (mat4);
}

t_mat4	rot_z_matrix(float angle)
{
	t_mat4		mat;
	float		rad;
	int			i;

	i = -1;
	mat = identity_matrix();
	rad = angle * M_PI / 180;
	mat.m[0] = cosf(rad);
	mat.m[5] = cosf(rad);
	mat.m[4] = -sinf(rad);
	mat.m[1] = sinf(rad);
	return (mat);
}

t_mat4	multiply_matrix(t_mat4 mat1, t_mat4 mat2)
{
	t_mat4	mat;
	int		i;
	int		row;
	int		col;
	int		index;

	col = -1;
	index = 0;
	while (++col < 4)
	{
		row = -1;
		while (++row < 4)
		{
			i = -1;
			mat.m[index] = 0.f;
			while (++i < 4)
				mat.m[index] += mat1.m[i + col * 4] * mat2.m[row + i * 4];
			index++;
		}
	}
	return (mat);
}
