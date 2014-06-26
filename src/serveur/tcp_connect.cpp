/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcp_connect.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 23:33:23 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/26 10:10:13 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tcp_connect.h"

int		tcp_connect::get_sock(){ return (this->sock); };
bool	tcp_connect::verbose(bool b){ this->v = (b == true) ? true : false; return (b); };

tcp_connect::tcp_connect()
{
	sock = -1;
	port = 0;
	address = NULL;
	v = false;
}

bool tcp_connect::connects(char *addr, char *port)
{
	struct protoent		*prot;
	struct sockaddr_in	sin;

	this->port = atoi(port);
	this->address = addr;
	if ((prot = getprotobyname("tcp")) == NULL)
		dprintf(2, "fail getprotobyname\n");
	if ((this->sock = socket(PF_INET, SOCK_STREAM, prot->p_proto)) == -1)
		dprintf(2, "fail socket\n");
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(this->address);
	sin.sin_port = htons(this->port);
	if (connect(this->sock,(struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		dprintf(2, "fail to connect\n");
		return(false);
	}
	return (true);
}

bool tcp_connect::sends(char *s, size_t size = 4096)
{
	if(sock != -1 && send(sock , s, size, 0) < 0)
		return (false);
	return (true);
}


