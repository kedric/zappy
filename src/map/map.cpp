/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 08:14:15 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/25 18:15:49 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/map.h"

map::map()
{
	this->x = 0;
	this->y = 0;
	this->m = NULL;
	this->nb_player = 1;
}

bool	map::init(int x, int y)
{
	if (x <= 1 || y <= 1)
		return (false);
	this->x = x;
	this->y = y;
	if ((this->m = (t_map **)malloc(sizeof(t_map *) * y + 1)) == NULL)
		return (false);
	this->m[y] = NULL;
	while (--y)
	{
		if ((this->m[y] = (t_map *)malloc(sizeof(t_map) * this->x)) == NULL)
			return (false);
		x = this->x;
		while (--x)
		{
			this->m[y][x].x = x;
			this->m[y][x].y = y;
			this->m[y][x].ps = NULL;
		}
	}
	return (true);
}

t_map *map::get_m(int x, int y)
{
	if (x >= this->x)
		x = x % this->x;
	else if (x < 0)
		x = this->x;
	if (y >= this->y)
		y = y % this->y;
	else if (y < 0)
		y = this->y;
	return (&this->m[y][x]);
}

bool	map::add_player(class player *p, int x, int y)
{
	s_lst_ps			*add;
	t_map			*m;
	s_lst_ps			*lst;

	add = (s_lst_ps *)malloc(sizeof(s_lst_ps));
	add->p = p;
	m = get_m(x, y);
	add->next = NULL;
	if (m->ps == NULL)
		m->ps = add;
	else
	{
		lst = m->ps;
		while(lst->next)
			lst = lst->next;
		lst->next = add;
	}
	return (true);
}

bool	map::destroy()
{
	int		y;

	y = this->y + 1;
	while (--y)
		free(this->m[y]);
	free(this->m);
	return (true);
}


