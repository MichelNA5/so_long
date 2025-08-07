/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:38:47 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/07 23:32:27 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_position(t_game *game, int y, int x, char *img_path)
{
	int	w;
	int	h;

	game->map[game->player_pos.y][game->player_pos.x] = '0';
	game->player_pos.y = y;
	game->player_pos.x = x;
	game->map[y][x] = 'P';
	mlx_destroy_image(game->mlx, game->img.player);
	game->img.player = mlx_xpm_file_to_image(game->mlx, img_path, &w, &h);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	game->moves++;
	printf("Moves: %d\n", game->moves);
	draw_move_count(game);
}

void	move_up(t_game *game)
{
	int	y;
	int	x;

	y = game->player_pos.y - 1;
	x = game->player_pos.x;
	if (is_over(game->map) && game->map[y][x] == 'E')
		close_window(game);
	if (game->map[y][x] != '1' && game->map[y][x] != 'E')
		update_player_position(game, y, x, "./images/character/up.xpm");
}

void	move_down(t_game *game)
{
	int	y;
	int	x;

	y = game->player_pos.y + 1;
	x = game->player_pos.x;
	if (is_over(game->map) && game->map[y][x] == 'E')
		close_window(game);
	if (game->map[y][x] != '1' && game->map[y][x] != 'E')
		update_player_position(game, y, x, "./images/character/down.xpm");
}

void	move_left(t_game *game)
{
	int	y;
	int	x;

	y = game->player_pos.y;
	x = game->player_pos.x - 1;
	if (is_over(game->map) && game->map[y][x] == 'E')
		close_window(game);
	if (game->map[y][x] != '1' && game->map[y][x] != 'E')
		update_player_position(game, y, x, "./images/character/left.xpm");
}

void	move_right(t_game *game)
{
	int	y;
	int	x;

	y = game->player_pos.y;
	x = game->player_pos.x + 1;
	if (is_over(game->map) && game->map[y][x] == 'E')
		close_window(game);
	if (game->map[y][x] != '1' && game->map[y][x] != 'E')
		update_player_position(game, y, x, "./images/character/right.xpm");
}
