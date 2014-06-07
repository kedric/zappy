/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 14:32:15 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 14:33:49 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	if (s)
	{
		str = s;
		while (n-- > 0)
		{
			if (*str == (unsigned char)c)
				return ((void *)str);
			str++;
		}
	}
	return (NULL);
}
