/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:57:42 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 13:12:13 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_stack.h"

int	player_stack_count(t_player_stack *s, int (*f)(t_player *))
{
	int	i;

	i = 0;
	while (s)
	{
		if (!f || (*f)(s->player))
			i++;
		s = s->next;
	}
	return (i);
}
