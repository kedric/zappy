/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 10:38:29 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 15:02:24 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

/*
** reduit d'un tour l attente avant l'action.
*/

void		lower_action(t_act *act)
{
		act->waiting--;
}
