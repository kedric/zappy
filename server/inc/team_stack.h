/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:00:40 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 15:31:25 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEAM_STACK_H
# define TEAM_STACK_H

typedef struct s_team_stack	t_team_stack;

# include "team.h"

struct	s_team_stack
{
	t_team	*first;
	int		count;
};

t_team_stack	*team_stack_new(void);
void	team_stack_del(t_team_stack **s);
void	team_stack_clear(t_team_stack *s);
void	team_stack_add(t_team_stack *s, t_team *t);
void	team_stack_remove(t_team_stack *s, t_team *t);

#endif
