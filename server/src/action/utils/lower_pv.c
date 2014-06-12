/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_pv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 09:09:09 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 09:59:01 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

/*
** cette fonction rajoute un tour depuis la dernier foit ou le joueur a manger
*/

int		lower_pv(t_life *life)
{
	life->turn++;
	life->pv = (PV_VALUE - life->turn) / (PV_VALUE / 10);
	if ((PV_VALUE - life->turn) % (PV_VALUE / 10) != 0)
		life->pv++;
	if (life == 0)
		return (-1);
	return (0);
}
