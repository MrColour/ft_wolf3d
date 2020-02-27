/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 01:19:10 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 02:31:19 by kmira            ###   ########.fr       */
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
			glVertex2i(row, col);
			col++;
		}
		row++;
	}
	glEnd();
	glFlush();
}

void		update_pixels(t_wolf_window *h_wolf_window)
{
	update_pixels_(h_wolf_window->pixel_array,
					WIN_WIDTH,
					WIN_HEIGHT,
					h_wolf_window->bpp);
}

void		push_pixel(int x, int y, t_color color, uint8_t **pixel_array)
{
	if (0 < x && x < WIN_HEIGHT && 0 < y && y < WIN_WIDTH)
		*(t_color *)(&pixel_array[x][y * BBP]) = color;
}
