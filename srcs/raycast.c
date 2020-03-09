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
	d_x = 1;
	d_y = 1;
	if (m.coord.x < 0)
		d_x = -1;
	if (m.coord.y < 0)
		d_y = -1;
	x = player.pos.coord.x;
	y = player.pos.coord.y;
	while (1)
	{
		new_y = (m.coord.y / m.coord.x) * (x - player.pos.coord.x) + player.pos.coord.y;
		new_x = (m.coord.x / m.coord.y) * (y - player.pos.coord.y) + player.pos.coord.x;
		if (map.map[(int)x][(int)new_y] == 'W')
		{
			hit.pos.coord.x = x;
			hit.pos.coord.y = new_y;
			(m.coord.x > 0) ? (hit.side = RIGHT_SIDE) : (hit.side = LEFT_SIDE);
			return (hit);
		}
		else if (map.map[(int)new_x][(int)y] == 'W')
		{
			hit.pos.coord.x = new_x;
			hit.pos.coord.y = y;
			(m.coord.y > 0) ? (hit.side = TOP_SIDE) : (hit.side = BOTTOM_SIDE);
			return (hit);
		}
		y += d_y;
		x += d_x;
	}
	hit.pos.coord.x = -1;
	hit.pos.coord.y = -1;
	return (hit);
}

# define WIN_VIEW_ANGLE 45

t_ray	raycast(t_player *player, t_map *map)
{
	int			i;
	int			n = 0;
	double		ray_angle;
	t_ray		ray;
	t_vector3f	delta_ray;
	t_vector3f	edge_1;
	t_vector3f	edge_2;
	t_vector3f	at_ray;


	i = 0;
	ray_angle = player->dir.coord.x;

	player->dir = angle_to_vector(player->angle);

	edge_1 = rotate_vector(player->dir, WIN_VIEW_ANGLE);
	edge_2 = rotate_vector(player->dir, -WIN_VIEW_ANGLE);
	
	delta_ray.coord.x = ((edge_1.coord.x - edge_2.coord.x) / WIN_WIDTH);
	delta_ray.coord.y = ((edge_1.coord.y - edge_2.coord.y) / WIN_WIDTH);
	
	ray.vect = rotate_vector(player->dir, WIN_VIEW_ANGLE);

	while (i > player->dir.coord.x * -1)
	{
		render_pixel_col(vector_step(ray.vect, *map, *player), map, player);
		ray.vect = vect_add(ray.vect, delta_ray);
	}
}
