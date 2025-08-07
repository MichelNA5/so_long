/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:01:51 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/07 16:51:23 by mnaouss          ###   ########.fr       */
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
	return (0);
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
		mlx_key_hook(game.win, handle_key, &game);
		mlx_loop(game.mlx);
		return (0);
	}
}
