/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 00:57:39 by kmira             #+#    #+#             */
/*   Updated: 2020/02/29 00:21:47 by kmira            ###   ########.fr       */
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

t_texture	*get_texture(int fd)
{
	int				i;
	int				j;
	int				width;
	int				height;
	unsigned char	channel;
	t_texture		*result;
	unsigned char	buffer[14 + 14 + 2 + 1];

	width = 0;
	height = 0;
	read(fd, buffer, 1);
	if (buffer[0] == 'W')
		width = get_num(fd);
	read(fd, buffer, 1);
	if (buffer[0] == 'H')
		height = get_num(fd);
	result = malloc(sizeof(*result));
	result->width = width;
	result->height = height;
	result->memory_array = malloc(sizeof(*result->memory_array) * (width * height * BPP));
	i = 0;
	while (i < width * height)
	{
		read(fd, buffer, 12);
		j = 0;
		while (j < 4)
		{
			channel = 0;
			if (ft_isdigit(buffer[j * 3 + 0]))
				channel += (buffer[j * 3 + 0] - '0') * 100;
			if (ft_isdigit(buffer[j * 3 + 1]))
				channel += (buffer[j * 3 + 1] - '0') * 10;
			if (ft_isdigit(buffer[j * 3 + 2]))
				channel += (buffer[j * 3 + 2] - '0') * 1;
			result->memory_array[i * BPP + j] = channel;
			j++;
		}
		// printf("FIRST col: %hhu, %hhu, %hhu, %hhu\n", 	result->memory_array[i * BPP + 0],
		// 												result->memory_array[i * BPP + 1],
		// 												result->memory_array[i * BPP + 2],
		// 												result->memory_array[i * BPP + 3]);
		read(fd, buffer, 1);
		i++;
	}
	return (result);
}

t_texture	*create_texture(char *file_path)
{
	int			fd;
	t_texture	*texture;

	fd = open(file_path, O_RDONLY);
	texture = get_texture(fd);
	return (texture);
}
