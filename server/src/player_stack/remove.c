/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:41:05 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 13:35:13 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stack.h"

void	player_stack_remove(t_player_stack **s, t_player *p, void (*f)(t_player_stack **))
{
	t_player_stack	*i;
	t_player_stack	*j;

	if (!s || !*s || !p || !f)
		return ;
	j = (*s)->next;
	if ((*s)->player == p)
	{
		(*f)(s);
		*s = j;
		return ;
	}
	i = *s;
	while (j)
	{
		if (j->player == p)
		{
			i->next = j->next;
			(*f)(&j);
			return ;
		}
		i = j;
		j = j->next;
	}
}
