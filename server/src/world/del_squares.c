/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_squares.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:38:51 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 16:53:47 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "world.h"

void	world_del_squares(t_square ***s, int width, int height)
{
	int			x;
	int			y;
	t_square	*i;

	if (!s || !*s)
		return ;
	y = height;
	while (y--)
	{
		x = width;
		while (x--)
		{
			i = (*s)[y * width + x];
			square_del(&i);
		}
	}
	free(*s);
	*s = NULL;
}
