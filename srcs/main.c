/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:31:31 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 17:28:08 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(void)
{
	t_wolf_window	mgr_wolf_window;
	t_level_context	*curr_level;
	t_level_context	*new_level;

	new_level = NULL;
	mgr_wolf_window = wolf_initialize();
	curr_level = malloc(sizeof(t_level_main_menu));
	curr_level->init_self = init_main_menu;
	while (game_state() == GAME_STATE_OK && curr_level != NULL)
	{
		curr_level->init_self(curr_level, &mgr_wolf_window);
		new_level = curr_level->run_level(curr_level);
		curr_level = new_level;
	}
	wolf_destroy(&mgr_wolf_window);
	return (0);
}
