/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 23:52:02 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/26 04:26:43 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/zappy.h"
#include <unistd.h>

int main(int ac , char **av)
{
	game		*g;
	tcp_connect *c;
	char		i;


	g = new(game);
	if (ac != 4)
	{
		printf("usage\n");
		exit(0);
	}
	g->init(av[1], av[2], av[3]);
	while (g->finish != true)
	{
		g->do_select();
		if (g->fork() == true)
		{
			g->add_player();
		}
	}
	return (0);
}
