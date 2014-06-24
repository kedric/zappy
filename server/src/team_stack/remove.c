/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:24:32 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 15:34:36 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "team_stack.h"

void	team_stack_remove(t_team_stack *s, t_team *t)
{
	t_team	*i;
	t_team	*j;

	j = s->first ? s->first->next : NULL;
	if (s->first == t)
	{
		team_del(&t);
		s->first = j;
		s->count = 0;
		return ;
	}
	i = s->first;
	while (j)
	{
		if (j == t)
		{
			i->next = j->next;
			team_del(&j);
			s->count--;
			return ;
		}
		i = j;
		j = j->next;
	}
}
