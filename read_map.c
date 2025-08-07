/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:23:11 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/07 23:21:13 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map, char *line, int count)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (count + 2));
	i = 0;
	while (i < count)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[count] = line;
	new_map[count + 1] = NULL;
	free(map);
	return (new_map);
}

char	**read_map(char *filename)
{
	int		fd;
	int		count;
	char	*line;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map");
		return (NULL);
	}
	map = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		map = copy_map(map, line, count);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	if (map)
		map[count] = NULL;
	return (map);
}
