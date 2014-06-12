/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:08:50 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 11:31:22 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "player.h"

void	player_del(t_player **p)
{
	if (!p || !*p)
		return ;
	resource_del(&(*p)->resources);
	bzero(*p, sizeof(t_player));
	free(*p);
	*p = NULL;
}
