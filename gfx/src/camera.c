/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 09:04:02 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/10 17:53:30 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_mouse	g_mouse;

void	init_cam(t_cam *cam)
{
	t_vec	look_at;
	t_vec	roll;
	t_vec	cam_pos;

	g_mouse.angle = 0.f;
	g_mouse.delta_angle = 0.f;
	g_mouse.lx = 0.f;
	g_mouse.lz = 0.f;
	g_mouse.origin_x = -1.f;
	cam->speed = 2.f;
	cam->yaw_speed = 1.f;
	cam->yaw = 0.f;
	cam->y_dif = 10.f;
	cam->pos = new_vector(0.f, 2.f, 3.f);
	look_at = new_vector(cam->pos.x, cam->pos.y - cam->y_dif, \
			cam->pos.z - 10.f);
	roll = new_vector(0.f, 1.f, 0.f);
	cam->proj_matrix = perspective_matrix(FOV, ASPECT, NEAR, FAR);
	cam->view_matrix = view_matrix(cam->pos, look_at, roll);
}

void	update_value(float *value, float add, t_cam *cam)
{
	*value += add;
	cam->change = 1;
}

void	update_move_keys(t_cam *cam, GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_A))
		update_value(&cam->pos.x, -(cam->speed * g_elapsed), cam);
	if (glfwGetKey(window, GLFW_KEY_D))
		update_value(&cam->pos.x, (cam->speed * g_elapsed), cam);
	if (glfwGetKey(window, GLFW_KEY_W))
	{
		update_value(&cam->pos.z, -(cam->speed * g_elapsed), cam);
		update_value(&cam->pos.y, (cam->speed * g_elapsed), cam);
	}
	if (glfwGetKey(window, GLFW_KEY_S))
	{
		update_value(&cam->pos.z, (cam->speed * g_elapsed), cam);
		update_value(&cam->pos.y, -(cam->speed * g_elapsed), cam);
	}
}

void	update_rotate_keys(t_cam *cam, GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT))
		update_value(&cam->yaw, (cam->speed * g_elapsed), cam);
	if (glfwGetKey(window, GLFW_KEY_RIGHT))
		update_value(&cam->yaw, -(cam->speed * g_elapsed), cam);
	if (glfwGetKey(window, GLFW_KEY_UP))
	{
		if (cam->pos.y + (cam->speed * g_elapsed) < 15.f)
			update_value(&cam->pos.y, (cam->speed * g_elapsed), cam);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN))
	{
		if (cam->pos.y - (cam->speed * g_elapsed) > 0.f)
			update_value(&cam->pos.y, -(cam->speed * g_elapsed), cam);
	}
	if (glfwGetKey(window, GLFW_KEY_PAGE_UP))
		update_value(&cam->y_dif, (cam->speed * g_elapsed), cam);
	if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN))
		update_value(&cam->y_dif, -(cam->speed * g_elapsed), cam);
}

void	update_view_cam(t_cam *cam, GLFWwindow *window)
{
	static float save_lx = -1.f;
	t_vec	look_at;
	t_vec	roll;

	cam->change = 0;
	update_move_keys(cam, window);
	update_rotate_keys(cam, window);
	if (glfwGetKey(window, GLFW_KEY_X))
		init_cam(cam);
	if (save_lx == -1.f)
		save_lx = g_mouse.lx;
	if (cam->change || g_mouse.lx != save_lx || g_mouse.lz != 0)
	{
		cam->pos.z -= g_mouse.lz;
		look_at = new_vector(cam->pos.x + g_mouse.lx, cam->pos.y - cam->y_dif, \
				cam->pos.z - 10.f);
		roll = new_vector(0.f, 1.f, 0.f);
		cam->view_matrix = view_matrix(cam->pos, look_at, roll);
		save_lx = g_mouse.lx;
		g_mouse.lz = 0;
	}
}
