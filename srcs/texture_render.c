/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 03:27:09 by kmira             #+#    #+#             */
/*   Updated: 2020/03/01 16:52:58 by kmira            ###   ########.fr       */
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
	transform.matrix[0][1] = 0;
	transform.matrix[0][2] = 0;

	transform.matrix[1][0] = -.33;
	transform.matrix[1][1] = 1;
	transform.matrix[1][2] = 0;

	draw_transform_texture(texture, mgr_wolf_window, &transform);
}

void	draw_wall_test_1(t_texture *texture, t_wolf_window *mgr_wolf_window)
{
	t_matrix3i	transform;

	transform.matrix[0][0] = 1;
	transform.matrix[0][1] = 0;
	transform.matrix[0][2] = 0;

	transform.matrix[1][0] = .5;
	transform.matrix[1][1] = 1;
	transform.matrix[1][2] = 0;

	draw_transform_texture(texture, mgr_wolf_window, &transform);
}

/*
** The texture is messed up, will try to fix it later.
** The problem is that the height and the width are reverse
** when the python script tries todo it.
*/

void	draw_transform_texture(t_texture *texture, t_wolf_window *mgr_wolf_window, t_matrix3i *transform)
{
	int	row;
	int	col;
	double	new_x;
	double	new_y;
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

				new_x = row * transform->matrix[0][0];
				new_y = row * transform->matrix[1][0] * -1 + col * transform->matrix[1][1];

				new_x = (int)new_x + texture->pos.coord.x;
				new_y = (int)new_y + texture->pos.coord.y;

				push_pixel(new_x, new_y, color, mgr_wolf_window->pixel_array);
			}
			col++;
		}
		row++;
	}
}
