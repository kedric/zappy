/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 14:21:16 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 11:34:25 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "square.h"

void	square_del(t_square **s)
{
	if (!s || !*s)
		return ;
	player_stack_clear(&(*s)->players, player_stack_del);
	resource_del(&(*s)->resources);
	bzero(*s, sizeof(t_square));
	free(*s);
	*s = NULL;
}
