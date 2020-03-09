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

void	render2_texture(t_texture *texture, t_wolf_window *window, t_player *player, t_map *map)
{
	printf("PLAYER_ANGLE: %f\n", player->angle);
	printf("PLAYER: (%f, %f)\n", player->pos.coord.x, player->pos.coord.y);

	raycast(player, map, window);

	move_cursor_up(22);

	(void)texture;
	(void)window;
	(void)player;
	(void)map;
	return ;
}

// https://www.geogebra.org/3d/rfkkvfuq

void	render_pixel_col(t_rayhit hitspot, t_map *map, t_player *player, t_wolf_window *wolf_window, int col)
{
	double	depth;
	t_color	color_1;
	t_color	color_2;
	t_color	color_3;
	t_color	color_4;
	int		i;
	int		height;

	if (hitspot.pos.coord.x == -1 && hitspot.pos.coord.y == -1)
		return ;
	color_1.col_32bit = 0xf35588; //TOP      PINK
	color_2.col_32bit = 0x1eb2a6; //BOTTOM   1eb2a6
	color_3.col_32bit = 0xffe75e; //LEFT     YELLOW
	color_4.col_32bit = 0xdab8f3; //RIGHT    PURPLE
	player->pos.coord.z = 0;
	hitspot.pos.coord.z = 0;

	depth = distance_vector3f(player->pos, hitspot.pos);
	i = 0;
	height = (5 / depth) * 70;
	while (i < height)
	{
		if (hitspot.side == TOP_SIDE)
			push_pixel(col, i - height / 2 + WIN_HEIGHT / 2, color_1, wolf_window->pixel_array);
		else if (hitspot.side == BOTTOM_SIDE)
			push_pixel(col, i - height / 2 + WIN_HEIGHT / 2, color_2, wolf_window->pixel_array);
		else if (hitspot.side == LEFT_SIDE)
			push_pixel(col, i - height / 2 + WIN_HEIGHT / 2, color_3, wolf_window->pixel_array);
		else
			push_pixel(col, i - height / 2 + WIN_HEIGHT / 2, color_4, wolf_window->pixel_array);
		i++;
	}
	(void)map;
}
