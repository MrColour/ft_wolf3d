/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_level_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 03:56:22 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 17:56:28 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_LEVEL_STRUCTS_H
# define WOLF_LEVEL_STRUCTS_H

#include "wolf_structs.h"

typedef struct	s_level_context
{
	t_wolf_window			*mgr_wolf_window;
	int						(*init_self)(struct s_level_context *level, t_wolf_window *mgr_wolf_window);
	struct s_level_context	*(*run_level)(struct s_level_context *self);
	struct s_level_context	*(*get_next_level)(struct s_level_context *self);
	int						(*clean_level)(struct s_level_context *self);
	int						level_ticks;
	int						level_state;

}				t_level_context;

typedef union	u_level_main_menu
{
	t_level_context			common_level;
	int						h_next_state;
}				t_level_main_menu;

typedef union	u_level_first
{
	t_level_context			common_level;
	int						h_next_state;
}				t_level_first;

#endif
