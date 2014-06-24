/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:37:09 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 15:02:12 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include <stdlib.h>

/*
** creer une nouvelle action
** la variable wait est a + 1 lors d'un tour je commence par decrementer
** cette variable mais je dois quand meme attendre le tours d initialisation
** donc je le rajoute ici;
*/

t_act *new_act(t_player *player,t_world *world, int opt)
{
	t_act *act;
	t_table_action *ref;

	act = NULL;
	ref = sig_tab_act();
	act = (t_act *)malloc(sizeof(t_act));
	ref->fct_init[opt](act, player, world);
	return (act);
}

void	*destroy_act(t_act *act)
{
	free(act);
}
