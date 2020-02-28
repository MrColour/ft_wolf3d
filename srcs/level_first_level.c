/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_first_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:24:06 by kmira             #+#    #+#             */
/*   Updated: 2020/02/28 03:43:25 by kmira            ###   ########.fr       */
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
	t_level_first	*self_full;

	level->mgr_wolf_window = mgr_wolf_window;
	level->run_level = run_level_first_level;
	level->get_next_level = get_next_level_first_level;
	level->clean_level = clean_level_first_level;
	level->is_running = level_is_running_first_level;

	level->level_ticks = 0;

	self_full = (t_level_first *)level;
	self_full->h_game_state = 0;
	self_full->bounces = 0;

	mgr_wolf_window->background_color.col_32bit = 0x777777;

	self_full->test_text = create_texture("resources/con_play_tex");
	self_full->test_text->pos.coord.x = WIN_WIDTH / 2;
	self_full->test_text->pos.coord.y = WIN_HEIGHT / 2;
	return (1);
}

int				level_is_running_first_level(t_level_context *self)
{
	int				result;
	t_level_first	*self_full;

	result = 1;
	self_full = (t_level_first *)self;
	if (glfwWindowShouldClose(self->mgr_wolf_window->window))
		result = 0;
	else if (self_full->bounces >= 100)
		result = 0;
	else if (self_full->h_game_state == 'e')
		result = 0;
	else if (self_full->h_game_state == '\007')
		result = 0;
	return (result);
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


	location_1.vector[X] = WIN_WIDTH / 2; location_1.vector[Y] = WIN_HEIGHT / 2;
	velocity_1.vector[X] = 5; velocity_1.vector[Y] = 1;

	location_2.vector[X] = WIN_WIDTH / 3; location_2.vector[Y] = WIN_HEIGHT / 4;
	velocity_2.vector[X] = -3; velocity_2.vector[Y] = 2;

	mgr_wolf_window = self->mgr_wolf_window;

	while (self->is_running(self))
	{
		glfwPollEvents();
		if (glfwGetKey(mgr_wolf_window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(mgr_wolf_window->window, GL_TRUE);
			game_running(GAME_STATE_SET, SHUTDOWN_GAME);
			self_full->h_next_state = 'e';
		}
		else if (glfwGetKey(mgr_wolf_window->window, GLFW_KEY_SPACE) == GLFW_PRESS && self_full->h_toggle == 0)
		{
			self_full->h_game_state ^= ' ';
			self_full->h_toggle = 1;
			self->level_ticks = 15;
		}
		else if (glfwGetKey(mgr_wolf_window->window, GLFW_KEY_ENTER) == GLFW_PRESS)
			self_full->h_game_state = '\007';

		if (self_full->h_game_state == ' ')
		{
			draw_circle_c(mgr_wolf_window->pixel_array, location_1.coord.x, location_1.coord.y, 0xFFFFFF);
			draw_circle_c(mgr_wolf_window->pixel_array, location_2.coord.x, location_2.coord.y, 0xFFFFFF);
			if (self->level_ticks % 25 == 0)
			{
				self_full->h_toggle = 0;
				self->level_ticks = 0;
			}
		}
		else
		{
			draw_circle_c(mgr_wolf_window->pixel_array, location_1.coord.x, location_1.coord.y, 0xfe346e);
			draw_circle_c(mgr_wolf_window->pixel_array, location_2.coord.x, location_2.coord.y, 0xe8f044);
			if (self->level_ticks % 25 == 0)
			{
				self_full->h_toggle = 0;
				self->level_ticks = 0;
			}
		}

		draw_texture(self_full->test_text, mgr_wolf_window);

		circle_logic_c(&location_1, &velocity_1, &self_full->bounces);
		circle_logic_c(&location_2, &velocity_2, &self_full->bounces);

		refresh_screen(mgr_wolf_window);

		self->level_ticks++;
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
