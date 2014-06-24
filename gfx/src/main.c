/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthebaud <rthebaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 15:31:56 by rthebaud          #+#    #+#             */
/*   Updated: 2014/06/10 19:24:56 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

float g_elapsed = 1.f / 60.f;

void	update_elapsed_sec()
{
	static double	prev_time = -1;
	double			cur_sec;
	double			fps;
	
	if (prev_time == -1)
		prev_time = glfwGetTime();
	cur_sec = glfwGetTime();
	g_elapsed = (cur_sec - prev_time);
	prev_time = cur_sec;
}

void	print_fps_counter(GLFWwindow *window)
{
	static int		frame_count;
	static float	cumul;
	char			tmp[128];
	float			fps;

	cumul += g_elapsed;
	if (cumul > 0.25f)
	{
		fps = (double)frame_count / cumul;
		sprintf(tmp, "framerate: %.2f", fps);
		glfwSetWindowTitle(window, tmp);
		cumul = 0;
		frame_count = 0;
	}
	frame_count++;
}

void	update(GLFWwindow *window)
{
	t_cam		cam;
	t_scene		scene;

	init_map(&scene, MAP_X, MAP_Y);
	load_scene(&scene, &cam);
	while (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS \
			&& glfwWindowShouldClose(window) == 0)
	{
		update_elapsed_sec();
		update_view_cam(&cam, window);
		print_fps_counter(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw_map(cam, scene);
		t_vec pos;
		pos = new_vector(0.f, 0.f, -10.f);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}

int	ft_error(char *msg)
{
	fprintf(stderr, "ERROR: %s\n", msg);
	return (-1);
}

int	init_GLFW(GLFWwindow **window)
{
	if (!glfwInit ())
		return (ft_error("could not start GLFW3"));
	glfwWindowHint (GLFW_SAMPLES, 4);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	*window = glfwCreateWindow (WIN_W, WIN_H, "Zappy", NULL, NULL);
	if (!(*window))
	{
		glfwTerminate();
		return (ft_error("could not open window with GLFW3"));
	}
	glfwMakeContextCurrent (*window);
	glewExperimental = 1;
	if (glewInit() != GLEW_OK)
		return (ft_error("failed to init GLEW"));
	printf ("Renderer: %s\n", glGetString (GL_RENDERER));
	printf ("OpenGL version supported %s\n", glGetString (GL_VERSION));
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glfwSetMouseButtonCallback(*window, mouse_button);
	glfwSetCursorPosCallback(*window, mouse_move);
	glfwSetScrollCallback(*window, scroll_function);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/*	glEnable (GL_CULL_FACE);
		glCullFace (GL_BACK);
		glFrontFace (GL_CW);*/
	return (1);
}

int	main(int argc, char **argv)
{
	GLFWwindow	*window;
	if (init_GLFW(&window) == -1)
		return (-1);
	update(window);
	glfwTerminate();
	return (0);
}
