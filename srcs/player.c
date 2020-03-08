/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:08:12 by marvin            #+#    #+#             */
/*   Updated: 2020/03/07 18:55:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_structs.h"
#include "wolf.h"

# define MOVEMENT_SPEED .1

void	update_player(t_level_context *context, t_player *player)
{
	t_level_first	*level;
	char			**map;
	int				pos_x;
	int				pos_y;

	level = (t_level_first *)context;
	map = level->map;

	pos_x = (int)player->pos.coord.x;
	pos_y = (int)player->pos.coord.y;
	if (level->h_game_state == MOVE_UP && map[pos_y - 1][pos_x] != 'W' && map[pos_y - 1][pos_x] != 'R')
		player->pos.coord.y -= MOVEMENT_SPEED;
	else if (level->h_game_state == MOVE_DOWN && map[pos_y + 1][pos_x] != 'W' && map[pos_y + 1][pos_x] != 'R')
		player->pos.coord.y += MOVEMENT_SPEED;
	else if (level->h_game_state == MOVE_RIGHT && map[pos_y][pos_x - 1] != 'W' && map[pos_y][pos_x - 1] != 'R')
		player->pos.coord.x -= MOVEMENT_SPEED;
	else if (level->h_game_state == MOVE_LEFT && map[pos_y][pos_x + 1] != 'W' && map[pos_y][pos_x + 1] != 'R')
		player->pos.coord.x += MOVEMENT_SPEED;

	map[pos_y][pos_x] = ' ';
	map[(int)player->pos.coord.y][(int)player->pos.coord.x] = PLAYER_CHAR;
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
	player->pos.coord.x = j - 1;
	player->pos.coord.y = i - 1;
}

void	player_init(t_player *player, char **map)
{
	player->angle = 90;

	get_player_position(player, map);
}
