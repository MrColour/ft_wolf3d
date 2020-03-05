/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_main_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:00:24 by kmira             #+#    #+#             */
/*   Updated: 2020/03/01 13:10:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#define CIR_SIZE 50

int		level_init_main_menu(t_level_context *level, t_wolf_window *mgr_wolf_window)
{
	t_level_main_menu	*self_full;

	self_full = (t_level_main_menu *)level;

	self_full->common_level.mgr_wolf_window = mgr_wolf_window;
	self_full->common_level.run_level = level_loop_main_menu;
	self_full->common_level.is_running = level_running_main_menu;
	self_full->common_level.get_input = level_get_input_main_menu;
	self_full->common_level.get_next_level = level_get_next_main_menu;
	self_full->common_level.clean_level = level_clean_main_menu;

	self_full->h_menu_index = 0;

	self_full->animation_array = malloc(sizeof(*self_full->animation_array) * (3 + 1));
	self_full->animation_array[0] = tittle_animation();
	self_full->animation_array[1] = play_button_animation();
	self_full->animation_array[2] = quit_button_animation();
	self_full->animation_array[3] = NULL;

	return (1);
}

int		level_running_main_menu(t_level_context *self)
{
	int					result;
	t_level_main_menu	*self_full;

	result = 1;
	self_full = (t_level_main_menu *)self;
	if (glfwWindowShouldClose(self->mgr_wolf_window->window))
		result = 0;
	else if (self_full->h_game_state == 'e')
		result = 0;
	else if (self_full->h_game_state == ' ')
		result = 0;
	return (result);
}

void			level_get_input_main_menu(t_level_context *self)
{
	t_level_main_menu	*level;
	t_wolf_window		*wolf_window;

	glfwPollEvents();
	level = (t_level_main_menu *)self;
	wolf_window = level->common_level.mgr_wolf_window;
	if (glfwGetKey(wolf_window->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(wolf_window->window, GL_TRUE);
		game_running(GAME_STATE_SET, SHUTDOWN_GAME);
		level->h_game_state = 'e';
	}
	else if (glfwGetKey(wolf_window->window, GLFW_KEY_SPACE) == GLFW_PRESS ||
			glfwGetKey(wolf_window->window, GLFW_KEY_ENTER) == GLFW_PRESS)
		level->h_game_state = ' ';
	else if (glfwGetKey(wolf_window->window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		if (level->h_menu_index < 1)
			level->h_menu_index++;
	}
	else if (glfwGetKey(wolf_window->window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		if (level->h_menu_index > 0)
			level->h_menu_index--;
	}
}

t_level_context	*level_loop_main_menu(t_level_context *self)
{
	t_wolf_window		*mgr_wolf_window;
	t_level_context		*new_level;
	t_level_main_menu	*self_full;

	self_full = (t_level_main_menu *)self;
	mgr_wolf_window = self->mgr_wolf_window;

	while (self->is_running(self))
	{

		self->get_input(self);

		change_animation(&self_full->animation_array[0], self);
		draw_texture(self_full->animation_array[0]->texture, mgr_wolf_window);

		change_animation(&self_full->animation_array[1], self);
		draw_texture(self_full->animation_array[1]->texture, mgr_wolf_window);

		change_animation(&self_full->animation_array[2], self);
		draw_texture(self_full->animation_array[2]->texture, mgr_wolf_window);

		refresh_screen(mgr_wolf_window);
	}
	new_level = self->get_next_level(self);
	self->clean_level(self);
	return (new_level);
}

t_level_context	*level_get_next_main_menu(struct s_level_context *self)
{
	t_level_main_menu *self_full;

	self_full = (t_level_main_menu *)self;
	if (self_full->h_game_state == 'e')
		return (NULL);
	else if (self_full->h_game_state >= ' ' && self_full->h_menu_index == 0)
		return (first_level(self->mgr_wolf_window));
	else if (self_full->h_game_state >= ' ' && self_full->h_menu_index == 1)
		return (NULL);
	else
		return (NULL);
}

int		level_clean_main_menu(t_level_context *self)
{
	(void)self;
	return (42);
}
