/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 11:23:36 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 11:32:23 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "resource.h"

void	resource_del(t_resource **r)
{
	if (!r || !*r)
		return ;
	bzero(*r, RESOURCE_COUNT);
	free(*r);
	*r = NULL;
}
