/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 14:27:26 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 15:43:10 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "team.h"

void	team_remove_player(t_team *t, t_player *p)
{
	if (!t->count)
		return ;
	player_stack_remove(&t->players, p, player_stack_del_player);
	t->count--;
}
