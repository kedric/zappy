/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 07:01:48 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/07 08:46:50 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		init_port(t_env *env, char **av, int i)
{
	if (av[i + 1])
		env->port = ft_atoi(av[i + 1]);
	if (env->port > 0)
	{
		ft_printf("port du serveur = %d\n", env->port);
		return (i + 1);
	}
	return (-1);
}

int		verbose(t_env *env, char **av, int i)
{
	(void)av;
	env->v = 1;
	ft_printf("mode verbose activer\n");
	return (i);
}

int		use_av(char **av, int i, t_env *env, int ret)
{
	int (*ptf[7])(t_env *env, char **av, int i);
	ptf[0] = init_port;
	ptf[1] = init_x;
	ptf[2] = init_y;
	ptf[3] = init_n;
	ptf[4] = init_c;
	ptf[5] = init_t;
	ptf[6] = verbose;

	i = ptf[ret](env, av, i);
	return (i);
}

int		search_opt(char *av)
{
	char	*opt;
	int		ret;

	opt = "pxynctv";
	ret = 0;

	while (opt[ret] && opt[ret] != av[1])
		ret++;
	if (ret > 6)
			ret = -1;
	return (ret);
}

void	parse_av(char **av, int ac, t_env *env)
{
	int		i;
	int		ret;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if ((ret = search_opt(av[i])) != -1)
				i = use_av(av, i, env, ret);
			else
			{
				ft_dprintf(2,"invalide argument : %s\n", av[i]);
				say_usage(av[0]);
			}
		}
		i++;
	}
}
