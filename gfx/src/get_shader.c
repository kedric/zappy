/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 14:19:44 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/10 14:27:38 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

char	*get_shader_name(char *obj_name, char *shader)
{
	char	*tmp;
	char	*file;

	file = ft_strjoin("shaders/", obj_name);
	tmp = file;
	file = ft_strjoin(file, shader);
	free(tmp);
	tmp = file;
	file = ft_strjoin(file, ".glsl");
	return (file);
}

char	*load_shader(char *file, int type)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	*shader;
	char	buf[129];

	printf("i load %s\n", file);
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		printf("ERROR: could not find %s\n ==> Using default shader file\n",\
				file);
		if (type == 1)
			return (load_shader(get_shader_name("tile", "_vs_shader"), 1));
		return (load_shader(get_shader_name("tile", "_frag_shader"), 2));
	}
	shader = NULL;
	while ((ret = read(fd, buf, 128)) > 0)
	{
		buf[ret] = 0;
		tmp = shader;
		if (shader)
			shader = ft_strjoin(shader, buf);
		else
			shader = ft_strdup(buf);
		if (tmp)
			free(tmp);
	}
	free(file);
	return (shader);
}



GLuint	get_shader(char *obj_name)
{
	const	char *vertex_shader;
	const	char *frag_shader;
	GLuint	vs;
	GLuint	fs;
	GLuint	shader_prog;

	vertex_shader = load_shader(get_shader_name(obj_name, "_vs_shader"), 1);
	frag_shader = load_shader(get_shader_name(obj_name, "_frag_shader"), 2);
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	print_shader_log(vs);
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &frag_shader, NULL);
	glCompileShader(fs);
	print_shader_log(fs);
	shader_prog = glCreateProgram();
	glAttachShader(shader_prog, fs);
	glAttachShader(shader_prog, vs);
	glLinkProgram(shader_prog);
	return (shader_prog);
}
