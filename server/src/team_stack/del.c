/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:09:26 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 15:21:41 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "team_stack.h"

void	team_stack_del(t_team_stack **s)
{
	if (!s || !*s)
		return ;
	team_stack_clear(*s);
	bzero(*s, sizeof(t_team_stack));
	free(*s);
	*s = NULL;
}
