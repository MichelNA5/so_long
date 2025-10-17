/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:11:34 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/11 18:52:17 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_exit_reachable(char **map, t_point size)
{
	int	y;
	int	x;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (map[y][x] == 'E')
			{
				if ((y > 0 && map[y - 1][x] == 'F') ||
					(y < size.y - 1 && map[y + 1][x] == 'F') ||
					(x > 0 && map[y][x - 1] == 'F') ||
					(x < size.x - 1 && map[y][x + 1] == 'F'))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	fill(char **tab, t_point size, char target, t_point pos)
{
	if (pos.y < 0 || pos.x < 0 || pos.y >= size.y || pos.x >= size.x)
		return ;
	if (tab[pos.y][pos.x] == 'F' || tab[pos.y][pos.x] == '1'
		|| tab[pos.y][pos.x] == 'E')
		return ;
	tab[pos.y][pos.x] = 'F';
	fill(tab, size, target, (t_point){pos.x, pos.y - 1});
	fill(tab, size, target, (t_point){pos.x, pos.y + 1});
	fill(tab, size, target, (t_point){pos.x - 1, pos.y});
	fill(tab, size, target, (t_point){pos.x + 1, pos.y});
}

static void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	fill(tab, size, target, begin);
}

static int	check_map_valid(char **mapcpy)
{
	int		i;
	int		j;
	t_point	size;

	size.y = row_len(mapcpy);
	size.x = col_len(mapcpy[0]);
	i = 0;
	while (mapcpy[i])
	{
		j = 0;
		while (mapcpy[i][j])
		{
			if (mapcpy[i][j] == 'C' || mapcpy[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	if (!is_exit_reachable(mapcpy, size))
		return (0);
	return (1);
}

int	is_path_valid(char **map, t_point pos)
{
	char	**mapcpy;
	int		is_valid;
	int		i;

	mapcpy = deep_copy_map(map);
	if (!mapcpy)
		return (0);
	flood_fill(mapcpy, (t_point){col_len(mapcpy[0]), row_len(mapcpy)}, pos);
	is_valid = check_map_valid(mapcpy);
	i = 0;
	while (mapcpy[i])
	{
		free(mapcpy[i]);
		i++;
	}
	free(mapcpy);
	return (is_valid);
}
