/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 14:32:15 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 14:34:43 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*str1;
	char			*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (s1 && s2)
	{
		while (((str1[i] != '\0') && (n > i))\
			|| (((str2[i]) != '\0') && (n > i)))
		{
			if (str1[i] != str2[i])
				return ((unsigned char)str1[i] - (unsigned char)str2[i]);
			i++;
		}
		return (0);
	}
	return (-1);
}
