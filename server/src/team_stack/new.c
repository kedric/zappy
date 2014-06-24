/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:05:36 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 15:08:40 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "team_stack.h"

t_team_stack	*team_stack_new(void)
{
	t_team_stack	*s;

	if (!(s = (t_team_stack *)malloc(sizeof(t_team_stack))))
		return (NULL);
	s->count = 0;
	s->first = NULL;
	return (s);
}
