/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:36:32 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 15:24:08 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include <stddef.h>
#include <stdlib.h>

int			check_take(t_act *act, t_player *player)
{
	if (ressource_quantity(player->square->resources, act->t) > 0)
		return (0);
	return(-1);
}

int			do_take(t_act *act, t_player *player)
{
	if (check_take(act, player) == -1)
		return (-1);
	resource_remove(player->square->resources, act->t, 1);
	resource_add(player->resources, act->t, 1);
	//send_message client / gfx
	return (0);
}

int			init_take(t_act *act, t_player *player, t_world *world)
{
	if (check_take(act, player))
	{
		free(act);
		return (-1);
	}
	(void)world;
	act->fct_check = check_take;
	act->waiting = TIME_TAKE;
	act->fct_do = do_take;
	act->next = NULL;
	return (0);
}
