/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 03:27:09 by kmira             #+#    #+#             */
/*   Updated: 2020/02/28 21:30:38 by kmira            ###   ########.fr       */
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
