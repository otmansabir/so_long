/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:04:00 by osabir            #+#    #+#             */
/*   Updated: 2023/03/24 11:33:05 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hero_up(t_tools *help, int x, int y)
{
	mlx_put_image_to_window(help->mlx, help->mlx_win, help->space,
		(help->plyer_x * 64), (help->plyer_y * 64));
	mlx_put_image_to_window(help->mlx, help->mlx_win,
		help->space, (x * 64), (y * 64));
	mlx_put_image_to_window(help->mlx, help->mlx_win,
		help->hero4, (x * 64), (y * 64));
}

void	hero_down(t_tools *help, int x, int y)
{
	mlx_put_image_to_window(help->mlx, help->mlx_win, help->space,
		(help->plyer_x * 64), (help->plyer_y * 64));
	mlx_put_image_to_window(help->mlx, help->mlx_win,
		help->space, (x * 64), (y * 64));
	mlx_put_image_to_window(help->mlx, help->mlx_win,
		help->hero1, (x * 64), (y * 64));
}

void	hero_left(t_tools *help, int x, int y)
{
	mlx_put_image_to_window(help->mlx, help->mlx_win, help->space,
		(help->plyer_x * 64), (help->plyer_y * 64));
	mlx_put_image_to_window(help->mlx, help->mlx_win,
		help->space, (x * 64), (y * 64));
	mlx_put_image_to_window(help->mlx, help->mlx_win,
		help->hero3, (x * 64), (y * 64));
}

void	hero_raghit(t_tools *help, int x, int y)
{
	mlx_put_image_to_window(help->mlx, help->mlx_win, help->space,
		(help->plyer_x * 64), (help->plyer_y * 64));
	mlx_put_image_to_window(help->mlx, help->mlx_win,
		help->space, (x * 64), (y * 64));
	mlx_put_image_to_window(help->mlx, help->mlx_win,
		help->hero2, (x * 64), (y * 64));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
