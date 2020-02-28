/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_first_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:24:06 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 17:55:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	circle_logic_c(t_vector3i *location, t_vector3i *velocity, int *bounces)
{
	location->coord.x += velocity->vector[X];
	location->coord.y += velocity->vector[Y];
	if (location->coord.x + 50 >= WIN_WIDTH || location->coord.x - 50 <= 0)
	{
		velocity->vector[X] *= -1;
		*bounces = *bounces + 1;
	}
	if (location->coord.y + 50 >= WIN_HEIGHT || location->coord.y - 50 <= 0)
	{
		velocity->vector[Y] *= -1;
		*bounces = *bounces + 1;
	}
}

void	draw_circle_c(uint8_t **pixel_array, int x_center, int y_center, uint32_t hex_color)
{
	int		x;
	int		y;
	float	i;
	int		j;
	t_color	color;

	j = 0;
	i = 0;
	color.col_32bit = hex_color;
	while (i < (M_PI * 2))
	{
		x = (int)50 * cos(i) + x_center;
		y = (int)50 * sin(i) + y_center;
		push_pixel(x, y, color, pixel_array);
		i += 0.001;
		j++;
	}
}

t_level_context	*first_level(t_wolf_window *mgr_wolf_window)
{
	t_level_context	*result;
	t_level_first	*self_full;

	self_full = malloc(sizeof(*self_full));
	ft_bzero(self_full, sizeof(*self_full));
	self_full->common_level.init_self = init_first_level;
	self_full->common_level.mgr_wolf_window = mgr_wolf_window;

	result = (t_level_context *)self_full;
	return (result);
}

int				init_first_level(t_level_context *level, t_wolf_window *mgr_wolf_window)
{
	level->mgr_wolf_window = mgr_wolf_window;
	level->run_level = run_level_first_level;
	level->get_next_level = get_next_level_first_level;
	level->clean_level = clean_level_first_level;
	return (1);
}

t_level_context	*run_level_first_level(t_level_context *self)
{
	t_wolf_window	*mgr_wolf_window;
	t_level_context	*new_level;
	t_level_first	*self_full;

	self_full = (t_level_first *)self;

	t_vector3i		velocity_1;
	t_vector3i		location_1;

	t_vector3i		velocity_2;
	t_vector3i		location_2;

	int				bounces;

	location_1.vector[X] = WIN_WIDTH / 2; location_1.vector[Y] = WIN_HEIGHT / 2;
	velocity_1.vector[X] = 5; velocity_1.vector[Y] = 1;

	location_2.vector[X] = WIN_WIDTH / 3; location_2.vector[Y] = WIN_HEIGHT / 4;
	velocity_2.vector[X] = -3; velocity_2.vector[Y] = 2;

	bounces = 0;
	mgr_wolf_window = self->mgr_wolf_window;
	while (!glfwWindowShouldClose(mgr_wolf_window->window) && bounces < 100)
	{
		draw_circle_c(mgr_wolf_window->pixel_array, location_1.coord.x, location_1.coord.y, 0xfe346e);
		draw_circle_c(mgr_wolf_window->pixel_array, location_2.coord.x, location_2.coord.y, 0xe8f044);

		update_pixels(mgr_wolf_window);

		glfwSwapBuffers(mgr_wolf_window->window);
		glfwPollEvents();
		if (glfwGetKey(mgr_wolf_window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(mgr_wolf_window->window, GL_TRUE);
			game_running(GAME_STATE_SET, SHUTDOWN_GAME);
			self_full->h_next_state = 'e';
		}

		circle_logic_c(&location_1, &velocity_1, &bounces);
		circle_logic_c(&location_2, &velocity_2, &bounces);

		clear_pixel_array(mgr_wolf_window->pixel_array);
	}
	new_level = self->get_next_level(self);
	self->clean_level(self);
	return (new_level);
}

t_level_context	*get_next_level_first_level(struct s_level_context *self)
{
	(void)self;
	return (NULL);
}

int		clean_level_first_level(t_level_context *self)
{
	(void)self;
	return (42);
}
