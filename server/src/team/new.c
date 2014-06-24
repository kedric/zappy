/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:54:50 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 15:03:47 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "team.h"

t_team	*team_new(int id, char *name, int max)
{
	t_team	*t;

	if (!(t = (t_team *)malloc(sizeof(t_team))))
		return (NULL);
	t->id = id;
	t->max = max;
	t->count = 0;
	t->players = NULL;
	t->next = NULL;
	t->name = strdup(name);
	if (!t->name)
		team_del(&t);
	return (t);
}
