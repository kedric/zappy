/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:14:36 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 15:02:16 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include <stddef.h>

int			do_left(t_act *act, t_player *player)
{
	player->orientation = (++player->orientation == 0) ? O_WEST : player->orientation;
	//send_message client / gfx
	return (0);
}

int			init_left(t_act *act, t_player *player, t_world *world)
{
	(void)player;
	(void)world;
	act->fct_check = NULL;
	act->waiting = TIME_LEFT;
	act->fct_do = do_left;
	act->next = NULL;
	return (0);
}
