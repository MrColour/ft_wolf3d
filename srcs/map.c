/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 05:09:43 by kmira             #+#    #+#             */
/*   Updated: 2020/03/04 18:34:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#define BUFF_SIZE 1024

char	*get_raw_map(char *file_name)
{
	int		fd;
	int		btyes_read;
	int		last_read;
	char	buffer[BUFF_SIZE];
	char	*result;

	last_read = 1;
	btyes_read = 0;
	fd = open(file_name, O_RDONLY);
	while (last_read)
	{
		last_read = read(fd, buffer, BUFF_SIZE);
		btyes_read += last_read;
	}
	result = malloc(sizeof(*result) * (btyes_read + 1));
	close(fd);
	fd = open(file_name, O_RDONLY);
	read(fd, result, btyes_read);
	result[btyes_read] = '\0';
	return (result);
}

int		get_line_count(char *raw_map)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (raw_map[i] != '\0')
	{
		if (raw_map[i] == '\n')
			result++;
		i++;
	}
	return (result);
}

char	*get_map(char *file_name)
{
	char	*raw_map;
	char	**bounded_map;
	int		lines;
	int		i;

	raw_map = get_raw_map(file_name);
	lines = get_line_count(raw_map);

	bounded_map = malloc(sizeof(*bounded_map) * (lines + 2 + 1));
	i = 1;
	// while (i - 1 < lines)
	// {
	// 	bounded_map()
	// 	i++;
	// }
	return (raw_map);
}
