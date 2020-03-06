/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 03:27:09 by kmira             #+#    #+#             */
/*   Updated: 2020/03/06 04:07:22 by kmira            ###   ########.fr       */
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

void	draw_transform2_texture(t_texture *texture, t_wolf_window *mgr_wolf_window, t_matrix3i *transform)
{
	int		row;
	int		col;

	double	new_x;
	double	new_y;

	t_color	color;

	int		cont_i;
	int		cont_j;

	row = 0;
	while (row < texture->height)
	{
		col = 0;
		while (col < texture->width)
		{
			if (texture->memory_array[row * texture->width * BPP + col * BPP + 3] != 0)
			{

				new_x = col * transform->matrix[0][0] + texture->screen_pos.coord.x;
				new_y = row * transform->matrix[1][1] + texture->screen_pos.coord.y;

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

t_vector3i	wall_start(char **map, t_player *player)
{
	int			row;
	int			col;
	t_vector3i	distance;

	distance.coord.y = 0;
	row = player->posy - 1;
	col = player->posx;
	while (row > 0 && map[row][col] == ' ')
	{
		row--;
		distance.coord.y++;
	}
	distance.coord.x = player->posx % EXPAND_AMOUNT;
	return (distance);
}

/*
** So the problem here seems to be that I have to transform how much
** each pixel from the texture is from the actual world.
** the ratio should be the total depth and how far back the camera is
** from the screen. This ratio determines the x-axis stretching
** or expanding.
*/

/*
** On that note there may be an easier way by finding the angle
** doing atan, then using that angle with the fixed camera (screen - camera)
** distance to find the position on the screen.
*/

void	render_texture(t_texture *texture, t_wolf_window *window, t_player *player, char **map)
{
	t_vector3i	texture_world_pos;

	texture_world_pos = wall_start(map, player);
	// texture_world_pos.coord.z = (texture->height * 2.0) / WIN_HEIGHT;
	texture_world_pos.coord.z = 2;
	printf("Wall pos: (%i, %i, %i)\n", texture_world_pos.coord.x, texture_world_pos.coord.y, texture_world_pos.coord.z);

	double	cam_x;
	double	cam_y;
	double	cam_z;
	double	cam_back;
	double	offset_x;
	double	offset_y;

	double	end_offset_x;
	double	end_offset_y;

	t_matrix3i	transform;

	cam_back = 2.0;

	cam_x = .5 + texture_world_pos.coord.x;
	cam_y = texture_world_pos.coord.y + cam_back;
	cam_z = 1;

	printf("CAM: (%f, %f, %f)\n", cam_x, cam_y, cam_z);

	double scale = 1.8;

	offset_x = 2.0 - (((cam_x) * (cam_back)) / (cam_y + 1));
	offset_y = ((((cam_z) * (cam_back)) / (cam_y + 1)) * scale) + 1;

	end_offset_x = ((EXPAND_AMOUNT - cam_x) * (cam_back) / (cam_y + 1)) + 2;
	end_offset_y = 2 - offset_y;

	printf("Screen: (%f, %f)\n", offset_x, offset_y);
	printf("END   : (%f, %f)\n", end_offset_x, end_offset_y);

	transform.matrix[0][0] = end_offset_x - offset_x;
	transform.matrix[1][1] = offset_y - end_offset_y;

	offset_x = (offset_x / (4)) * WIN_WIDTH;
	end_offset_x = (end_offset_x / (4)) * WIN_WIDTH;

	offset_y = WIN_HEIGHT - (offset_y / (2)) * WIN_HEIGHT;
	end_offset_y = WIN_HEIGHT - (end_offset_y / (2)) * WIN_HEIGHT;

	printf("POST Screen: (%f, %f)\n", offset_x, offset_y);
	printf("POST END   : (%f, %f)\n", end_offset_x, end_offset_y);

	texture->screen_pos.coord.x = offset_x;
	texture->screen_pos.coord.y = offset_y;

	printf("X Scale: %f Y Scale: %f\n", transform.matrix[0][0], transform.matrix[1][1]);

	draw_transform2_texture(texture, window, &transform);

	move_cursor_up(59);

	(void)texture;
	(void)window;
	(void)player;
	return ;
}
