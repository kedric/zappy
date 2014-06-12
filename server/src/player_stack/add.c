/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:35:29 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 12:42:35 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stack.h"

void	player_stack_add(t_player_stack **s, t_player *p)
{
	t_player_stack	*i;

	if (!p || !s)
		return ;
	i = *s;
	*s = player_stack_new(p);
	(*s)->next = i;
}
