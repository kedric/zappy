/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receve.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 09:17:58 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/26 10:16:32 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tcp_connect.h"

bool tcp_connect::recvs(char *buf, size_t size)
{
	bzero(buf, size);
	if(recv(this->sock , buf , size - 1 , 0) < 0)
		return (false);
	if (this->v == true)
		printf("< %s", buf);
	return (true);
}
