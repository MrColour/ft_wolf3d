/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:00:33 by kmira             #+#    #+#             */
/*   Updated: 2020/03/07 18:32:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double			to_radians(double angle)
{
	double		result;

	result = (angle * M_PI) / (180.0);
	return (result);
}

t_vector3f		vector_at_angle(double angle, double scale)
{
	t_vector3f	result;
	double		radian;

	radian = to_radians(angle);
	result.coord.x = cos(angle) * scale;
	result.coord.y = sin(angle) * scale;
	return (result);
}

t_vector3f		angle_to_vector(double angle)
{
	return (vector_at_angle(angle, 1.0));
}

t_vector3f		rotate_vector(t_vector3f vector, double angle)
{
	t_vector3f	result;
	double		cos_a;
	double		sin_a;
	double		radian;

	radian = to_radians(angle);
	cos_a = cos(radian);
	sin_a = sin(radian);
	result.coord.x = vector.coord.x * cos_a - vector.coord.y * sin_a;
	result.coord.y = vector.coord.x * sin_a + vector.coord.y * cos_a;
	result.coord.z = 0;
	return (result);
}
