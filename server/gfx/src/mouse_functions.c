/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 12:37:26 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/10 14:05:33 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	mouse_button(GLFWwindow *window, int button, int action, int mode)
{
	double	x;
	double	y;

	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			glfwGetCursorPos(window, &x, &y);
			g_mouse.origin_x = x;
		}
		else
		{
			g_mouse.angle += g_mouse.delta_angle;
			g_mouse.origin_x = -1;
		}
	}
}

void	mouse_move(GLFWwindow *window, double xpos, double ypos)
{
/*
	if (g_mouse.origin_x >= 0)
	{
		g_mouse.delta_angle = (xpos - g_mouse.origin_x) * 0.001f;
		g_mouse.lx = sinf(g_mouse.angle + g_mouse.delta_angle);
//		g_mouse.lz = -cos(g_mouse.angle +g_mouse.delta_angle);
	}*/
}

void	scroll_function(GLFWwindow *window, double xoffset, double yoffset)
{
	g_mouse.lz = yoffset * g_elapsed;
}
