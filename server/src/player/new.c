/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:07:51 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 11:26:39 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "player.h"

t_player	*player_new(int id, t_team *t, t_square *s)
{
	t_player	*p;

	if (!(p = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	p->id = id;
	p->life = PLAYER_START_LIFE;
	p->level = PLAYER_START_LEVEL;
	p->orientation = player_random_orientation();
	p->team = t;
	p->square = s;
	p->resources = resource_new();
	return (p);
}
