/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:31:31 by kmira             #+#    #+#             */
/*   Updated: 2020/02/26 16:55:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "wolf.h"

void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(250, 0, 0);

	glBegin(GL_POINTS);

	float x, y, i;
	int	j = 0;

	glColor3ub(250, 0, 0);

	// iterate y up to 2*pi, i.e., 360 degree
	// with small increment in angle as
	// glVertex2i just draws a point on specified co-ordinate
	for ( i = 0; i < 2 * (M_PI); i += 0.001)
	{
		// let 200 is radius of circle and as,
		// circle is defined as x=r*cos(i) and y=r*sin(i)
		if (j % 2 == 0)
			glColor3ub(0, 0, 250);
		else
			glColor3ub(0, 250, 0);
		x = 256 * cos(i);
		y = 256 * sin(i);

		glVertex2i(x, y);
		j++;
	}
	glEnd();
	glFlush();
}

int main (int argc, char** argv)
{
	wolf_initialize();
	// glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// glutDisplayFunc(display);
	// glutMainLoop();
	(void)argc;
	(void)argv;
}
