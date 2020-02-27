/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:57:44 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 02:31:12 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_STRUCTS_H
# define WOLF_STRUCTS_H

typedef	struct	s_wolf_window
{
	GLFWwindow	*window;
	uint8_t		**pixel_array;
	int			bpp;
}				t_wolf_window;

/*
** The union has its bits in a certain order, do not change
** unless you know what you are doing and are on a machine
** thats ENDIANNESS is different from MacOs.
*/

typedef union	u_color
{
	uint32_t	col_32bit;
	uint8_t		col_8bit[4];
	struct
	{
		uint8_t	blue;
		uint8_t	green;
		uint8_t	red;
		uint8_t	alpha;
	}			channel;
}				t_color;

#endif
