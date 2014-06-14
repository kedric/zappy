/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 10:35:45 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/14 10:38:31 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"
#include <stdio.h>

char	*ft_sprintf(char *s,char const *str, ...)
{
	va_list	args;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 's')
		{
			ft_strcat(s, va_arg(args, char*));
			i = i + 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'd')
		{
			tmp = ft_itoa(va_arg(args, int));
			ft_strcat(s, tmp);
			tmp = NULL;
			i = i + 2;
		}
		else
			s[ft_strlen(s)] = str[i++];
	}
	va_end(args);
	return (s);
}
