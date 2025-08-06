/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:47:39 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/06 23:09:18 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int	row_len(char **map);
int	col_len(char *str);

#endif