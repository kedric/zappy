/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:19:12 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 12:27:09 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "player_stack.h"

t_player_stack	*player_stack_new(t_player *p)
{
	t_player_stack	*s;

	if (!(s = (t_player_stack *)malloc(sizeof(t_player_stack))))
		return (NULL);
	s->player = p;
	s->next = NULL;
	return (s);
}
