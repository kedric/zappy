/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 08:38:51 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/06 08:39:11 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_vec	sub_vector(t_vec a, t_vec b)
{
	t_vec res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

float	get_length(t_vec p)
{
	return (sqrtf(p.x * p.x + p.y * p.y + p.z * p.z));
}

t_vec	cross(t_vec a, t_vec b)
{
	t_vec res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

t_vec	normalize(t_vec p)
{
	float	len;

	len = get_length(p);
	if (len == 0.f)
		return (new_vector(0.f, 0.f, 0.f));
	p.x /= len;
	p.y /= len;
	p.z /= len;
	return (p);
}
