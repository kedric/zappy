/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:02:04 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 15:02:14 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include <stddef.h>

int			do_right(t_act *act, t_player *player)
{
	player->orientation = (++player->orientation == 5) ? O_NORTH : player->orientation;
	//send_message client / gfx
	return (0);
}

int			init_right(t_act *act, t_player *player, t_world *world)
{
	(void)player;
	(void)world;
	act->fct_check = NULL;
	act->waiting = TIME_RIGHT;
	act->fct_do = do_right;
	act->next = NULL;
	return (0);
}
