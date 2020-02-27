/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:57:22 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 00:37:50 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#define WIN_CENTER 0
#define WIN_TOP_LEFT 1

static void	window_origin(int option)
{
	if (option == WIN_CENTER)
	{
		glOrtho(-(WIN_WIDTH / 2), (WIN_WIDTH / 2),
				-(WIN_HEIGHT / 2), (WIN_HEIGHT / 2), 0.0, 1.0);
	}
	else if (option == WIN_TOP_LEFT)
		glOrtho(0, WIN_WIDTH, (WIN_HEIGHT), 0, 0.0, 1.0);
	else
		glOrtho(0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0, 1.0);
}

GLFWwindow	*wolf_initialize(void)
{
	GLFWwindow *window;

	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME, NULL, NULL);
	glfwMakeContextCurrent(window);
	glPointSize(1.0);
	glMatrixMode(GL_MODELVIEW);
	window_origin(WIN_TOP_LEFT);
	return (window);
}
