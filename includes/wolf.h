/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:58:30 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 02:20:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include <OpenGL/gltypes.h>
# include <OpenGL/glext.h>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>

# include "glfw3.h"
# include "glfw3native.h"

# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# include "debug.h"
# include "libft.h"
# include "wolf_structs.h"
# include "stddef.h"

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MACROS
*/

# define WIN_WIDTH 1024
# define WIN_HEIGHT 512
# define WIN_NAME "ft_Wolfenstien 3D"

# define BYTES_PER_PIXEL 4
# define BBP BYTES_PER_PIXEL

# define RED_CHANNEL 2
# define GREEN_CHANNEL 1
# define BLUE_CHANNEL 0
# define ALPHA_CHANNEL 3

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: initialization.c
*/

t_wolf_window	wolf_initialize(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: window_render.c
** Description: makes our usage of OpenGl more like mlx
** library.
*/

void		update_pixels(t_wolf_window *h_wolf_window);
void		push_pixel(int x, int y, t_color color, uint8_t **pixel_array);

#endif
