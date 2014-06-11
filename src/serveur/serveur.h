/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 06:38:21 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/10 08:17:23 by jmancero         ###   ########.fr       */
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

# define FD_CLIENT 50
# define FD_SERV 100
# define BUFF_SIZE 4096
# define MAX(a,b)	((a > b) ? a : b)

typedef struct	s_team
{
	char		*name;
}				t_team;

typedef struct s_player
{
	int			type;
	int			x;
	int			y;
	void		(*fct_read)();
	void		(*fct_write)();
	char		save[BUFF_SIZE + 1];
	char		buff_read[BUFF_SIZE + 1];
	char		buff_write[BUFF_SIZE +1];
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
	t_player	*p;
	t_team		**team;
	t_case		***map;
	fd_set		fd_read;
	fd_set		fd_write;
	int			max;
	int			max_fd;
	int			ret;
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

void		init_serv(t_env *env);
void		check_fd(t_env *env);
void		do_select(t_env *env);
void		init_fd(t_env *e);

#endif
