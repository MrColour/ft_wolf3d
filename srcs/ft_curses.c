/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:31:03 by kmira             #+#    #+#             */
/*   Updated: 2020/03/05 23:32:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_cursor_up(int amount)
{
	write(STDERR_FILENO, "\n\033[", 3);
	ft_putnbr_fd(amount, STDERR_FILENO);
	write(STDERR_FILENO, "A"ANSI_RESET, 5);
}
