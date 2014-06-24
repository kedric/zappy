/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 14:38:03 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 16:32:40 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "world.h"

t_world	*world_new(int width, int height)
{
	t_world	*w;

	if (!(w = (t_world *)malloc(sizeof(t_world))))
		return (NULL);
	w->width = width;
	w->height = height;
	w->squares = world_new_squares(width, height);
	if (!w->squares)
		world_del(&w);
	return (w);
}
