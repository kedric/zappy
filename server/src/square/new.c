/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 14:17:03 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 11:34:21 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "square.h"

t_square	*square_new(int x, int y)
{
	t_square	*s;

	if (!(s = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	s->x = x;
	s->y = y;
	s->players = NULL;
	s->resources = resource_new();
	return (s);
}
