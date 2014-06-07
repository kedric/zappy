/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 14:32:16 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 14:32:16 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i1;
	unsigned int	i2;

	i1 = 0;
	if (ft_strlen(s2) == 0)
	{
		return ((char *)s1);
	}
	while (i1 < n && s1[i1] != '\0')
	{
		i2 = 0;
		while ((i1 + i2) < n && s1[i1 + i2] != '\0' && s2[i2] != '\0'
				&& s2[i2] == s1[i1 + i2])
		{
			i2++;
		}
		if (s2[i2] == '\0')
		{
			return ((char *)s1 + i1);
		}
		i1++;
	}
	return (NULL);
}
