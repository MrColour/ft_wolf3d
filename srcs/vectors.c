/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:10:42 by jjosephi          #+#    #+#             */
/*   Updated: 2020/03/08 09:26:02 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double		distance_vector3f(t_vector3f a, t_vector3f b)
{
	double	result;
	double	delta_x;
	double	delta_y;
	double	delta_z;

	delta_x = a.coord.x - b.coord.x;
	delta_y = a.coord.y - b.coord.y;
	delta_z = a.coord.z - b.coord.z;

	result = (delta_x * delta_x) + (delta_y * delta_y) + (delta_z * delta_z);

	result = pow(result, .5);
	return (result);
}

t_vector3f	vect_add(t_vector3f vect1, t_vector3f vect2)
{
	t_vector3f	new_vect;

	new_vect.coord.x = vect1.coord.x + vect2.coord.x;
	new_vect.coord.y = vect1.coord.y + vect2.coord.y;
	new_vect.coord.z = vect1.coord.z + vect2.coord.z;
	return (new_vect);
}

t_vector3f	ray_vect(t_player player, double rayangle)
{
	t_vector3f	ray;

	ray = rotate_vector(player.dir, rayangle);
	ray = Vect_add(ray, player.dir);

	return (ray);
}
