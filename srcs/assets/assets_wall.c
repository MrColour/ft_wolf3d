/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:30:01 by kmira             #+#    #+#             */
/*   Updated: 2020/03/06 01:54:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			wall_update(t_animation *self, t_level_context *level)
{
	int					result;
	t_level_first		*real_level;
	double				x_distance;
	double				y_distance;

	real_level = (t_level_first	*)level;

	x_distance = self->texture->world_pos.coord.z - real_level->player.posy + 3;
	y_distance = self->texture->world_pos.coord.z - real_level->player.posy + 3;

	self->texture->transform.matrix[0][0] = (1.5 * self->texture->width) / (x_distance);
	self->texture->transform.matrix[1][1] = (1.5 * self->texture->height) / (y_distance);

	printf("Transoform: (%f, %f)\n", self->texture->transform.matrix[0][0], self->texture->transform.matrix[1][1]);

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
