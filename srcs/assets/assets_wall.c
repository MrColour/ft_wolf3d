/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:30:01 by kmira             #+#    #+#             */
/*   Updated: 2020/03/07 19:00:03 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			wall_update(t_animation *self, t_level_context *level)
{
	int					result;

	result = 0;
	(void)self;
	(void)level;
	return (result);
}

t_animation	*wall_animation(void)
{
	t_animation *wall;
	int			offset;

	wall = malloc(sizeof(*wall));
	wall->texture = create_texture("resources/ft_png_files/wall.ft_png");

	offset = wall->texture->width / 2;

	wall->texture->screen_pos.coord.x = 0;
	wall->texture->screen_pos.coord.y = 0;

	wall->update_sprite = wall_update;

	wall->next = wall;

	return (wall);
}
