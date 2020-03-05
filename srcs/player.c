/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:08:12 by marvin            #+#    #+#             */
/*   Updated: 2020/03/04 22:56:52 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_structs.h"
#include "wolf.h"

void	get_player_position(t_player *player, char **map)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	found = 0;
	while (map[i] != NULL && found == 0)
	{
		j = 0;
		while (map[i][j] != '\0' && found == 0)
		{
			if (map[i][j] == PLAYER_CHAR)
				found = 1;
			j++;
		}
		i++;
	}
	printf("PLAYER: (%d, %d)\n", j, i);
	player->posx = j;
	player->posy = i;
}

void	player_init(t_player *player, char **map)
{
	player->viewangle = 90;
	player->rotation = 0;

	get_player_position(player, map);
}
