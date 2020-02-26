/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:31:31 by kmira             #+#    #+#             */
/*   Updated: 2020/02/25 18:28:51 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "wolf.h"

void	myInit(void)
{
	// breadth of picture boundary is 1 pixel
	glPointSize(1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// setting window dimension in X- and Y- direction
	gluOrtho2D(-780, 780, -420, 420);
}

void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	float x, y, i;

	glColor3ub(250, 0, 0);

	// iterate y up to 2*pi, i.e., 360 degree
	// with small increment in angle as
	// glVertex2i just draws a point on specified co-ordinate
	for ( i = 0; i < (M_PI); i += 0.001)
	{
		// let 200 is radius of circle and as,
		// circle is defined as x=r*cos(i) and y=r*sin(i)
			glColor3ub(0, 0, 250);
		x = 200 * cos(i);
		y = 200 * sin(i);

		glVertex2i(x, y);
	}
	glEnd();
	glFlush();
}

void key(unsigned char key, int x, int y)
{
	if (key == 53)
	{
		glutDestroyWindow(0);
	}
	(void)x;
	(void)y;
}

int main (int argc, char** argv)
{
	int win;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);

	// Giving name to window
	win = glutCreateWindow("Circle Drawing");
	myInit();

	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutMainLoop();
}
/* int main(int argc, char **argv)
{
	glutInit(argc, argv);
	glutCreateWindow("Test owo");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(100, 100);
	glutMainLoop();
} */
