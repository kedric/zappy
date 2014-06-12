/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 11:00:38 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/11 12:03:12 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCE_H
# define RESOURCE_H

typedef int				t_resource;
typedef enum e_resource	t_res_type;

# define RESOURCE_COUNT 7
# define RN_FOOD "nourriture"
# define RN_LINEMATE "linemate"
# define RN_DERAUMERE "deraumere"
# define RN_SIBUR "sibur"
# define RN_MENDIANE "mendiane"
# define RN_PHIRAS "phiras"
# define RN_THYSTAME "thystame"

enum	e_resource
{
	R_FOOD = 0,
	R_LINEMATE = 1,
	R_DERAUMERE = 2,
	R_SIBUR = 3,
	R_MENDIANE = 4,
	R_PHIRAS = 5,
	R_THYSTAME = 6,
};

t_resource	*resource_new(void);
void		resource_del(t_resource **r);
void		resource_add(t_resource *r, t_res_type t, int quantity);
void		resource_remove(t_resource *r, t_res_type t, int quantity);
char		*resource_name(t_res_type t);
t_res_type	resource_type(char *name);
int			ressource_quantity(t_resource *r, t_res_type t);

#endif
