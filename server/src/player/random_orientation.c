/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:10:06 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 12:13:00 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "player.h"

t_orient	player_random_orientation(void)
{
	t_orient	o;

	o = rand() % 4 + 1;
	return (o);
}
