/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:47:39 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/07 16:51:02 by mnaouss          ###   ########.fr       */
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

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*player;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_w;
	int		map_h;
	t_point	player_pos;
	t_img	img;
}	t_game;

int		row_len(char **map);
int		col_len(char *str);
int		is_path_valid(char **map, t_point pos);
char	*ft_strdup(const char *s);
t_point	find_player(char **map);

char	**read_map(char *filename);
void	init_images(t_game *game);
void	get_map_dimensions(t_game *game);
int		is_valid_map(char **map);
int		draw_map(t_game *game);

#endif