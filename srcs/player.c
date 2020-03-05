/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:08:12 by marvin            #+#    #+#             */
/*   Updated: 2020/03/05 01:15:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_structs.h"
#include "wolf.h"

void	update_player(t_level_context *context, t_player *player)
{
	t_level_first	*level;
	char			**map;
	int				pos_x;
	int				pos_y;

	level = (t_level_first *)context;
	map = level->map;

	pos_x = player->posx;
	pos_y = player->posy;
	if (level->h_game_state == MOVE_UP && map[pos_y - 1][pos_x] != 'W' && map[pos_y - 1][pos_x] != 'R')
		player->posy--;
	else if (level->h_game_state == MOVE_DOWN && map[pos_y + 1][pos_x] != 'W' && map[pos_y + 1][pos_x] != 'R')
		player->posy++;
	else if (level->h_game_state == MOVE_RIGHT && map[pos_y][pos_x - 1] != 'W' && map[pos_y][pos_x - 1] != 'R')
		player->posx--;
	else if (level->h_game_state == MOVE_LEFT && map[pos_y][pos_x + 1] != 'W' && map[pos_y][pos_x + 1] != 'R')
		player->posx++;

	map[pos_y][pos_x] = ' ';
	map[player->posy][player->posx] = PLAYER_CHAR;
}

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
	player->posx = j - 1;
	player->posy = i - 1;
}

void	player_init(t_player *player, char **map)
{
	player->viewangle = 90;
	player->rotation = 0;

	get_player_position(player, map);
}
