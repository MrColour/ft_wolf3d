/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_state.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:07:47 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 04:22:01 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_STATE_H
# define META_STATE_H

# define GAME_STATE_GET 1
# define GAME_STATE_SET 2

# define GAME_STATE_OK 42

int		game_state(void);
int		game_running(int option, int value);

#endif
