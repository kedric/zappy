/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 00:41:04 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/26 09:52:35 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"
#include <time.h>
#include <unistd.h>

game::game()
{
	this->x = 0;
	this->y = 0;
	p_count = 0;
	this->max_map = 0;
	this->port = NULL;
	this->addr = NULL;
	this->p_max = 0;
	this->p = NULL;
	this->p_last = NULL;
	this->team = NULL;
	this->ret = 0;
	this->finish = false;
}

void game::init(char *addr, char *port, char *team)
{
	player *p;

	this->team = team;
	this->init_port(port);
	this->init_addr(addr);
	this->add_player();
	printf("init new game ok\n");
}

int			game::get_x() { return (this->x); }
int			game::get_y() { return (this->y); }
void		game::set_x(int x) { this->x = x; }
void		game::set_y(int y) { this->y = y; }
void		game::set_p_max(int nb) { this->p_max = nb; }
int			game::get_p_max(){ return (this->p_max); }
char		*game::get_port() { return (this->port); }
char		*game::get_addr() { return (this->addr); }
string		game::get_team() { return (this->team); }
class map	*game::get_map() {return (this->map); }
void		game::set_map(class map *m){ this->map = m; }
bool		game::fork(){return ((this->p_max > 1) ? true: false);}

bool game::init_port(char *port)
{
	this->port = port;
	return (true);
}

bool game::add_player()
{
	struct s_lst_p *p_tmp;

	p_tmp = (struct s_lst_p *)malloc(sizeof(struct s_lst_p));
	p_tmp->p = new(class player);
	p_tmp->p->init(this);
	p_tmp->next = NULL;
	if (this->p == NULL)
	{
		this->p = p_tmp;
		this->p_last = p_tmp;
		this->p_max = p_tmp->p->get_id();
		return (true);
	}
	this->p_last->next = p_tmp;
	this->p_last = p_tmp;
	this->p_max--;
	return (true);
}

bool game::init_addr(char *addr)
{
	this->addr = addr;
	return (true);
}

void	game::check_fd(class player *p)
{
	if (FD_ISSET(p->get_id(), &this->fd_read))
		p->recv();
	if (FD_ISSET(p->get_id(), &this->fd_write))
		p->send();
	if (FD_ISSET(p->get_id(), &this->fd_read) || FD_ISSET(p->get_id(), &this->fd_write))
		this->ret--;
}

void	game::init_fd(class player *p)
{
		FD_SET(p->get_id(), &this->fd_read);
		if (p->get_send_len() > 0)
			FD_SET(p->get_id(), &this->fd_write);
}

bool	game::do_select()
{
	struct s_lst_p *p;
	int c;
	struct timeval	timev;
	int				i;

	timev.tv_sec = 0;
	timev.tv_usec = 100;
	p = this->p;

		FD_ZERO(&this->fd_read);
		FD_ZERO(&this->fd_write);
	while (p)
	{
		i = p->p->get_id();

		this->init_fd(p->p);
		p = p->next;
	}
	this->ret = select(i + 1 , &this->fd_read, &this->fd_write, NULL, &timev);
	p = this->p;
	while (p)
	{
		check_fd(p->p);
		p->p->do_turn();
		p = p->next;
	}

	return (true);
}
