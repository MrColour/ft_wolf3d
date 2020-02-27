/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:31:31 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 00:35:20 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_circle(void)
{
	float	x;
	float	y;
	float	i;
	int		j;

	j = 0;
	i = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(250, 0, 0);
	glBegin(GL_POINTS);
	glColor3ub(250, 0, 0);
	while (i < (M_PI / 2))
	{
		if (j % 2 == 0)
			glColor3ub(0, 0, 250);
		else
			glColor3ub(0, 250, 0);
		x = 256 * cos(i);
		y = 256 * sin(i);
		glVertex2i(x, y);
		i += 0.001;
		j++;
	}
	glEnd();
	glFlush();
}

int		main(void)
{
	GLFWwindow *window;

	window = wolf_initialize();

	glfwSwapInterval(1);
	while (!glfwWindowShouldClose(window))
	{
		draw_circle();
		glfwSwapBuffers(window);
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}
	glfwTerminate();
}
