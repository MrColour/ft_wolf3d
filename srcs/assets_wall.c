/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:28:28 by kmira             #+#    #+#             */
/*   Updated: 2020/03/01 17:25:221 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			wall_update(t_animation *self, t_level_context *level)
{
	int					result;
	t_level_first		*real_level;

	real_level = (t_level_first	*)level;

	self->texture->pos.coord.x = self->texture->draw.coord.x + real_level->player.posx;
	self->texture->pos.coord.y = self->texture->draw.coord.y + real_level->player.posy;

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
	t_animation *tittle;
	int			offset;

	tittle = malloc(sizeof(*tittle));
	tittle->texture = create_texture("resources/ft_png_files/wall.ft_png");

	offset = tittle->texture->width / 2;

	tittle->texture->pos.coord.x = WIN_WIDTH / 2 - offset;
	tittle->texture->pos.coord.y = WIN_HEIGHT / 2 - 150;

	tittle->texture->draw.coord.x = WIN_WIDTH / 2 - offset;
	tittle->texture->draw.coord.y = WIN_HEIGHT / 2 - 150;

	tittle->update_sprite = wall_update;

	tittle->next = tittle;

	return (tittle);
}

