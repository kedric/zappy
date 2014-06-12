/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:31:42 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 13:35:11 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stack.h"

void	player_stack_clear(t_player_stack **s, void (*f)(t_player_stack **))
{
	t_player_stack	*n;

	if (!s || !f)
		return ;
	while (*s)
	{
		n = (*s)->next;
		(*f)(s);
		*s = n;
	}
}
