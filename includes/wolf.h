/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:58:30 by kmira             #+#    #+#             */
/*   Updated: 2020/03/04 22:55:50 by kmira            ###   ########.fr       */
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

# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "libft.h"
# include "meta_state.h"
# include "wolf_level_structs.h"
# include "wolf_structs.h"

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

# define PLAYER_CHAR 'P'
# define ENEMY_CHAR '0'
# define WALL_CHAR 'W'

# define CLIP_BOUNDARY 4

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

int					level_init_main_menu(t_level_context *level, t_wolf_window *mgr_wolf_window);
t_level_context	*	level_loop_main_menu(t_level_context *self);
int					level_running_main_menu(t_level_context *self);
void				level_get_input_main_menu(t_level_context *self);
t_level_context	*	level_get_next_main_menu(struct s_level_context *self);
int					level_clean_main_menu(t_level_context *self);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: level_first_level.c
*/

t_level_context	*first_level(t_wolf_window *mgr_wolf_window);

int					level_init_first_level(t_level_context *level, t_wolf_window *mgr_wolf_window);
t_level_context	*	level_loop_first_level(t_level_context *self);
int					level_running_first_level(t_level_context *self);
void				level_get_input_first_level(t_level_context *self);
t_level_context	*	level_get_next_first_level(struct s_level_context *self);
int					level_clean_first_level(t_level_context *self);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: assets.c
*/

t_texture	*create_texture(char *file_path);

void		draw_texture(t_texture *texture, t_wolf_window *mgr_wolf_window);
void		draw_transform_texture(t_texture *texture, t_wolf_window *mgr_wolf_window, t_matrix3i *transform);

t_animation	*play_button_animation(void);
t_animation	*quit_button_animation(void);
t_animation	*tittle_animation(void);
t_animation	*wall_animation(void);
t_animation	*player_animation(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: animation.c
*/

void	fill_shared_lock(t_animation *animation, int *shared_lock);
void	change_animation(t_animation **addr, t_level_context *level);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: map.c
*/

char	**get_map(char *file_name);
void	print_map(char **map);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: player.c
*/

void	player_init(t_player *player, char **map);

#endif

