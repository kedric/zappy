/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 08:19:40 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/09 18:31:32 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

int				load_texture(char *file)
{
	GLuint	tex;
	t_img	img;

	printf("je load %s\n", file);
	if (lodepng_decode32_file(&img.data, &img.x, &img.y, file))
		return (ft_error("load png error"));
	glActiveTexture (GL_TEXTURE0);
	glGenTextures(1, &tex);
	glBindTexture (GL_TEXTURE_2D, tex);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, img.x, img.y, 0, GL_RGBA, \
			GL_UNSIGNED_BYTE, (GLvoid *)img.data);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
	return (tex);
}
