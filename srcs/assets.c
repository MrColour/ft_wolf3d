/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 00:57:39 by kmira             #+#    #+#             */
/*   Updated: 2021/01/19 00:35:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			get_num(int fd)
{
	int		i;
	int		result;
	char	buff[20];

	i = 0;
	ft_bzero(buff, sizeof(buff));
	read(fd, &buff[i], 1);
	while (ft_isdigit(buff[i]) == 1)
	{
		i++;
		read(fd, &buff[i], 1);
	}
	result = ft_atoi(buff);
	return (result);
}

/*
** The python script that makes ft_png has the x and the y reversed
** Because of this the wierd modulo and multiplication math has to be
** done so that the pixel data of the texture is in the correct place.
** This is the row:
** 	(i % result->height) * result->width
** This is the col:
** 		( i / result->height)
*/

t_texture	*get_texture(int fd)
{
	int				i;
	int				j;
	uint32_t		color;
	t_texture		*result;
	unsigned char	buffer[12 + 1];

	result = malloc(sizeof(*result));
	read(fd, buffer, 1);
	if (buffer[0] == 'W')
		result->width = get_num(fd);
	read(fd, buffer, 1);
	if (buffer[0] == 'H')
		result->height = get_num(fd);
	result->memory_array = malloc(sizeof(*result->memory_array) * (result->width * result->height * BPP));
	i = -1;
	while (++i < result->width * result->height)
	{
		read(fd, buffer, 12);
		j = -1;
		color = 0;
		while (++j < 4)
		{
			color = color << 8;
			if (ft_isdigit(buffer[j * 3 + 0]))
				color += (buffer[j * 3 + 0] - '0') * 100;
			if (ft_isdigit(buffer[j * 3 + 1]))
				color += (buffer[j * 3 + 1] - '0') * 10;
			if (ft_isdigit(buffer[j * 3 + 2]))
				color += (buffer[j * 3 + 2] - '0') * 1;
		}
		*(uint32_t *)(&result->memory_array[ ( ((i % result->height) * result->width) + (( i / result->height)) ) * BPP]) = color;
		read(fd, buffer, 1);
	}
	return (result);
}

t_texture	*create_texture(char *file_path)
{
	int			fd;
	t_texture	*texture;

	fd = open(file_path, O_RDONLY);
	texture = get_texture(fd);
	close(fd);
	return (texture);
}
