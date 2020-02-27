/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:31:31 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 02:31:55 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_circle(uint8_t **pixel_array)
{
	int		x;
	int		y;
	float	i;
	int		j;
	t_color	color;

	j = 0;
	i = 0;
	color.col_32bit = 0x05dfd7;
	while (i < (M_PI / 2))
	{
		x = (int)256 * cos(i);
		y = (int)256 * sin(i);
		push_pixel(x, y, color, pixel_array);
		i += 0.001;
		j++;
	}
}

int		main(void)
{
	t_wolf_window	h_wolf_window;

	h_wolf_window = wolf_initialize();

	glfwSwapInterval(1);
	while (!glfwWindowShouldClose(h_wolf_window.window))
	{
		draw_circle(h_wolf_window.pixel_array);
		update_pixels(&h_wolf_window);
		glfwSwapBuffers(h_wolf_window.window);
		glfwPollEvents();
		if (glfwGetKey(h_wolf_window.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(h_wolf_window.window, GL_TRUE);
	}
	glfwTerminate();
}
