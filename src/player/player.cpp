/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 08:06:16 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/26 10:17:54 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/player.h"
#include <unistd.h>
#include <time.h>

player::player()
{
	this->id = 0;
	this->map = NULL;
	this->c = NULL;
	this->buf_send = NULL;
	this->etat = false;
}

int			player::get_id() { return (this->id); }
int			player::get_send_len(){ return ((this->buf_send != NULL) ? 1 : 0); }


bool		player::init(class game *g)
{
	this->g = g;

	this->map = g->get_map();
	printf("init player\n");
	this->c = new(class tcp_connect);
	if (this->c->connects(g->get_addr(), g->get_port()) == false)
	{
		dprintf(2 ,"fail to connect\n");
	}
	this->id = this->c->get_sock();
	g->p_count = this->id;
	this->send_team();
	return (true);
}

void		player::add_to_end(struct s_buf* add, struct s_buf *lst)
{
	while (lst->next)
		lst = lst->next;
	lst->next = add;
}


void		player::add_send(const char *str)
{
	struct s_buf *buf;

	buf = (struct s_buf *)malloc(sizeof(struct s_buf));
	buf->next = NULL;
	if (this->buf_send == NULL)
		this->buf_send = buf;
	else
		this->add_to_end(buf, this->buf_send);
	bzero(buf->msg, BUF_SIZE);
	sprintf(buf->msg, "%s", str);
}


bool		player::send_team()
{
	this->add_send(this->g->team);
	return (true);
}

void		player::send()
{
	struct s_buf *tmp;
	while (this->buf_send)
	{
		sprintf(this->buf_send->msg, "%s\n",this->buf_send->msg);
		c->sends(this->buf_send->msg, sizeof(this->buf_send->msg));
		tmp = this->buf_send;
		this->buf_send = this->buf_send->next;
		free(tmp);
	}
}

void		player::recup_nb(char *s)
{
	int nb = -1;
	int x;
	int y;


	if (this->etat == P_INIT)
	{
		printf("x : %d y: %d\n",this->g->get_x(),this->g->get_y());

		sscanf(s, "%d %d", &x, &y);
		if (this->g->get_x() == 0)
			nb = -2;
		this->g->set_x(x);
		this->g->set_y(y);
		if (nb == -2)
		{
			this->map = new(class map);
			this->first = true;
			this->map->init(this->g->get_x(), this->g->get_y());
			this->map->add_player(this, 1, 1);
			this->etat = WAIT_NEW_CMD;
			printf("----init new map -----\n");
		}
		printf("game set max player : %d\n", nb);
		this->etat = WAIT_NEW_CMD;
	}
	else
	{
		sscanf(s, "%d\n", &nb);
		if (this->etat == P_WAIT_NBB)
			this->etat = P_INIT;
		else
			this->etat = WAIT_NEW_CMD;
		this->g->set_p_max(nb);
		return;
	}
	printf("%s\n", s);
}

void		player::to_origine(int to)
{
	if (to == 1 || to == 2 || to == 8)
		add_send("avancer");
	if (to == 4 || to == 5 || to == 6 || to == 3)
		add_send("gauche");
	else
		add_send("droite");
	this->etat = WAIT_REP ;

}
void		player::message(char *s)
{
	int direct;
	int pid;
	char rest[4096];

	sscanf(s, "message %d, %d %s\n", &direct, &pid, rest);
	printf("rest = %s\n" , rest);
	if (pid != getpid())
		return;
	if (strncmp(rest, "ici", 3) == 0)
		to_origine(direct);
}

void		player::parse(char *s)
{
	printf("tretement %s\n", s);
	if (strncmp("BIENVENUE", s, 9) == 0)
		this->etat = P_WAIT_NBB;
	else if (atoi(s) > 0)
		this->recup_nb(s);
	else if(strncmp("ok", s, 2) == 0)
		this->etat = WAIT_NEW_CMD;
	else if(strncmp("ko", s, 2) == 0)
		this->etat = WAIT_NEW_CMD;
	else if (strncmp("message", s, 7) == 0)
		this->message(s);
}

void		player::recv()
{
	char	buf[BUF_SIZE + 1];
	char	tmp[BUF_SIZE + 1];
	int		j;
	int		i;

	if (c->recvs(buf, BUF_SIZE) == false)
		return;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			this->parse(tmp);
			j = 0;
			i++;
			continue;
		}
		tmp[j] = buf[i];
		tmp[j+ 1] = 0;
		j++;
		i++;
	}
}

void		player::do_turn()
{
	char s[50];

	//printf("do_turn(%d)\n", this->get_id());
	if (this->etat == WAIT_NEW_CMD)
	{
		if (this->first == true)
			sprintf(s, "broadcast %d ici", getpid());
		else
			sprintf(s,"avancer");
		this->add_send(s);
		this->etat = WAIT_REP;
	}
}
