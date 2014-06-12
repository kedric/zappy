/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 11:37:39 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 11:33:08 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

typedef struct s_square		t_square;

# include "player_stack.h"
# include "resource.h"

struct	s_square
{
	int				x;
	int				y;
	t_player_stack	*players;
	t_resource		*resources;
};

t_square	*square_new(int x, int y);
void		square_del(t_square **s);
void	square_add_player(t_square *s, t_player *p);
void	square_remove_player(t_square *s, t_player *p);

#endif
