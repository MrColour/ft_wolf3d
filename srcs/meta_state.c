/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:05:54 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 04:21:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_state.h"

int	game_running(int option, int value)
{
	static int	status;

	if (option == GAME_STATE_SET)
		status = value;
	return (status);
}

int		game_state(void)
{
	int	result;

	result = game_running(GAME_STATE_GET, 0);
	return (result);
}
