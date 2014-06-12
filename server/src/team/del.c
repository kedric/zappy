/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:22:19 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 13:58:21 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "team.h"

void	team_del(t_team **t)
{
	if (!t || !*t)
		return ;
	player_stack_clear(&(*t)->players, player_stack_del_player);
	bzero(*t, sizeof(t_team));
	free(*t);
	*t = NULL;
}
