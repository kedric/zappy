/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_squares.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:29:22 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 16:53:44 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "world.h"

t_square	**world_new_squares(int width, int height)
{
	t_square	**s;
	int			x;
	int			y;
	t_square	*i;
	
	if (!(s = (t_square **)malloc(sizeof(t_square *) * (width * height))))
		return (NULL);
	y = height;
	while (y--)
	{
		x = width;
		while (x--)
		{
			if (!(i = square_new(x, y)))
			{
				world_del_squares(&s, width, height);
				return (NULL);
			}
			s[y * width + x] = i;
		}
	}
	return (s);
}
