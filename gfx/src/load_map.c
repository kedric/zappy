/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 17:50:07 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/10 19:42:34 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_vec	grid_to_world(int x, int y, int map_x, int map_y)
{
	t_vec p;

	p.x = -((map_x * TILE_X) / 2) + (TILE_X * x);
	p.y = 0.f;
	p.z = -((TILE_X * y));
	return (p);
}

t_tile	**init_tiles(int x, int y)
{
	t_tile	**map;
	int		ix;
	int		iy;

	map = (t_tile **)malloc(sizeof(t_tile *) * y);
	iy = -1;
	while (++iy < y)
	{
		ix = -1;
		map[iy] = (t_tile *)malloc(sizeof(t_tile) * x);
		while (++ix < x)
		{
			map[iy][ix].players = NULL;
			map[iy][ix].ressources = NULL;
		}
	}
	return (map);
}

void	add_player(t_circ_lst **lst, int id)
{
	t_player	*player;
	t_circ_lst	*new;

	player = (t_player *)malloc(sizeof(t_player));
	player->id = id;
	player->moving = 0;
	player->ressources = NULL;
	new = new_elem_circular((void *)player, PLAYER);
	add_begin_circular(lst, new);
}

t_vec	random_pos(int x, int y, int map_x, int map_y)
{
	t_vec	p;

	p = grid_to_world(x, y, map_x, map_y);
	p.x += (float)(rand() % 20) - 10.f;
	p.z += (float)(rand() % 20) - 10.f;
	return (p);
}

void	add_ressource(t_circ_lst **lst, int ressource, t_vec p)
{
	t_ressource	*rs;
	t_circ_lst	*new;

	rs = (t_ressource *)malloc(sizeof(t_ressource));
	rs->pos_in_tile = p;
	rs->type = ressource;
	new = new_elem_circular((void *)rs, ressource);
	add_begin_circular(lst, new);
}

void	init_map(t_scene *scene, int x, int y)
{
	scene->map = init_tiles(x, y);
	scene->map_x = x;
	scene->map_y = y;
	add_player(&scene->map[4][4].players, 0);
	add_player(&scene->map[1][10].players, 0);
	add_player(&scene->map[10][4].players, 0);
}
