/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:00:58 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 13:02:05 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	player_max_level(t_player *p)
{
	return (p->level == PLAYER_MAX_LEVEL);
}