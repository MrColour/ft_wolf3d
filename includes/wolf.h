/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:58:30 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 22:44:43 by kmira            ###   ########.fr       */
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
# include "meta_state.h"
# include "wolf_level_structs.h"
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
# define BPP BYTES_PER_PIXEL

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

void			update_pixels(t_wolf_window *mgr_wolf_window);
void			push_pixel(int x, int y, t_color color, uint8_t **pixel_array);
void			clear_pixel_array(uint8_t **pixel_array);
void			refresh_screen(t_wolf_window *mgr_wolf_window);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: wolf_destroy.c
** Description: Deconstructor functions for freeing memory.
*/

void			wolf_destroy(t_wolf_window *mgr_wolf_window);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: main_menu.c
*/

int				init_main_menu(t_level_context *level, t_wolf_window *mgr_wolf_window);
int				level_is_running_main_menu(t_level_context *self);
t_level_context	*run_level_main_menu(t_level_context *self);
t_level_context	*get_next_level_main_menu(struct s_level_context *self);
int				clean_main_menu(t_level_context *self);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: level_first_level.c
*/

t_level_context	*first_level(t_wolf_window *mgr_wolf_window);

int				init_first_level(t_level_context *level, t_wolf_window *mgr_wolf_window);
int				level_is_running_first_level(t_level_context *self);
t_level_context	*run_level_first_level(t_level_context *self);
t_level_context	*get_next_level_first_level(struct s_level_context *self);
int				clean_level_first_level(t_level_context *self);

#endif
