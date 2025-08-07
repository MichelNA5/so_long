/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:14:35 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/07 16:44:44 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_dimensions(t_game *game)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	if (!game->map || !game->map[0])
	{
		game->map_w = 0;
		game->map_h = 0;
		return ;
	}
	w = col_len(game->map[0]);
	while (game->map[h])
	{
		h++;
	}
	game->map_w = w;
	game->map_h = h;
}

void	init_images(t_game *game)
{
	int	w;
	int	h;

	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./images/wall.xpm", &w, &h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"./images/floor.xpm", &w, &h);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"./images/pokeball.xpm", &w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./images/exit.xpm", &w, &h);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"./images/character/left.xpm", &w, &h);
	if (!game->img.wall || !game->img.floor || !game->img.collectible
		|| !game->img.exit || !game->img.player)
	{
		exit(1);
	}
	game->img.width = w;
	game->img.height = h;
}

/*
** Puts the correct image tile onto the window based on the map character.
*/
static void	put_tile(t_game *game, int y, int x)
{
	char	tile;
	void	*img_to_draw;
	int		w;
	int		h;

	tile = game->map[y][x];
	img_to_draw = NULL;
	if (tile == '1')
		img_to_draw = game->img.wall;
	else if (tile == '0')
		img_to_draw = game->img.floor;
	else if (tile == 'C')
		img_to_draw = game->img.collectible;
	else if (tile == 'E')
		img_to_draw = game->img.exit;
	else if (tile == 'P')
		img_to_draw = game->img.player;
	w = game->img.width;
	h = game->img.height;
	if (img_to_draw)
		mlx_put_image_to_window(game->mlx, game->win,
			img_to_draw, x * w, y * h);
}

/*
** Iterates through the map and calls put_tile for each character
** to render the entire game map.
*/
int	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			put_tile(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
