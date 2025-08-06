/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:03:17 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/06 13:32:05 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(char **map)
{
	int	i;
	int	len;

	len = col_len(map[0]);
	i = 1;
	while (map[i])
	{
		if (col_len(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int	has_required_elements(char **map)
{
	int	i;
	int	j;
	int	player;
	int	col;
	int	exit;

	i = -1;
	player = 0;
	col = 0;
	exit = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				player = 1;
			else if (map[i][j] == 'E')
				exit = 1;
			else if (map[i][j] == 'C')
				col = 1;
		}
	}
	return (player && col && exit);
}

static int	has_border_wall(char **map)
{
	int	i;
	int	width;
	int	height;

	height = row_len(map);
	width = col_len(map[0]);
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_map(char **map)
{
	if (!is_rectangular(map))
		return (0);
	if (!is_border_wall(map))
		return (0);
	if (!has_required_elements(map))
		return (0);
	if (!is_path_valid(map))
	{
		printf("Path to collectibles or exit is blocked\n");
		return (0);
	}
	return (1);
}
