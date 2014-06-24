/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:37:46 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 13:41:15 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "player_stack.h"

void	player_stack_del_player(t_player_stack **s)
{
	if (!s || !*s)
		return ;
	player_del(&(*s)->player);
	bzero(*s, sizeof(t_player_stack));
	free(*s);
	s = NULL;
}
