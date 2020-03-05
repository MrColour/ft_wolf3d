/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:54:08 by marvin            #+#    #+#             */
/*   Updated: 2020/03/04 04:44:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_structs.h"

void	raycast(t_player *player, t_map *map)
{
	char	**map;
	int		i;
	int		n;
	float	raystart;
	float	rayend;

	raystart = player->posx - player->viewangle / 2 + player->rotation;
	rayend = player->posx - player->viewangle / 2;
	// while ()
	// {
	// }
}
