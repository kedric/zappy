/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 11:56:36 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 12:01:13 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resource.h"

t_res_type	resource_type(char *name)
{
	if (*name == 'l')
		return (R_LINEMATE);
	if (*name == 'd')
		return (R_DERAUMERE);
	if (*name == 's')
		return (R_SIBUR);
	if (*name == 'm')
		return (R_MENDIANE);
	if (*name == 'p')
		return (R_PHIRAS);
	if (*name == 't')
		return (R_THYSTAME);
	return (R_FOOD);
}
