/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:08:12 by marvin            #+#    #+#             */
/*   Updated: 2020/03/08 09:34:26 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_structs.h"
#include "wolf.h"

#define MOVEMENT_SPEED .1
#define ROTATE_SPEED 12.5

void	modulo_angle(double *angle)
{
	double	result;

	result = *angle;
	if (*angle >= 360)
		result = *angle - 360.0;
	if (*angle < 0)
		result = 360.0 + *angle;
	*angle = result;
}

void	update_player(t_level_context *context, t_player *player)
{
	t_level_first	*level;
	char			**map;
	int				pos_x;
	int				pos_y;

	level = (t_level_first *)context;
	map = level->map.map;

	pos_x = (int)player->pos.coord.x;
	pos_y = (int)player->pos.coord.y;
	if (level->h_game_state & MOVE_UP && map[pos_y - 1][pos_x] != 'W' && map[pos_y - 1][pos_x] != 'R')
		player->pos.coord.y -= MOVEMENT_SPEED;
	else if (level->h_game_state & MOVE_DOWN && map[pos_y + 1][pos_x] != 'W' && map[pos_y + 1][pos_x] != 'R')
		player->pos.coord.y += MOVEMENT_SPEED;
	else if (level->h_game_state & MOVE_RIGHT && map[pos_y][pos_x - 1] != 'W' && map[pos_y][pos_x - 1] != 'R')
		player->pos.coord.x -= MOVEMENT_SPEED;
	else if (level->h_game_state & MOVE_LEFT && map[pos_y][pos_x + 1] != 'W' && map[pos_y][pos_x + 1] != 'R')
		player->pos.coord.x += MOVEMENT_SPEED;
	else if (level->h_game_state & ROTATE_LEFT)
		player->angle -= ROTATE_SPEED;
	else if (level->h_game_state & ROTATE_RIGHT)
		player->angle += ROTATE_SPEED;

	modulo_angle(&player->angle);

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
	player->pos.coord.x = j - 1;
	player->pos.coord.y = i - 1;
}

void	player_init(t_player *player, char **map)
{
	player->angle = 0;
	player->dir.coord.x = 4;
	player->dir.coord.y = 0;
	get_player_position(player, map);
}
