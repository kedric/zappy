/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 11:23:35 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 15:03:32 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEAM_H
# define TEAM_H

typedef struct s_team	t_team;

# include "player_stack.h"

struct	s_team
{
	int				id;
	char			*name;
	int				max;
	int				count;
	t_player_stack	*players;
	t_team			*next;
};

t_team	*team_new(int id, char *name, int max);
void	team_del(t_team **t);
void	team_add_player(t_team *t, t_player *p);
void	team_remove_player(t_team *t, t_player *p);

#endif
