/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:23:11 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/11 22:03:06 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_ber_extension(char *filename)
{
	int	len;
	int	last_slash;

	len = ft_strlen(filename);
	if (len <= 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (0);
	last_slash = len - 5;
	while (last_slash >= 0 && filename[last_slash] != '/')
		last_slash--;
	if (last_slash == len - 5)
		return (0);
	return (1);
}

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

	if (!has_ber_extension(filename))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening map"), NULL);
	map = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		map = copy_map(map, line, count++);
		line = get_next_line(fd);
	}
	close(fd);
	if (map)
		map[count] = NULL;
	return (map);
}
