/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 14:32:15 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 14:33:21 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2 && c && n)
	{
		while (i < n)
		{
			*((char *)s1 + i) = *((char *)s2 + i);
			if (*((char *)s2 + i) == (unsigned char)c)
				return ((char *)s1 + i + 1);
			i++;
		}
	}
	return (NULL);
}
