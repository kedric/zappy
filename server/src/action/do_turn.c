/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:16:08 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 10:38:05 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "action.h"

int init_new_turn(t_player *player)
{
	int ret;

	ret = 0;
	if ((ret = lower_pv(&player->pv)) != 0)
		return (ret);
	lower_turn_action();
}


/*
** effectue le tour apres le sellec pour cela elle parcourt tout la stack des
** team
** 1-aplique a chaque joueur la decrementaion des variable
** 2-une baterie de test avant d'aplique l'action
**
*/

void	do_turn(t_team_stack *team, t_world *world)
{
	int				i;
	int				ret;
	t_team			*tmp_t;
	t_player_stack	*tmp_p;

	if (team == NULL || world == NULL)
		return ;
	if ((tmp_t = team->first) == NULL)
		return ;
	if ((tmp_p = tmp_t->players) == NULL)
		return ;
	i = -1;
	while (++i < team->count)
	{
		while (tmp_p != NULL)
		{
			init_new_turn(tmp_p->player);
			if ((ret = check_act(tmp_p->player, world)) == 1)
				do_act();
			tmp_p = tmp_p->next;
		}
		tmp_t = tmp_t->next;
	}
}
