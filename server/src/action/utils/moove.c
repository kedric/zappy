/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 13:13:41 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 15:16:57 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include <stddef.h>

int			do_moove(t_act *act, t_player *player)
{
	square_remove_player(player->square, player);
	// voire avec romain pour qu il fasse une fonction pour me sortire un t_squar
	// square_add_player(act->to, player);

	// send message client / graphique
}

int			init_moove(t_act *act, t_player *player, t_world *world)
{
	act->fct_check = NULL;
	act->waiting = TIME_MOOVE;
	act->fct_do = do_moove;
	act->next = NULL;
}
