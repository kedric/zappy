/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 14:35:32 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 16:44:37 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

typedef struct s_world		t_world;

# include "square.h"

struct	s_world
{
	int			width;
	int			height;
	t_square	**squares;
};

t_world		*world_new(int width, int height);
t_square	**world_new_squares(int width, int height);
void	world_del(t_world **w);
void	world_del_squares(t_square ***s, int width, int height);

#endif
