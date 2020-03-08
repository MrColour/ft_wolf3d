/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:54:08 by marvin            #+#    #+#             */
/*   Updated: 2020/03/08 09:30:38 by jjosephi         ###   ########.fr       */
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
	ray_angle = player->dir.coord.x;
	player->dir = rotate_vector(player->pos, player->angle);
	while (i > player->dir.coord.x * -1)
	{
		ray.vect = ray_vect(*player, ray_angle);
		 
		ray_angle -= player->dir.coord.x/ WIN_WIDTH;
	}
	
}
