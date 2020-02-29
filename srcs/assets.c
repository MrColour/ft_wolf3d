/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 00:57:39 by kmira             #+#    #+#             */
/*   Updated: 2020/02/29 02:14:02 by kmira            ###   ########.fr       */
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
	unsigned char	channel;
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
		while (++j < 4)
		{
			channel = 0;
			if (ft_isdigit(buffer[j * 3 + 0]))
				channel += (buffer[j * 3 + 0] - '0') * 100;
			if (ft_isdigit(buffer[j * 3 + 1]))
				channel += (buffer[j * 3 + 1] - '0') * 10;
			if (ft_isdigit(buffer[j * 3 + 2]))
				channel += (buffer[j * 3 + 2] - '0') * 1;
			result->memory_array[i * BPP + j] = channel;
		}
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
	return (texture);
}
