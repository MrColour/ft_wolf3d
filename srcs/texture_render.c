/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 03:27:09 by kmira             #+#    #+#             */
/*   Updated: 2020/03/05 01:38:48 by kmira            ###   ########.fr       */
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

void	draw_transform_texture(t_texture *texture, t_wolf_window *mgr_wolf_window, t_matrix3i *transform)
{
	int		row;
	int		col;
	double	new_x;
	double	new_y;
	t_color	color;

	int		cont_i;
	int		cont_j;

	row = 0;
	// texture->screen_pos.coord.x = texture->world_pos.coord.x - (texture->width / 2) * transform->matrix[0][0];
	texture->screen_pos.coord.y = texture->world_pos.coord.y - (texture->height / 2) * transform->matrix[1][1];

	if (transform->matrix[0][0] > CLIP_BOUNDARY || transform->matrix[1][1] > CLIP_BOUNDARY)
		return ;

	texture->screen_pos.coord.x = (3.0 * (texture->world_pos.coord.x)) / (texture->world_pos.coord.z + 3);

	texture->screen_pos.coord.x += WIN_WIDTH / 2;
	texture->screen_pos.coord.y += WIN_HEIGHT / 2;

	while (row < texture->height)
	{
		col = 0;
		while (col < texture->width)
		{

			if (texture->memory_array[row * texture->width * BPP + col * BPP + 3] != 0)
			{
				new_x = col * transform->matrix[0][0] + row * transform->matrix[1][0];
				new_y = col * transform->matrix[0][1] + row * transform->matrix[1][1];

				new_x = (int)(new_x + texture->screen_pos.coord.x);
				new_y = (int)(new_y + texture->screen_pos.coord.y);

				color.col_32bit = *(int *)(&texture->memory_array[row * texture->width * BPP + col * BPP]);

				cont_i = 0;
				while (cont_i <= (int)transform->matrix[0][0])
				{
					cont_j = 0;
					while (cont_j <=  (int)transform->matrix[1][1])
					{
						push_pixel(new_x + cont_i, new_y + cont_j, color, mgr_wolf_window->pixel_array);
						cont_j++;
					}
					cont_i++;
				}
			}
			col++;
		}
		row++;
	}
	(void)transform;
}

void	render_texture(t_texture *texture, t_wolf_window *window, t_player *player)
{
	return ;
}
