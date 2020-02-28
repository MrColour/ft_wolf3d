/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:31:31 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 16:55:12 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#define CIR_SIZE 50

void	draw_circle(uint8_t **pixel_array, int x_center, int y_center)
{
	int		x;
	int		y;
	float	i;
	int		j;
	t_color	color;

	j = 0;
	i = 0;
	color.col_32bit = 0xfe346e;
	while (i < (M_PI * 2))
	{
		x = (int)CIR_SIZE * cos(i) + x_center;
		y = (int)CIR_SIZE * sin(i) + y_center;
		push_pixel(x, y, color, pixel_array);
		i += 0.001;
		j++;
	}
}

t_level_context	*run_main_menu(t_level_context *self)
{
	t_wolf_window	*h_wolf_window;
	t_vector3i		velocity;
	t_vector3i		location;

	h_wolf_window = self->h_wolf_window;

	location.vector[X] = WIN_WIDTH / 2;
	location.vector[Y] = WIN_HEIGHT / 2;

	velocity.vector[X] = 5;
	velocity.vector[Y] = 2;
	while (!glfwWindowShouldClose(h_wolf_window->window))
	{
		draw_circle(h_wolf_window->pixel_array, location.coord.x, location.coord.y);
		update_pixels(h_wolf_window);
		glfwSwapBuffers(h_wolf_window->window);
		glfwPollEvents();
		if (glfwGetKey(h_wolf_window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(h_wolf_window->window, GL_TRUE);
		location.coord.x += velocity.vector[X];
		location.coord.y += velocity.vector[Y];
		if (location.coord.x + CIR_SIZE >= WIN_WIDTH || location.coord.x - CIR_SIZE <= 0)
			velocity.vector[X] *= -1;
		if (location.coord.y + CIR_SIZE >= WIN_HEIGHT || location.coord.y - CIR_SIZE <= 0)
			velocity.vector[Y] *= -1;
		clear_pixel_array(h_wolf_window->pixel_array);
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
