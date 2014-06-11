/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:03:40 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/11 11:01:45 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	client_read(t_env *env, int cs)
{
	int	ret;

	ret = recv(cs, env->p[cs].buff_read, BUFF_SIZE, 0);
	env->p[cs].buff_read[ret] = 0;
	if (ret <= 0)
	{
		close(cs);
		env->p[cs].type = 0;
		env->p[cs].fct_read = NULL;
		env->p[cs].fct_write = NULL;
		ft_bzero(env->p[cs].save, BUFF_SIZE + 1);
		printf("client #%d disconected\n", cs);
	}
	else
	{
		// if (print_pkg(env, cs, ret))
		// {
		// 	free(env->p[cs].save);
		// 	ft_bzero(env->p[cs].save, BUFF_SIZE + 1);
		// }
	}
}

void	client_write(t_env *env, int cs)
{
	send(cs, env->p[cs].buff_write, ft_strlen(env->p[cs].buff_write), 0);
	ft_bzero(env->p[cs].buff_write, BUFF_SIZE);
}

void		new_client(t_env *env, int s)
{
	int					cs;
	struct				sockaddr_in	csock_in;
	socklen_t			csock_len;

	csock_len = sizeof(csock_in);
	cs = X(-1, accept(s, (struct sockaddr *)&csock_in, &csock_len), "accept");
	env->p[cs].type = FD_CLIENT;
	env->p[cs].fct_read = client_read;
	env->p[cs].fct_write = client_write;
	ft_bzero(env->p[cs].save, BUFF_SIZE + 1);
	printf("New client %d from %s:%d\n", cs
		, inet_ntoa(csock_in.sin_addr), ntohs(csock_in.sin_port));
	ft_strcat(env->p[cs].buff_write, "BIENVENUE\n");

}

void		init_serv(t_env *env)
{
	int				sock;
	struct	sockaddr_in	sock_in;
	struct	protoent	*prot;

	prot = (struct protoent *)XV(NULL, getprotobyname("tcp"), "getprotobyname");
	sock = X(-1, socket(PF_INET, SOCK_STREAM, prot->p_proto), "socket");
	sock_in.sin_family = AF_INET;
	sock_in.sin_addr.s_addr = INADDR_ANY;
	sock_in.sin_port = htons(env->port);
	X(-1, bind(sock, (struct sockaddr *)&sock_in, sizeof(sock_in)), "bind");
	X(-1, listen(sock, 42), "listen");
	env->p[sock].type = FD_SERV;
	env->p[sock].fct_read = new_client;
}
