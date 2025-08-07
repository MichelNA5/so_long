/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:38:47 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/07 19:15:26 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

void	move_up(t_game *game)
{
	int	y;
	int	x;
	int	w;
	int	h;

	y = game->player_pos.y - 1;
	x = game->player_pos.x;
	if (can_move(game, y, x))
	{
		game->map[game->player_pos.y][x] = '0';
		game->player_pos.y = y;
		game->map[y][x] = 'P';
		game->img.player = mlx_xpm_file_to_image(game->mlx,
				"./images/character/up.xpm", &w, &h);
		draw_map(game);
	}
}

void	move_down(t_game *game)
{
	int	y;
	int	x;
	int	w;
	int	h;

	y = game->player_pos.y + 1;
	x = game->player_pos.x;
	if (can_move(game, y, x))
	{
		game->map[game->player_pos.y][x] = '0';
		game->player_pos.y = y;
		game->map[y][x] = 'P';
		mlx_clear_window(game->mlx, game->win);
		game->img.player = mlx_xpm_file_to_image(game->mlx,
				"./images/character/down.xpm", &w, &h);
		draw_map(game);
	}
}

void	move_left(t_game *game)
{
	int	y;
	int	x;
	int	w;
	int	h;

	y = game->player_pos.y;
	x = game->player_pos.x - 1;
	if (can_move(game, y, x))
	{
		game->map[y][game->player_pos.x] = '0';
		game->player_pos.x = x;
		game->map[y][x] = 'P';
		game->img.player = mlx_xpm_file_to_image(game->mlx,
				"./images/character/left.xpm", &w, &h);
		draw_map(game);
	}
}

void	move_right(t_game *game)
{
	int	y;
	int	x;
	int	w;
	int	h;

	y = game->player_pos.y;
	x = game->player_pos.x + 1;
	if (can_move(game, y, x))
	{
		game->map[y][game->player_pos.x] = '0';
		game->player_pos.x = x;
		game->map[y][x] = 'P';
		game->img.player = mlx_xpm_file_to_image(game->mlx,
				"./images/character/right.xpm", &w, &h);
		draw_map(game);
	}
}
