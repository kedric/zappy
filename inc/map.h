/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 08:09:44 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/25 18:15:48 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "zappy.h"
struct			s_lst_ps
{
	class player		*p;
	struct s_lst_ps		*next;
};

typedef struct		s_map
{
	int				x;
	int				y;
	s_lst_ps		*ps;
}					t_map;

class map
{
private:
	int				x;
	int				y;
	t_map			**m;
	struct s_lst_p	*p;
	int				nb_player;


public:
	map();
	bool init(int x, int y);
	t_map *get_m(int x, int y);
	bool destroy();
	bool add_player(class player *p, int x, int y);
	bool rm_player(class player *p, int x, int y);
};

#endif
