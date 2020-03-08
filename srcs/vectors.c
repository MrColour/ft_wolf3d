/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:10:42 by jjosephi          #+#    #+#             */
/*   Updated: 2020/03/07 18:11:49 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_structs.h"

t_vector3f Vect_add(t_vector3f vect1, t_vector3f vect2)
{
	t_vector3f  new_vect;
	
	new_vect.coord.x = vect1.coord.x + vect2.coord.x;
	new_vect.coord.y = vect1.coord.y + vect2.coord.y;
	new_vect.coord.z = vect1.coord.z + vect2.coord.z;
	return (new_vect);
}