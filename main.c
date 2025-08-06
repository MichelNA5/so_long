/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:03:30 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/06 12:05:07 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 640, 480, "so_long");
	img = mlx_xpm_file_to_image(mlx,
			"./images/character/left.xpm", &img_width, &img_height);
	if (!img)
		return (1);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, handle_key, NULL);
	mlx_loop(mlx);
	return (0);
}
