/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quantity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 12:01:34 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 12:03:18 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resource.h"

int	ressource_quantity(t_resource *r, t_res_type t)
{
	return (r[t]);
}
