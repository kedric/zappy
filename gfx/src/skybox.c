/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 15:36:32 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/09 16:52:10 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static int			gl_enums(int i)
{
	static int	enums[] =
	{
		GL_TEXTURE_CUBE_MAP_POSITIVE_X,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
	};

	return (enums[i]);
}

static int			bind_skybox(GLuint tex)
{
	int		i;
	char	*tmp;
	char	*file;
	t_img	img;

	i = -1;
	while (++i < 6)
	{
		glBindTexture (GL_TEXTURE_CUBE_MAP, tex);
		tmp = ft_itoa(i);
		file = ft_strjoin("textures/sky", tmp);
		tmp = file;
		file = ft_strjoin(file, ".png");
		free(tmp);
		if (lodepng_decode32_file(&img.data, &img.x, &img.y, file))
			return (ft_error("load png error"));
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, img.x, img.y, 0, GL_RGBA, \
				GL_UNSIGNED_BYTE, (GLvoid *)img.data);
		free(file);
	}
}

int					load_skybox(void)
{
	int		i;
	char	*tmp;
	GLuint	tex;

	glActiveTexture (GL_TEXTURE1);
	glGenTextures(1, &tex);
	if (bind_skybox(tex) == -1)
		return (-1);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return (tex);
}
