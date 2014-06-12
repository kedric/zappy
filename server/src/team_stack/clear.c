/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:15:25 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 15:34:12 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "team_stack.h"

void	team_stack_clear(t_team_stack *s)
{
	t_team	*t;
	t_team	*swap;

	t = s->first;
	while (t)
	{
		swap = t->next;
		team_del(&t);
		t = swap;
	}
	s->count = 0;
}
