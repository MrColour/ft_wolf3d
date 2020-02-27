/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:58:30 by kmira             #+#    #+#             */
/*   Updated: 2020/02/27 00:38:08 by kmira            ###   ########.fr       */
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
# include "wolf_structs.h"
# include "stddef.h"

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MACROS
*/

# define WIN_WIDTH 1024
# define WIN_HEIGHT 512
# define WIN_NAME "ft_Wolfenstien 3D"

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** file: initialization.c
*/

GLFWwindow *wolf_initialize(void);

#endif
