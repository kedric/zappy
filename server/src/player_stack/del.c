/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:22:21 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 11:25:56 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "player_stack.h"

void	player_stack_del(t_player_stack **s)
{
	if (!s || !*s)
		return ;
	bzero(*s, sizeof(t_player_stack));
	free(*s);
	*s = NULL;
}
