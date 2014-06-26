/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 00:38:11 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/26 09:52:18 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include "zappy.h"

class game
{
private:
	int				x;
	int				y;
	char			*port;
	char			*addr;
	int				max_map;
	struct s_lst_p	*p;
	struct s_lst_p	*p_last;
	int				p_max;
	void			check_fd(class player *p);
	void			init_fd();
	fd_set			fd_read;
	fd_set			fd_write;
	int				ret;
	class map		*map;



public:
	game();
	int				p_count;
	bool			finish;
	char			*team;
	void	init(char *addr, char *port, char *team);
	int		get_x();
	int		get_y();
	class map	*get_map();
	void		set_map(class map *m);
	void	set_y(int y);
	void	set_x(int x);
	void	set_p_max(int nb);
	int		get_p_max();
	bool	add_player();
	void	do_game(class palyer *p);
	void	init_fd(class player *p);
	bool	init_port(char *port);
	bool	init_addr(char *addr);
	char	*get_addr();
	char	*get_port();
	string	get_team();
	bool	do_select();
	bool	fork();
};

#endif
