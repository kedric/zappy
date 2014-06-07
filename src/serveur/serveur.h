/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 06:38:21 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/07 10:05:59 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <sys/socket.h>
# include <netdb.h>
# include <sys/time.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/select.h>
# include <stdio.h>

typedef struct	s_team
{
	char		*name;
}				t_team;

typedef struct s_player
{
	int			sock;
	int			x;
	int			y;
	t_team		*team;
}				t_player;

typedef struct s_case
{
	int			x;
	int			y;
	int			linemate;
	int			deraumere;
	int			sibure;
	int			mendiane;
	int			phirase;
	int			thystame;
	int			nb_player;
	t_player	*player;
}				t_case;

typedef struct s_env
{
	int			v;
	int			port;
	int			x_max;
	int			y_max;
	int			t_d;
	int			t;
	int			c_start;
	t_team		**team;
	t_case		***map;
}				t_env;

/*
** main.c
*/
void	say_usage(char *name);

/*
** parse_av.c
*/
int		verbose(t_env *env, char **av, int i);
int		init_port(t_env *env, char **av, int i);
int		use_av(char **av, int i, t_env *env, int ret);
int		search_opt(char *av);
void	parse_av(char **av, int ac, t_env *env);

/*
** use_av.c
*/
int		init_x(t_env *env, char **av, int i);
int		init_y(t_env *env, char **av, int i);
int		init_n(t_env *env, char **av, int i);
int		init_c(t_env *env, char **av, int i);
int		init_t(t_env *env, char **av, int i);

/*
** init_map.c
*/
void	create_map(t_env *env);

#endif
