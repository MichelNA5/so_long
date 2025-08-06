/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:11:34 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/06 14:21:14 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **tab, t_point size, char target, t_point pos)
{
	if (pos.y < 0 || pos.x < 0 || pos.y >= size.y || pos.x >= size.x)
		return ;
	if (tab[pos.y][pos.x] == 'F' || tab[pos.y][pos.x] != target)
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
