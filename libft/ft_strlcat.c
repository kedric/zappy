/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 14:32:16 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/04 14:32:16 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*dst;
	const char	*source;
	size_t		len;
	size_t		dst_len;

	dst = dest;
	source = src;
	len = size;
	while (len-- != 0 && *dst != '\0')
		dst++;
	dst_len = dst - dest;
	len = size - dst_len;
	if (len == 0)
		return (dst_len + ft_strlen(source));
	while (*source != '\0')
	{
		if (len != 1)
		{
			*dst++ = *source;
			len--;
		}
		source++;
	}
	*dst = '\0';
	return (dst_len + (source - src));
}
