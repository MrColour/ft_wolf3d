/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:54:08 by marvin            #+#    #+#             */
/*   Updated: 2020/03/07 20:51:31 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_structs.h"
#include "wolf.h"

void	raycast(t_player *player, t_map *map)
{
	int i;
	double ray_angle;
	t_ray ray;
	
	i = 0;
	ray_angle = 90;
	player->dir = rotate_vector(player->pos, player->angle);
	 rotate_vector(player->cam.pos, player->angle);
	while (i < player->cam.length.coord.x)
	{
		ray.vect = ray_vect(*player, player->cam, ray_angle);
		
		ray_angle -= player->view_angle / WIN_WIDTH;
	}
	
}
