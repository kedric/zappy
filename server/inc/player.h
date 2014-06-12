/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 11:25:20 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/12 10:51:07 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef enum e_orientation	t_orient;
typedef struct s_player		t_player;

# include "team.h"
# include "square.h"
# include "resource.h"
# include "action.h"

# define PLAYER_START_LIFE 10
# define PLAYER_START_LEVEL 1
# define PLAYER_MAX_LEVEL 8

enum	e_orientation
{
	O_NORTH = 1,
	O_EAST = 2,
	O_SOUTH = 3,
	O_WEST = 4,
};

typedef struct	s_life
{
	int			pv;
	int			turn;
}				t_life;

struct	s_player
{
	int			id;
	int			level;
	int			life;
	t_life		pv;
	t_orient	orientation;
	t_action	*action;
	t_square	*square;
	t_team		*team;
	t_resource	*resources;
};

t_player	*player_new(int id, t_team *t, t_square *s);
void		player_del(t_player **p);
t_orient	player_random_orientation(void);
int	player_max_level(t_player *p);

#endif
