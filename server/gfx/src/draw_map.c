/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:52:50 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/10 20:41:19 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static void	draw_skybox(t_cam cam, t_scene scene)
{
	int		tex_loc;

	glDepthMask(GL_FALSE);
	glUseProgram(scene.objects[SKYBOX].program);
	tex_loc = glGetUniformLocation(scene.objects[SKYBOX].texture, \
			"cube_texture");
	glUniform1i(tex_loc, 1);
	glBindTexture (GL_TEXTURE_CUBE_MAP, scene.objects[SKYBOX].texture);
	translate_cam(scene.objects[SKYBOX].program, cam, 1);
	glBindVertexArray(scene.objects[SKYBOX].vao);
	glDrawArrays(GL_TRIANGLES, 0, scene.objects[SKYBOX].point_count);
	glDepthMask(GL_TRUE);
}

void		draw_player(t_vec2 p, t_scene scene, t_cam cam)
{
	t_vec	pos;

	pos = grid_to_world(p.x, p.y, scene.map_x, scene.map_y);
	pos.y += 1.f;
	draw_particles(scene.objects[PLAYER]);
	translate_obj(scene.objects[PLAYER].program, pos, 0);
	translate_cam(scene.objects[PLAYER].program, cam, 0);
}

void		draw_ressources(t_vec2 p, t_scene scene, t_cam cam)
{
	t_vec		pos;
	t_ressource	ressource;

	pos = grid_to_world(p.x, p.y, scene.map_x, scene.map_y);
	pos.y += 1.f;
	draw_particles(scene.objects[PLAYER]);
	translate_obj(scene.objects[PLAYER].program, pos, 0);
	translate_cam(scene.objects[PLAYER].program, cam, 0);
}

void		draw_map(t_cam cam, t_scene scene)
{
	t_vec	p;
	t_vec2	v;
	int		x;
	int		z;
	int		i;

	v = new_vec2(-1, -1);
	p = new_vector(0.f, 0.f, 0.f);
	glActiveTexture(GL_TEXTURE0);
	draw_skybox(cam, scene);
	glUseProgram(scene.objects[TILE].program);
	glBindTexture (GL_TEXTURE_2D, scene.objects[TILE].texture);
	translate_cam(scene.objects[TILE].program, cam, 0);
	while (++v.y < scene.map_y)
	{
		v.x = -1;
		p.x = -((scene.map_y * TILE_X) / 2);
		while (++v.x < scene.map_x)
		{
			if (scene.map[v.x][v.y].players)
				draw_player(v, scene, cam);
/*			if (scene.map[v.x][v.y].ressources)
				draw_ressources(v, scene, cam);*/
			glUseProgram(scene.objects[TILE].program);
			glBindTexture (GL_TEXTURE_2D, scene.objects[TILE].texture);
			translate_obj(scene.objects[TILE].program, p, 1);
			glBindVertexArray(scene.objects[TILE].vao);
			glDrawArrays(GL_TRIANGLES, 0, scene.objects[TILE].point_count);
			p.x += TILE_X;
		}
		p.z -= TILE_X;
	}
}
