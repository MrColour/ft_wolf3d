/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:08:12 by marvin            #+#    #+#             */
/*   Updated: 2020/03/04 22:42:49 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_structs.h"
#include "wolf.h"

void	get_player_position(char **map)
{

}

void	player_init(t_player *player, t_map *map)
{
	player->posx = map->width / 2;
	player->posy = map->height / 2;
	player->viewangle = 90;
	player->rotation = 0;
	map->map[player->posy][player->posx] = PLAYER_CHAR;
}
