/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:11:34 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/07 09:42:01 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **tab, t_point size, char target, t_point pos)
{
	if (pos.y < 0 || pos.x < 0 || pos.y >= size.y || pos.x >= size.x)
		return ;
	if (tab[pos.y][pos.x] == 'F' || tab[pos.y][pos.x] == '1')
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

static char	**deep_copy_map(char **map)
{
	int		i;
	char	**mapcpy;

	mapcpy = malloc(sizeof(char *) * (row_len(map) + 1));
	if (!mapcpy)
		return (NULL);
	i = 0;
	while (i < row_len(map))
	{
		mapcpy[i] = ft_strdup(map[i]);
		if (!mapcpy[i])
		{
			while (--i >= 0)
				free(mapcpy[i]);
			free(mapcpy);
			return (NULL);
		}
		i++;
	}
	mapcpy[i] = NULL;
	return (mapcpy);
}

static int	check_map_valid(char **mapcpy)
{
	int	i;
	int	j;

	i = 0;
	while (mapcpy[i])
	{
		j = 0;
		while (mapcpy[i][j])
		{
			if (mapcpy[i][j] == 'C' || mapcpy[i][j] == 'E' ||
				mapcpy[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
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
