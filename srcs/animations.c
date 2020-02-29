/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:30:14 by kmira             #+#    #+#             */
/*   Updated: 2020/02/29 00:11:28 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fill_shared_lock(t_animation *animation, int *shared_lock)
{
	t_animation	*root;

	root = animation;
	if (animation == NULL)
		return ;
	animation->shared_lock = shared_lock;
	animation = animation->next;
	while (animation != NULL && animation != root)
	{
		animation->shared_lock = shared_lock;
		animation = animation->next;
	}
}

void	change_animation(t_animation **addr, t_level_context *level)
{
	t_animation	*current_animation;
	t_animation	*next_animation;
	int			change_next;

	current_animation = *addr;
	if (current_animation == NULL)
		return ;
	change_next = current_animation->update_sprite(current_animation, level);
	if (change_next != 0)
	{
		next_animation = current_animation->next;
		*addr = next_animation;
	}
}
