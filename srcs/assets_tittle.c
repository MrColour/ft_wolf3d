/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_tittle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 00:33:59 by kmira             #+#    #+#             */
/*   Updated: 2020/02/29 00:39:20 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			tittle_update(t_animation *self, t_level_context *main_menu)
{
	int					result;

	result = 0;
	(void)self;
	(void)main_menu;
	return (result);
}

t_animation	*tittle_animation(void)
{
	t_animation *tittle;
	int			offset;

	tittle = malloc(sizeof(*tittle));
	tittle->texture = create_texture("resources/con_tittle_tex");

	offset = tittle->texture->width / 2;

	tittle->texture->pos.coord.x = WIN_WIDTH / 2 - offset;
	tittle->texture->pos.coord.y = WIN_HEIGHT / 2 - 150;
	tittle->update_sprite = tittle_update;

	tittle->next = tittle;

	return (tittle);
}
