/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 05:09:43 by kmira             #+#    #+#             */
/*   Updated: 2020/03/04 22:46:48 by kmira            ###   ########.fr       */
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

#define EXPAND_AMOUNT 5

void	fill_square(char **map, int col_start, int row_start, char fill)
{
	int		delta_i;
	int		delta_j;

	delta_i = 0;
	while (delta_i < EXPAND_AMOUNT)
	{
		if (fill == 'E' || fill == 'P')
			map[row_start * EXPAND_AMOUNT + delta_i][col_start * EXPAND_AMOUNT + 0] = ' ';
		else
			map[row_start * EXPAND_AMOUNT + delta_i][col_start * EXPAND_AMOUNT + 0] = fill;
		delta_j = 1;
		while (delta_j < EXPAND_AMOUNT)
		{
			if (fill != '\n' && fill != 'E' && fill != 'P')
				map[row_start * EXPAND_AMOUNT + delta_i][col_start * EXPAND_AMOUNT + delta_j] = fill;
			else if (fill != '\n')
				map[row_start * EXPAND_AMOUNT + delta_i][col_start * EXPAND_AMOUNT + delta_j] = ' ';
			delta_j++;
		}
		delta_i++;
	}
	if (fill == 'E' || fill == 'P')
		map[row_start * EXPAND_AMOUNT + EXPAND_AMOUNT / 2][col_start * EXPAND_AMOUNT + EXPAND_AMOUNT / 2] = fill;
}

void	fill_map(char **map, char *raw_map)
{
	int	i;
	int	at_row;
	int	at_col;

	i = 0;
	at_col = 0;
	at_row = 0;
	while (raw_map[i] != '\0')
	{
		fill_square(map, at_col, at_row, raw_map[i]);
		if (raw_map[i] == '\n')
		{
			at_row = at_row + 1;
			at_col = 0;
		}
		else
			at_col++;
		i++;
	}
}

char	**expand_map(char *raw_map)
{
	int		i;
	int		lines;
	int		line_length;
	char	**result;

	i = 0;
	lines = get_line_count(raw_map);
	result = malloc(sizeof(result) * (lines * EXPAND_AMOUNT + 1));
	while (raw_map[i] != '\0' && raw_map[i] != '\n')
		i++;
	line_length = i;
	i = 0;
	while (i < lines * EXPAND_AMOUNT)
	{
		result[i] = malloc(sizeof(**result) * (line_length * EXPAND_AMOUNT + 1 + 1));
		ft_bzero(result[i], sizeof(**result) * (line_length * EXPAND_AMOUNT + 1 + 1));
		i++;
	}
	result[i] = NULL;
	fill_map(result, raw_map);
	return (result);
}

char	**get_map(char *file_name)
{
	char	*raw_map;
	char	**map;

	raw_map = get_raw_map(file_name);
	map = expand_map(raw_map);
	return (map);
}

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}
