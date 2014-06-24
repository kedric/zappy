/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:33:14 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 16:46:19 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "world.h"

void	world_del(t_world **w)
{
	if (!w || !*w)
		return ;
	world_del_squares(&(*w)->squares, (*w)->width, (*w)->height);
	bzero(*w, sizeof(t_world));
	*w = NULL;
}
