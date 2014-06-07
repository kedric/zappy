/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_av.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 07:47:31 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/07 09:31:14 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		init_x(t_env *env, char **av, int i)
{
	if (av[i + 1])
		env->x_max = ft_atoi(av[i + 1]);
	if (env->x_max <= 0)
	{
		ft_dprintf(2, "invalide argument -x > 0\n");
		say_usage(av[0]);
	}
	ft_printf("taille x = %d\n", env->x_max);
	return (i + 1);
}

int		init_y(t_env *env, char **av, int i)
{
	if (av[i + 1])
		env->y_max = ft_atoi(av[i + 1]);
	if (env->y_max <= 0)
	{
		ft_dprintf(2, "invalide argument -y > 0\n");
		say_usage(av[0]);
	}
	ft_printf("taille y = %d\n", env->y_max);
	return (i + 1);
}

int		creat_new_team(t_env *env, char *name)
{
	int	i;

	i = 0;
	while (env->team[i] != NULL && ft_strcmp(env->team[i]->name, name) != 0)
		i++;
	if (env->team[i] != NULL)
	{
		ft_dprintf(2, "Deux equipe ne peuvent pas avoir le meme nom\n");
		exit(-1);
	}
	else
	{
		env->team[i] = (t_team *)malloc(sizeof(t_team));
		env->team[i]->name = name;
		ft_printf("New team add : %s\n", env->team[i]->name);
	}
	return (0);
}

int		init_n(t_env *env, char **av, int i)
{
	int	count;
	int	j;

	if (env->team == NULL)
	{
		count = 1;
		while (av[i + count] && av[i + count][0] != '-')
			count++;
		env->team = (t_team **)malloc(sizeof(t_team *) * count);
		j = count;
		while (--j != -1)
			env->team[j] = NULL;
		while (++j != count - 1)
			creat_new_team(env, av[i + 1 + j]);
		return (i + count - 1);
	}
	else
	{
		ft_dprintf(2, "les equipes ne peuvent pas etre definie deux fois\n");
		exit(-1);
	}
	return (0);
}

int		init_c(t_env *env, char **av, int i)
{
	if (av[i + 1])
		env->c_start = ft_atoi(av[i + 1]);
	if (env->c_start <= 0)
	{
		ft_dprintf(2, "invalide argument -c > 0\n");
		say_usage(av[0]);
	}
	ft_printf("nombre d'equipe au demarage = %d\n", env->c_start);
	return (i + 1);
}

int		init_t(t_env *env, char **av, int i)
{
	if (av[i + 1])
		env->t_d = ft_atoi(av[i + 1]);
	if (env->t_d < 0)
	{
		ft_dprintf(2, "invalide argument -t >= 0\n");
		say_usage(av[0]);
	}
	ft_printf("time = %d\n", env->t_d);
	if (env->t_d != 0)
		env->t = 1000000 / env->t_d;
	if (env->v)
		ft_printf("time en usec : %d\n", env->t);
	return (i + 1);
}
