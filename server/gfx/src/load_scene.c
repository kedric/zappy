/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 17:12:27 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/10 15:25:52 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static char	*get_object_name(int index)
{
	static char *names_tab[] =
	{
		[TILE] = "tile",
		[SKYBOX] = "skybox",
		[ROCK] = "rock1",
		[PLAYER] = "player",
	};
	return (names_tab[index]);
}

static void	get_file_name(char *dir, char *obj_name, char *extension, char **file)
{
	char	*tmp;

	*file = ft_strjoin(dir, obj_name);
	tmp = *file;
	*file = ft_strjoin(*file, extension);
	free(tmp);
}

static int	load_object(int index, char *obj_name, t_scene *scene)
{
	char	*file;

	if (index == PLAYER)
	{
		scene->objects[index] = set_particle(100, "textures/glow.png");
		return (1);
	}
	get_file_name("textures/", obj_name, ".png", &file);
	if (index == SKYBOX)
		scene->objects[index].texture = load_skybox();
	else
		scene->objects[index].texture = load_texture(file);
	get_file_name("meshs/", obj_name, ".obj", &file);
	load_meshes(file, scene, index);
	scene->objects[index].program = get_shader(obj_name);
	free(file);
	return (1);
}

int			load_scene(t_scene *scene, t_cam *cam)
{
	t_object_names	objects;

	scene->object_count = 0;
	init_cam(cam);
	scene->objects = (t_gldata *)malloc(sizeof(t_gldata) * ALLOC_BUFFER);
	objects = 0;
	while (objects != END)
	{
		if (load_object(objects, get_object_name(objects), scene) == -1)
			return (-1);
		objects++;
	}
}
