/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 14:29:20 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 14:30:31 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

void	square_remove_player(t_square *s, t_player *p)
{
	player_stack_remove(&s->players, p, player_stack_del);
}
