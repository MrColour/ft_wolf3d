/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:57:22 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 02:09:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#define WIN_CENTER 0
#define WIN_TOP_LEFT 1
#define WIN_CARTESIAN 2

static void		window_origin(int option)
{
	if (option == WIN_CENTER)
	{
		glOrtho(-(WIN_WIDTH / 2), (WIN_WIDTH / 2),
				-(WIN_HEIGHT / 2), (WIN_HEIGHT / 2), 0.0, 1.0);
	}
	else if (option == WIN_TOP_LEFT)
		glOrtho(0, WIN_WIDTH, (WIN_HEIGHT), 0, 0.0, 1.0);
	else
		glOrtho(0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0, 1.0);
}

static uint8_t	**create_pixel_array(int width, int height, int bpp)
{
	uint8_t	*memory;
	uint8_t	**result;
	int		row;

	row = 0;
	result = malloc(sizeof(*result) * (height + 1));
	ft_bzero(result, sizeof(*result) * (height + 1));
	memory = malloc(sizeof(*memory) * (height * width * bpp));
	ft_bzero(memory, sizeof(*memory) * (height * width * bpp));
	while (row < height)
	{
		result[row] = &memory[row * width * bpp];
		row++;
	}
	result[row] = NULL;
	return (result);
}

t_wolf_window	wolf_initialize(void)
{
	t_wolf_window	h_wolf_win;

	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	h_wolf_win.window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT,
							WIN_NAME, NULL, NULL);
	glfwMakeContextCurrent(h_wolf_win.window);
	glPointSize(1.0);
	glMatrixMode(GL_MODELVIEW);
	window_origin(WIN_TOP_LEFT);
	glClear(GL_COLOR_BUFFER_BIT);
	h_wolf_win.bpp = BYTES_PER_PIXEL;
	h_wolf_win.pixel_array = create_pixel_array(WIN_WIDTH, WIN_HEIGHT,
												h_wolf_win.bpp);
	return (h_wolf_win);
}
