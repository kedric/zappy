/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 14:32:16 by jmancero          #+#    #+#             */
/*   Updated: 2014/05/28 11:08:39 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_puterr(char *s)
{
	if (s)
		write (2, s, ft_strlen(s));
}

void	ft_errorexit(char *s)
{
	if (s)
		write (2, s, ft_strlen(s));
	write (2, "\n", 1);
	_Exit(-1);
}

t_error		e_i(char *file, int line)
{
	t_error	err;

	err.file = file;
	err.line = line;
	return (err);
}

int			x_int(int err, int res, char *str, t_error e)
{
	if (res == err)
	{
		ft_fprintf(2, "%s error (%s, %d)\n", str, e.file, e.line);
		exit (1);
	}
	return (res);
}

void		*x_void(void *err, void *res, char *str, t_error e)
{
	if (res == err)
	{
		ft_fprintf(2, "%s error (%s, %d)\n", str, e.file, e.line);
		exit (1);
	}
	return (res);
}
