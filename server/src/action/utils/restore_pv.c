/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_pv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 09:46:13 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 09:53:50 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

/*
** fonction a appeler quand un joueur se connect ou mange
** se qui lui remet tout ses pv.
*/

void	restore_pv(t_life *life)
{
	life->pv = 10;
	life->turn = 0;
}
