/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_main_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:00:24 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 22:50:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#define CIR_SIZE 50

void	circle_logic(t_vector3i *location, t_vector3i *velocity, int *bounces)
{
	location->coord.x += velocity->vector[X];
	location->coord.y += velocity->vector[Y];
	if (location->coord.x + CIR_SIZE >= WIN_WIDTH || location->coord.x - CIR_SIZE <= 0)
	{
		velocity->vector[X] *= -1;
		*bounces = *bounces + 1;
	}
	if (location->coord.y + CIR_SIZE >= WIN_HEIGHT || location->coord.y - CIR_SIZE <= 0)
	{
		velocity->vector[Y] *= -1;
		*bounces = *bounces + 1;
	}
}

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

int		init_main_menu(t_level_context *level, t_wolf_window *mgr_wolf_window)
{
	t_level_main_menu	*self_full;

	level->mgr_wolf_window = mgr_wolf_window;
	level->run_level = run_level_main_menu;
	level->get_next_level = get_next_level_main_menu;
	level->clean_level = clean_main_menu;
	level->is_running = level_is_running_main_menu;

	self_full = (t_level_main_menu *)level;
	self_full->bounces = 0;
	return (1);
}

int		level_is_running_main_menu(t_level_context *self)
{
	int					result;
	t_level_main_menu	*self_full;

	result = 1;
	self_full = (t_level_main_menu *)self;
	if (glfwWindowShouldClose(self->mgr_wolf_window->window))
		result = 0;
	else if (self_full->bounces >= 1)
		result = 0;
	else if (self_full->h_game_state == 'e')
		result = 0;
	return (result);
}

t_level_context	*run_level_main_menu(t_level_context *self)
{
	t_wolf_window		*mgr_wolf_window;
	t_level_context		*new_level;
	t_level_main_menu	*self_full;

	t_vector3i			velocity;
	t_vector3i			location;
	int					bounces;

	self_full = (t_level_main_menu *)self;

	bounces = 0;
	mgr_wolf_window = self->mgr_wolf_window;
	location.vector[X] = WIN_WIDTH / 2;
	location.vector[Y] = WIN_HEIGHT / 2;
	velocity.vector[X] = 5;
	velocity.vector[Y] = 1;

	while (self->is_running(self))
	{
		draw_circle(mgr_wolf_window->pixel_array, location.coord.x, location.coord.y);

		glfwPollEvents();
		if (glfwGetKey(mgr_wolf_window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(mgr_wolf_window->window, GL_TRUE);
			game_running(GAME_STATE_SET, SHUTDOWN_GAME);
			self_full->h_next_state = 'e';
		}
		circle_logic(&location, &velocity, &self_full->bounces);
		refresh_screen(mgr_wolf_window);
	}
	new_level = self->get_next_level(self);
	self->clean_level(self);
	return (new_level);
}

t_level_context	*get_next_level_main_menu(struct s_level_context *self)
{
	t_level_main_menu *self_full;

	self_full = (t_level_main_menu *)self;
	if (self_full->h_next_state == 'e')
		return (NULL);
	else if (self_full->bounces >= 1)
		return (first_level(self->mgr_wolf_window));
	else
		return (NULL);
}

int		clean_main_menu(t_level_context *self)
{
	(void)self;
	return (42);
}
