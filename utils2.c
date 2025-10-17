/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:50:00 by mnaouss           #+#    #+#             */
/*   Updated: 2025/08/12 20:24:43 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

static char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		len;

	num = n;
	len = (n <= 0);
	while (n && ++len)
		n /= 10;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

void	draw_move_count(t_game *game)
{
	char	*num_str;
	char	*full_str;

	num_str = ft_itoa(game->moves);
	if (!num_str)
		return ;
	full_str = ft_strjoin("Moves: ", num_str);
	free(num_str);
	if (!full_str)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, full_str);
	free(full_str);
}
