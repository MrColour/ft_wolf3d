/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 03:27:09 by kmira             #+#    #+#             */
/*   Updated: 2020/03/04 01:26:00 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_texture(t_texture *texture, t_wolf_window *mgr_wolf_window)
{
	int		row;
	int		col;
	t_color	color;

	row = 0;
	while (row < texture->height)
	{
		col = 0;
		while (col < texture->width)
		{
			if (texture->memory_array[row * texture->width * BPP + col * BPP + 3] >= 20)
			{
				color.col_32bit = *(int *)(&texture->memory_array[row * texture->width * BPP + col * BPP]);
				push_pixel(texture->world_pos.coord.x + col,
							texture->world_pos.coord.y + row,
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

	transform.matrix[1][0] = 0;
	transform.matrix[1][1] = 1;
	transform.matrix[1][2] = 0;

	transform.matrix[2][0] = 0;
	transform.matrix[2][1] = 0;
	transform.matrix[2][2] = 0;

	draw_transform_texture(texture, mgr_wolf_window, &transform);
}

void	draw_wall_test_1(t_texture *texture, t_wolf_window *mgr_wolf_window)
{
	t_matrix3i	transform;

	transform.matrix[0][0] = (texture->width * 1.5) / (texture->screen_pos.coord.z + 3);
	transform.matrix[0][1] = 0;
	transform.matrix[0][2] = 0;

	transform.matrix[1][0] = 0;
	transform.matrix[1][1] = (texture->width * 1.5) / (texture->screen_pos.coord.z + 3);
	transform.matrix[1][2] = 0;

	transform.matrix[2][0] = 0;
 	transform.matrix[2][1] = 0;
	transform.matrix[2][2] = 0;

	draw_transform_texture(texture, mgr_wolf_window, &transform);
}

void	draw_wall_test_2(t_texture *texture, t_wolf_window *mgr_wolf_window)
{
	t_matrix3i	transform;

	transform.matrix[0][0] = (texture->width * 1.5) / (texture->screen_pos.coord.z + 3.0);
	transform.matrix[0][1] = 0;
	transform.matrix[0][2] = 0;

	transform.matrix[1][0] = 0;
	transform.matrix[1][1] = (texture->width * 1.5) / (texture->screen_pos.coord.z + 3.0);
	transform.matrix[1][2] = 0;

	transform.matrix[2][0] = 0;
 	transform.matrix[2][1] = 0;
	transform.matrix[2][2] = 0;

	draw_transform_texture(texture, mgr_wolf_window, &transform);
}

void	draw_transform_texture(t_texture *texture, t_wolf_window *mgr_wolf_window, t_matrix3i *transform)
{
	int		row;
	int		col;
	double	new_x;
	double	new_y;
	double	new_z;
	t_color	color;

	double	depth;

	row = 0;
	texture->world_pos.coord.x = WIN_WIDTH / 2 - (transform->matrix[0][0] / 2);
	texture->world_pos.coord.y = WIN_HEIGHT / 2 - (transform->matrix[0][0] / 2);
	while (row < texture->height)
	{
		col = 0;
		// delta_depth = -(h / texture->width) + row * (2.0 * h / (texture->height * texture->width));
		depth = 0;
		while (col < texture->width)
		{

			if (texture->memory_array[row * texture->width * BPP + col * BPP + 3] != 0)
			{
				new_x = col * transform->matrix[0][0] + row * transform->matrix[1][0];
				new_y = col * transform->matrix[0][1] + row * transform->matrix[1][1];
				new_z = col * transform->matrix[0][2] + row * transform->matrix[1][2];

				new_z = new_z + texture->world_pos.coord.z;

				// new_x = col;
				// new_y = row;
				new_x = (int)(new_x + texture->world_pos.coord.x);
				new_y = (int)(new_y + texture->world_pos.coord.y);

				color.col_32bit = *(int *)(&texture->memory_array[row * texture->width * BPP + col * BPP]);
				push_pixel(new_x, new_y, color, mgr_wolf_window->pixel_array);
			}

			col++;
			// depth = depth + (delta_depth);
		}
		row++;
	}
	(void)transform;
}
