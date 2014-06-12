/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 14:50:18 by jmancero          #+#    #+#             */
/*   Updated: 2014/06/12 09:57:55 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H
# include "world.h"
# include "team_stack.h"

# define PV_VALUE 1260
/*
** chaque action va etre partager en 3 fonction.
** 1-la premiere serviras a remplire la structure act.
** 2-la seconde permeteras de verifier la possibiliter de l action.
** 3-la troisieme permeteras d'apliquer l'action au plateau de jeux et creeras
** une reponce pour le client et le graphique.
*/

/*
** cette structure permet de gerrer la stack d'action a effectuer.
** on y trouver les parametre suivant
** le ptr sur la fonction a apliquer sur l action;
** le ptr sur la fonction de check lier a laction;
** les parametre sur la case actuel du joueur;
** les parametre sur la case affecter;
*/

typedef struct		s_act
{
	int				waiting;
	int				(*fct_do)();
	int				(*fct_check)();
	t_square		*to;
	t_square		*at;
	char			*msg_c;
	char			*msg_g;
	struct s_act	*next;
}					t_act;

/*
** la structure s_action va contenire la stack d action a efectuer
** on utilise la variable counte pour limiter le nombre daction que peut
** contenire la stack
*/

typedef struct		s_action
{
	t_act	*next;
	t_act	*last;
	int		count;
}					t_action;

/*
** .
** fonction a la racine du module action.
*/

void	do_turn(t_team_stack *team, t_world *world);
int		check_act(t_player *player, t_world *world);
void	init_new_turn(t_player *player);
void	do_act();
/*
** utils/
** toute ces fonction seron dans le dossier utils.
*/

int		lower_pv(t_life *life);
void	restore_pv(t_life *life);

#endif
