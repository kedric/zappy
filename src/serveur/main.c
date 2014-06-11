/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 06:23:14 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/10 08:18:06 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	say_usage(char *name)
{
	ft_dprintf(2, "%s, usage : %s", name, name);
	ft_dprintf(2, "-p <port> -x <width> -y <height> ");
	ft_dprintf(2, "-n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
	ft_dprintf(2, "-p numero de port\n");
	ft_dprintf(2, "-x largeur du Monde\n");
	ft_dprintf(2, "-y hauteur du Monde\n");
	ft_dprintf(2, "-n nom\\_equipe\\_1 nom\\_\\_equipe_2 ...\n");
	ft_dprintf(2, "-c nombre de client autorises au commencement du jeu\n");
	ft_dprintf(2, "-t diviseur de l'unite de temps ");
	ft_dprintf(2, "(plus t est grand, plus le jeu va vite)\n");
	exit(-1);
}

void	init_env(t_env *env, char *name)
{
	struct rlimit	rlp;

	env->v = 0;
	env->port = 0;
	env->x_max = 0;
	env->y_max = 0;
	env->t_d = 0;
	env->t = 1000000;
	env->c_start = 0;
	env->team = NULL;
	env->map = NULL;
	if (getrlimit(RLIMIT_NOFILE, &rlp))
		fprintf(stderr, "%s, fail to get limit\n", name);
	env->max_fd = rlp.rlim_cur;
	if ((env->p = (t_player *)malloc(sizeof(t_player) * env->max_fd)) == NULL)
		fprintf(stderr, "%s, fail to malloc env->p\n", name);
}

int		main(int ac, char **av)
{
	t_env	env;

//	if (ac < 7)
//		say_usage(av[0]);
	init_env(&env, av[0]);
	parse_av(av, ac,&env);
	create_map(&env);
	init_serv(&env);
	while (1)
	{
		init_fd(&env);
		do_select(&env);
		check_fd(&env);
	}
	return (0);
}
