/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 11:47:47 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/04 13:57:10 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_STACK_H
# define PLAYER_STACK_H

typedef struct s_player_stack	t_player_stack;

# include "player.h"

struct			s_player_stack
{
	t_player		*player;
	t_player_stack	*next;
};

t_player_stack	*player_stack_new(t_player *p);
void			player_stack_del(t_player_stack **s);
void		player_stack_del_player(t_player_stack **s);
void	player_stack_clear(t_player_stack **s, void (*f)(t_player_stack **));
void			player_stack_add(t_player_stack **s, t_player *p);
void	player_stack_remove(t_player_stack **s, t_player *p, void (*f)(t_player_stack **));
int				player_stack_count(t_player_stack *s, int (*f)(t_player *));

#endif
