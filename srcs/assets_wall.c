/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:28:28 by kmira             #+#    #+#             */
/*   Updated: 2020/03/01 13:09:24 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			wall_update(t_animation *self, t_level_context *main_menu)
{
	int					result;

	result = 0;
	(void)self;
	(void)main_menu;
	return (result);
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
	tittle->update_sprite = wall_update;

	tittle->next = tittle;

	return (tittle);
}

