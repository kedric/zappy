/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 11:37:40 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 11:40:10 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resource.h"

void	resource_remove(t_resource *r, t_res_type t, int quantity)
{
	if (r[t] >= quantity)
		r[t] -= quantity;
	else
		r[t] = 0;
}
