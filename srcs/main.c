/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:31:31 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 05:09:40 by kmira            ###   ########.fr       */
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

t_level_context	*run_main_menu(t_level_context *self)
{
	t_wolf_window *h_wolf_window;

	h_wolf_window = self->h_wolf_window;
	while (!glfwWindowShouldClose(h_wolf_window->window))
	{
		draw_circle(h_wolf_window->pixel_array);
		update_pixels(h_wolf_window);
		glfwSwapBuffers(h_wolf_window->window);
		glfwPollEvents();
		if (glfwGetKey(h_wolf_window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(h_wolf_window->window, GL_TRUE);
	}
	return (NULL);
}

int		init_main_menu(t_level_context *level, t_wolf_window *h_wolf_window)
{
	level->h_wolf_window = h_wolf_window;
	level->run_level = run_main_menu;
	return (1);
}

int		main(void)
{
	t_wolf_window	h_wolf_window;
	t_level_context	*curr_level;
	t_level_context	*new_level;

	new_level = NULL;
	h_wolf_window = wolf_initialize();
	curr_level = malloc(sizeof(t_level_main_menu));
	curr_level->init_self = init_main_menu;
	while (game_state() == GAME_STATE_OK && curr_level != NULL)
	{
		curr_level->init_self(curr_level, &h_wolf_window);
		new_level = curr_level->run_level(curr_level);
		curr_level = new_level;
	}
	wolf_destroy(&h_wolf_window);
	return (0);
}
