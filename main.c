/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:01:51 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/07 23:08:26 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == 119)
		move_up(game);
	else if (keycode == 115)
		move_down(game);
	else if (keycode == 97)
		move_left(game);
	else if (keycode == 100)
		move_right(game);
	return (0);
}

void	draw_move_count(t_game *game)
{
	char	str[32];

	sprintf(str, "Moves: %d", game->moves);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, str);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (!game.map || !is_valid_map(game.map))
			return (1);
		game.player_pos = find_player(game.map);
		game.moves = 0;
		get_map_dimensions(&game);
		game.mlx = mlx_init();
		if (!game.mlx)
			return (1);
		game.win = mlx_new_window(game.mlx, game.map_w * 64, game.map_h * 64,
				"so_long");
		if (!game.win)
			return (1);
		init_images(&game);
		draw_map(&game);
		draw_move_count(&game);
		mlx_key_hook(game.win, handle_key, &game);
		mlx_hook(game.win, 17, 0, close_window, &game);
		mlx_loop(game.mlx);
		return (0);
	}
}
