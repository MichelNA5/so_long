/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:03:17 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/11 19:32:03 by mnaouss          ###   ########.fr       */
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
	int	counts[3];

	i = -1;
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				counts[0]++;
			else if (map[i][j] == 'E')
				counts[1]++;
			else if (map[i][j] == 'C')
				counts[2] = 1;
			else if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != '\n')
				return (0);
		}
	}
	return (counts[0] == 1 && counts[2] && counts[1] == 1);
}

static int	is_border_wall(char **map)
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

t_point	find_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return ((t_point){j, i});
			j++;
		}
		i++;
	}
	return ((t_point){-1, -1});
}

int	is_valid_map(char **map)
{
	t_point	player_pos;

	if (!is_rectangular(map))
		return (0);
	if (!is_border_wall(map))
		return (0);
	if (!has_required_elements(map))
		return (0);
	player_pos = find_player(map);
	if (player_pos.x == -1 || player_pos.y == -1)
		return (0);
	if (!is_path_valid(map, player_pos))
	{
		return (0);
	}
	return (1);
}
