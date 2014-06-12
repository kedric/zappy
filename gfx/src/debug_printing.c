/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 03:42:38 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/06 08:08:08 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	print_shader_log(GLuint shader)
{
	int		max_len;
	int		actual_len;
	char	log[2048];

	max_len = 2048;
	actual_len = 0;
	glGetShaderInfoLog(shader, max_len, &actual_len, log);
	printf("shader debug log for GL index %u:\n%s\n", shader, log);
}

void	print_matrix(t_mat4 matrix)
{
	int	i;

	i = -1;
	printf("=========\n");
	while (++i < 16)
	{
		if (i % 4 == 0 && i != 0)
			printf("\n");
		printf("%.2f ", matrix.m[i]);
	}
	printf("\n=======\n");
}
