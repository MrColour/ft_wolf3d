/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 03:27:09 by kmira             #+#    #+#             */
/*   Updated: 2020/03/01 15:14:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_texture(t_texture *texture, t_wolf_window *mgr_wolf_window)
{
	int		row;
	int		col;
	t_color	color;

	row = 0;
	while (row < texture->width)
	{
		col = 0;
		while (col < texture->height)
		{
			if (texture->memory_array[row * texture->height * BPP + col * BPP + 3] != 0)
			{
				color.col_32bit = *(int *)(&texture->memory_array[row * texture->height * BPP + col * BPP]);
				push_pixel(texture->pos.coord.x + row,
							texture->pos.coord.y + col,
							color, mgr_wolf_window->pixel_array);
			}
			col++;
		}
		row++;
	}
}

void	draw_wall_test(t_texture *texture, t_wolf_window *mgr_wolf_window)
{
	t_matrix3i	transform;

	transform.matrix[0][0] = 1;
	transform.matrix[0][1] = 1;
	transform.matrix[0][2] = 0;

	transform.matrix[1][0] = 1;
	transform.matrix[1][1] = 1;
	transform.matrix[1][2] = 0;

	draw_transform_texture(texture, mgr_wolf_window, &transform);
}

/*
** The texture
*/

void	draw_transform_texture(t_texture *texture, t_wolf_window *mgr_wolf_window, t_matrix3i *transform)
{
	int	row;
	int	col;
	t_color	color;

	row = 0;
	while (row < texture->width)
	{
		col = 0;
		while (col < texture->height)
		{
			if (texture->memory_array[row * texture->height * BPP + col * BPP + 3] != 0)
			{
				color.col_32bit = *(int *)(&texture->memory_array[row * texture->height * BPP + col * BPP]);
				push_pixel(texture->pos.coord.x + row * transform->matrix[0][0] + col * (transform->matrix[0][1] * -1),
							texture->pos.coord.y + row * transform->matrix[1][0] + col * (transform->matrix[1][1]),
							color, mgr_wolf_window->pixel_array);
			}
			col++;
		}
		row++;
	}
}
