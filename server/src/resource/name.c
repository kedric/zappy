/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 11:42:08 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 12:01:14 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "resource.h"

static const char	*g_names[RESOURCE_COUNT] =
{
	[R_FOOD] = RN_FOOD,
	[R_LINEMATE] = RN_LINEMATE,
	[R_DERAUMERE] = RN_DERAUMERE,
	[R_SIBUR] = RN_SIBUR,
	[R_MENDIANE] = RN_MENDIANE,
	[R_PHIRAS] = RN_PHIRAS,
	[R_THYSTAME] = RN_THYSTAME,
};

char	*resource_name(t_res_type t)
{
	return (strdup(g_names[t]));
}
