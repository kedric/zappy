/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 11:08:10 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 11:32:25 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include "resource.h"

t_resource	*resource_new(void)
{
	t_resource	*r;

	if (!(r = (t_resource *)malloc(sizeof(t_resource) * RESOURCE_COUNT)))
		return (NULL);
	bzero(r, RESOURCE_COUNT);
	return (r);
}
