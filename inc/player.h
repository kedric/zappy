/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 08:06:54 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/26 03:33:45 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#include "zappy.h"

#define P_INIT 0
#define P_WAIT_NBB 1
#define P_WAIT_NB 1
#define P_FIRST 2
#define WAIT_NEW_CMD 4
#define WAIT_REP 5

#define BUF_SIZE 4096
class player;

struct			s_lst_p
{
	class player		*p;
	struct s_lst_p		*next;
};

struct			s_etat
{
	int			etat;
	void		(*fnc)();
	string		msg;
};

struct					s_buf
{
	char				msg[BUF_SIZE + 1];
	struct s_buf		*next;
};

class player
{
private:
	int					id;
	int					etat;
	bool					first;
	class tcp_connect	*c;
	class map			*map;
	class game			*g;
	struct s_buf		*buf_recv;
	struct s_buf		*buf_send;
	void				recup_nb(char *s);




public:
			player();
	bool	init(class game *g);
	bool	send_team();
	void	send();
	void	add_send(const char *);
	int		get_id();
	void	recv();
	char	*get_read();
	int		get_send_len();
	void	add_buff(struct s_buf *buf,struct s_buf *lst);
	void	add_to_end(struct s_buf* add, struct s_buf *lst);
	void	do_turn();
	void	parse(char *s);
	void	message(char *s);
	void	to_origine(int to);

};

#endif
