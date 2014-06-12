/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_funcs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 07:52:01 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/06 10:45:58 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_mat4	identity_matrix(void)
{
	t_mat4	mat4;
	int		i;

	i = -1;
	while (++i < 16)
	{
		if (i % 5 == 0)
			mat4.m[i] = 1.f;
		else
			mat4.m[i] = 0.f;
	}
	return (mat4);
}

t_mat4	scale_matrix(t_vec p)
{
	t_mat4	mat4;

	mat4 = identity_matrix();
	mat4.m[0] = p.x;
	mat4.m[5] = p.y;
	mat4.m[10] = p.z;
	return (mat4);
}

t_mat4	zero_matrix(void)
{
	t_mat4	mat;
	int		i;

	i = -1;
	while (++i < 16)
		mat.m[i] = 0.f;
	return (mat);
}

t_mat4	view_matrix(t_vec cam_pos, t_vec look_at, t_vec roll)
{
	t_mat4	p;
	t_mat4	view_matrix;
	t_vec	f;
	t_vec	r;
	t_vec	u;

	p = translation_matrix(new_vector(-cam_pos.x, -cam_pos.y, -cam_pos.z));
	f = normalize(sub_vector(look_at, cam_pos));
	r = normalize(cross(f, roll));
	u = normalize(cross(r, f));
	view_matrix = identity_matrix();
	view_matrix.m[0] = r.x;
	view_matrix.m[4] = r.y;
	view_matrix.m[8] = r.z;
	view_matrix.m[1] = u.x;
	view_matrix.m[5] = u.y;
	view_matrix.m[9] = u.z;
	view_matrix.m[2] = -f.x;
	view_matrix.m[6] = -f.y;
	view_matrix.m[10] = -f.z;
	return (multiply_matrix(view_matrix, p));
}

t_mat4	perspective_matrix(float fov, float aspect, float near, float far)
{
	float	fov_rad;
	float	range;
	float	p;
	t_vec	s;
	t_mat4	mat;

	fov_rad = fov * M_PI / 180;
	range = tanf(fov_rad * 0.5) * near;
	s.x = (2.f * near) / (range * aspect + range * aspect);
	s.y = near / range;
	s.z = -(far + near) / (far - near);
	p = -(2.f * far * near) / (far - near);
	mat = zero_matrix();
	mat.m[0] = s.x;
	mat.m[5] = s.y;
	mat.m[10] = s.z;
	mat.m[14] = p;
	mat.m[11] = -1.f;
	return (mat);
}
