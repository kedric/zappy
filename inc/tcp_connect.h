/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcp_connect.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 23:36:52 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/26 10:15:30 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCP_CONNECT_H
#define TCP_CONNECT_H

#include "zappy.h"

struct		s_str
{
	char			*str;
	struct	s_str	*next;
};

struct		s_str_s
{
	char			*first;
	struct	s_str	*last;
	int				count;
};


class tcp_connect
{
private:
	int					v;
	int					sock;
	char				*address;
	int					port;
	struct	sockaddr_in	server;
	struct	s_str_s		buf_r;
	struct	s_str_s		buf_s;



public:
	tcp_connect();
	bool		verbose(bool b);
	int			get_sock();
	bool		connects(char *, char *);
	bool		sends(char *s, size_t size);
	bool		recvs(char *buf, size_t size);
	void		close();
};

#endif
