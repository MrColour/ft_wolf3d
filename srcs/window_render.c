/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 01:19:10 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 17:17:25 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	update_pixels_(uint8_t **pixel_arr, int width, int height, int bpp)
{
	int	row;
	int	col;

	row = 0;
	glBegin(GL_POINTS);
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			glColor3ub(pixel_arr[row][col * bpp + RED_CHANNEL],
						pixel_arr[row][col * bpp + GREEN_CHANNEL],
						pixel_arr[row][col * bpp + BLUE_CHANNEL]);
			glVertex2i(col, row);
			col++;
		}
		row++;
	}
	glEnd();
	glFlush();
}

void		update_pixels(t_wolf_window *mgr_wolf_window)
{
	update_pixels_(mgr_wolf_window->pixel_array,
					WIN_WIDTH,
					WIN_HEIGHT,
					mgr_wolf_window->bpp);
}

void		push_pixel(int x, int y, t_color color, uint8_t **pixel_array)
{
	if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
		*(t_color *)(&pixel_array[y][x * BPP]) = color;
}

void		clear_pixel_array(uint8_t **pixel_array)
{
	ft_bzero(pixel_array[0],
			sizeof(**pixel_array) * (WIN_HEIGHT * WIN_WIDTH * BPP));
}
