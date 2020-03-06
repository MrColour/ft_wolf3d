/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_play_button.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:19:34 by kmira             #+#    #+#             */
/*   Updated: 2020/03/06 01:53:55 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			play_button_update(t_animation *self, t_level_context *main_menu)
{
	static int			prev_menu_state;
	t_level_main_menu	*level;
	int					result;

	result = 0;
	level = (t_level_main_menu *)main_menu;
	if (prev_menu_state != level->h_menu_index)
	{
		prev_menu_state = level->h_menu_index;
		result = 1;
	}
	(void)self;
	return (result);
}

t_animation	*play_button_animation(void)
{
	t_animation *deactive_button;
	t_animation *active_button;
	int			offset;

	deactive_button = malloc(sizeof(*deactive_button));
	deactive_button->texture = create_texture("resources/ft_png_files/play_deactive.ft_png");

	offset = deactive_button->texture->width / 2;

	deactive_button->texture->screen_pos.coord.x = WIN_WIDTH / 2 - offset;
	deactive_button->texture->screen_pos.coord.y = WIN_HEIGHT / 2;
	deactive_button->update_sprite = play_button_update;

	active_button = malloc(sizeof(*active_button));
	active_button->texture = create_texture("resources/ft_png_files/play_active.ft_png");
	active_button->texture->screen_pos.coord.x = WIN_WIDTH / 2 - offset;
	active_button->texture->screen_pos.coord.y = WIN_HEIGHT / 2;
	active_button->update_sprite = play_button_update;

	deactive_button->next = active_button;
	active_button->next = deactive_button;

	return (active_button);
}

int			quit_button_update(t_animation *self, t_level_context *main_menu)
{
	static int			prev_menu_state;
	t_level_main_menu	*level;
	int					result;

	result = 0;
	level = (t_level_main_menu *)main_menu;
	if (prev_menu_state != level->h_menu_index)
	{
		prev_menu_state = level->h_menu_index;
		result = 1;
	}
	(void)self;
	return (result);
}

t_animation	*quit_button_animation(void)
{
	t_animation *deactive_button;
	t_animation *active_button;
	int			offset;

	deactive_button = malloc(sizeof(*deactive_button));
	deactive_button->texture = create_texture("resources/ft_png_files/quit_deactive.ft_png");

	offset = deactive_button->texture->width / 2;

	deactive_button->texture->screen_pos.coord.x = WIN_WIDTH / 2 - offset;
	deactive_button->texture->screen_pos.coord.y = WIN_HEIGHT / 2 + 100;
	deactive_button->update_sprite = quit_button_update;

	active_button = malloc(sizeof(*active_button));
	active_button->texture = create_texture("resources/ft_png_files/quit_active.ft_png");
	active_button->texture->screen_pos.coord.x = WIN_WIDTH / 2 - offset;
	active_button->texture->screen_pos.coord.y = WIN_HEIGHT / 2 + 100;
	active_button->update_sprite = quit_button_update;

	deactive_button->next = active_button;
	active_button->next = deactive_button;

	return (deactive_button);
}
