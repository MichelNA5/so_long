/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:38:47 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/07 16:28:04 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	re_render(t_game	*game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
}

void	move_up(t_game	*game)
{
	re_render(game);
}
