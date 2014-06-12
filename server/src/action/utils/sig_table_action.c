/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_table_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 11:14:50 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 15:16:07 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include <stddef.h>

static void				init_fct(t_table_action *ret)
{
	ret->fct_init[MOOVE] = init_moove;
	ret->fct_init[RIGHT] = init_right;
	ret->fct_init[LEFT] = init_left;
	ret->fct_init[VIEW] = NULL;
	ret->fct_init[INVENTORY] = NULL;
	ret->fct_init[TAKE] = init_take;
	ret->fct_init[PUT] = init_put;
	ret->fct_init[DEPORT] = NULL;
	ret->fct_init[BROADCAST] = NULL;
	ret->fct_init[CAST] = NULL;
	ret->fct_init[FORK] = NULL;
	ret->fct_init[CNT] = NULL;
}

static t_table_action		*init_tab_act(void)
{
	static t_table_action ret;

	init_fct(&ret);
	return (&ret);
}

t_table_action		*sig_tab_act(void)
{
	static t_table_action *sig = NULL;

	if (sig == NULL)
		sig = init_tab_act();
	return (sig);
}
