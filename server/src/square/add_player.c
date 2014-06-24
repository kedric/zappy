/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 14:23:25 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 14:28:49 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

void	square_add_player(t_square *s, t_player *p)
{
	player_stack_add(&s->players, p);
}
