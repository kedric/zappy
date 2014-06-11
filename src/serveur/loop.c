/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 10:57:13 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/10 08:10:32 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	check_fd(t_env *env)
{
	int	i;

	i = 0;
	while ((i < env->max_fd) && (env->ret > 0))
	{
		if (FD_ISSET(i, &env->fd_read))
			env->p[i].fct_read(env, i);
		if (FD_ISSET(i, &env->fd_write))
			env->p[i].fct_write(env, i);
		if (FD_ISSET(i, &env->fd_read) || FD_ISSET(i, &env->fd_write))
			env->ret--;
		i++;
	}
}

void	do_select(t_env *env)
{
	struct timeval tv;

	tv.tv_sec = 0;
	tv.tv_usec = 1000;
	env->ret = select(env->max + 1, &env->fd_read, &env->fd_write, NULL, &tv);
}

void	init_fd(t_env *e)
{
	int		i;

	i = 0;
	e->max = 0;
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	while (i < e->max_fd)
	{
		if (e->p[i].type != 0)
		{
			FD_SET(i, &e->fd_read);
			if (strlen(e->p[i].buff_write) > 0)
				FD_SET(i, &e->fd_write);
			e->max = MAX(e->max, i);
		}
		i++;
	}
}
