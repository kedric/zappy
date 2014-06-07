/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 09:22:13 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/07 10:11:20 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

t_case	*init_case(int y, int x, t_env *env)
{
	t_case *ret;

	ret = (t_case *)XV(NULL, malloc(sizeof(t_case)), "create case");
	ret->x = x;
	ret->y = y;
	ret->linemate = 0;
	ret->deraumere = 0;
	ret->sibure = 0;
	ret->mendiane = 0;
	ret->phirase = 0;
	ret->thystame = 0;
	ret->nb_player = 0;
	ret->player = NULL;
	if (env->v)
		ft_printf("initialisation de la case x : %d, Y : %d \n", x, y);
	return (ret);
}

void	create_map(t_env *env)
{
	int	i;
	int	j;

	env->map = (t_case ***)XV(NULL, malloc(sizeof(t_case **) * env->x_max), "create map");
	i = -1;
	while (++i < env->x_max)
	{
		env->map[i] = (t_case **)XV(NULL, malloc(sizeof(t_case *) * env->y_max), "create row");
		j = -1;
		while (++j < env->y_max)
			env->map[i][j] = init_case(i, j, env);
	}
}
