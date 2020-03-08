/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 03:27:09 by kmira             #+#    #+#             */
/*   Updated: 2020/03/07 20:21:05 by kmira            ###   ########.fr       */
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
				push_pixel(texture->screen_pos.coord.x + col,
							texture->screen_pos.coord.y + row,
							color, mgr_wolf_window->pixel_array);
			}
			col++;
		}
		row++;
	}
}

double		distance_vector3f(t_vector3f a, t_vector3f b)
{
	double	result;
	double	delta_x;
	double	delta_y;
	double	delta_z;

	delta_x = a.coord.x - b.coord.x;
	delta_y = a.coord.y - b.coord.y;
	delta_z = a.coord.z - b.coord.z;

	result = (delta_x * delta_x) + (delta_y * delta_y) + (delta_z * delta_z);

	result = pow(result, .5);
	return (result);
}

/*
**          (y)|        /(z)
**             |      /
**             |    /
**             |  /
**   __________|/_________ (x)
**            /|
**          /  |
**        /    |
**      /      |
**
** y-axis = world height; window height
** x-axis = world width ; window width
** z-axis = world depth
*/

void	render2_texture(t_texture *texture, t_wolf_window *window, t_player *player, char **map)
{
	t_vector3f	camera_location;

	printf("PLAYER_ANGLE: %f\n", player->angle);

	int		cam_depth_offset;

	cam_depth_offset = 3;
	camera_location.coord.x = player->pos.coord.x;
	camera_location.coord.y = 1; //Height
	camera_location.coord.z = player->pos.coord.y + cam_depth_offset;
	printf("CAM: (%f, %f, %f)\n", camera_location.coord.x, camera_location.coord.z, camera_location.coord.y);

	move_cursor_up(58);

	(void)texture;
	(void)window;
	(void)player;
	(void)map;
	return ;
}

// https://www.geogebra.org/3d/rfkkvfuq
