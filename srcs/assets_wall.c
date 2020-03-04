/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:30:01 by kmira             #+#    #+#             */
/*   Updated: 2020/03/04 01:30:03 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			wall_update(t_animation *self, t_level_context *level)
{
	int					result;
	t_level_first		*real_level;

	real_level = (t_level_first	*)level;

	self->texture->screen_pos.coord.x = self->texture->world_pos.coord.x + real_level->player.posx;
	self->texture->screen_pos.coord.y = self->texture->world_pos.coord.y + real_level->player.posy;

	self->texture->transform.matrix[0][1] -= .001;

	result = 0;
	(void)self;
	(void)level;
	return (result);
}

void		wall_transform1_matrix(void)
{
	t_matrix3i	transform;

	transform.matrix[0][0] = 1;
	transform.matrix[0][1] = 0;
	transform.matrix[0][2] = 0;

	transform.matrix[1][0] = -.33;
	transform.matrix[1][1] = 1;
	transform.matrix[1][2] = 0;
}

void		wall_transform2_matrix(void)
{
	t_matrix3i	transform;

	transform.matrix[0][0] = 1;
	transform.matrix[0][1] = 0;
	transform.matrix[0][2] = 0;

	transform.matrix[1][0] = .5;
	transform.matrix[1][1] = 1;
	transform.matrix[1][2] = 0;
}

t_animation	*wall_animation(void)
{
	t_animation *wall;
	int			offset;

	wall = malloc(sizeof(*wall));
	wall->texture = create_texture("resources/ft_png_files/wall.ft_png");

	offset = wall->texture->width / 2;

	wall->texture->world_pos.coord.x = WIN_WIDTH / 2 - offset;
	wall->texture->world_pos.coord.y = WIN_HEIGHT / 2 - 150;

	wall->update_sprite = wall_update;

	wall->next = wall;

	return (wall);
}

