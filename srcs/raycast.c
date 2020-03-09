/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:54:08 by marvin            #+#    #+#             */
/*   Updated: 2020/03/08 18:30:57 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_structs.h"
#include "wolf.h"

#define LEFT_SIDE 2
#define RIGHT_SIDE 3
#define TOP_SIDE 0
#define BOTTOM_SIDE 1

t_rayhit vector_step(t_vector3f m, t_map map, t_player player)
{
	double d_x;
	double d_y;
	double x;
	double y;

	double new_x;
	double new_y;

	t_rayhit hit;
	int		toggle;

	d_x = 1;
	d_y = 1;
	if (m.coord.x < 0)
		d_x = -1;
	if (m.coord.y < 0)
		d_y = -1;
	x = player.pos.coord.x + 1;
	y = player.pos.coord.y + 1;
	toggle = 1;
	while (1)
	{
		new_y = (m.coord.y / m.coord.x) * (x - player.pos.coord.x + 1) + player.pos.coord.y + 1;
		new_x = (m.coord.x / m.coord.y) * (y - player.pos.coord.y + 1) + player.pos.coord.x + 1;
		// printf("Here (%f, %f)\n", new_x, new_y);
		if (new_x < 0 || new_x > 10 || new_y < 0 || new_y > 10 || y < 0 || y > 10 || x > 10 || x < 0)
			break ;
		if (map.map[(int)x][(int)new_y] == 'W')
		{
			hit.pos.coord.x = x;
			hit.pos.coord.y = new_y;
			(m.coord.x > 0) ? (hit.side = RIGHT_SIDE) : (hit.side = LEFT_SIDE);
			// printf("END\n");
			toggle = 1;
			break ;
		}
		if (map.map[(int)new_x][(int)y] == 'W')
		{
			hit.pos.coord.x = new_x;
			hit.pos.coord.y = y;
			(m.coord.y > 0) ? (hit.side = TOP_SIDE) : (hit.side = BOTTOM_SIDE);
			toggle = 1;
			break ;
		}
		y += d_y;
		x += d_x;
	}
	// printf("HIT at: (%f, %f)\n", hit.pos.coord.x, hit.pos.coord.y);
	if (toggle == 1)
		return (hit);
	hit.pos.coord.x = -1;
	hit.pos.coord.y = -1;
	return (hit);
}

# define WIN_VIEW_ANGLE 45

void	raycast(t_player *player, t_map *map, t_wolf_window *wolf_window)
{
	int			i;
	t_ray		ray;
	t_vector3f	delta_ray;
	t_vector3f	edge_1;
	t_vector3f	edge_2;

	player->dir = angle_to_vector(player->angle);

	edge_1 = rotate_vector(player->dir, WIN_VIEW_ANGLE);
	edge_2 = rotate_vector(player->dir, -WIN_VIEW_ANGLE);

	printf("DIR: (%f, %f)\n", player->dir.coord.x, player->dir.coord.y);
	printf("EDGE_1: (%f, %f)\n", edge_1.coord.x, edge_1.coord.y);
	printf("EDGE_2: (%f, %f)\n", edge_2.coord.x, edge_2.coord.y);

	delta_ray.coord.x = ((edge_2.coord.x - edge_1.coord.x) / WIN_WIDTH);
	delta_ray.coord.y = ((edge_2.coord.y - edge_1.coord.y) / WIN_WIDTH);

	printf("Delta: (%f, %f)\n", delta_ray.coord.x, delta_ray.coord.y);

	ray.vect = rotate_vector(player->dir, WIN_VIEW_ANGLE);

	printf("RAY VECT: (%f, %f)\n", ray.vect.coord.x, ray.vect.coord.y);

	i = 0;
	while (i < WIN_WIDTH)
	{
		render_pixel_col(vector_step(ray.vect, *map, *player), map, player, wolf_window, i);
		ray.vect = vect_add(ray.vect, delta_ray);
		i++;
	}
	printf("RAY VECT: (%f, %f)\n", ray.vect.coord.x, ray.vect.coord.y);
}
