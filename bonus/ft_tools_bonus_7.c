/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus_7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:42:41 by osabir            #+#    #+#             */
/*   Updated: 2023/04/01 14:49:33 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_the_window_part_3(t_tools *help, int x, int y)
{
	if (help->map[y][x] == 'M')
	{
		mlx_put_image_to_window(help->mlx, help->mlx_win, help->space \
		, (x * 64), (y * 64));
		mlx_put_image_to_window(help->mlx, help->mlx_win, help->enemy \
		, (x * 64), (y * 64));
	}
	else if (help->map[y][x] == 'E')
	{
		mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->space, (x * 64), (y * 64));
		mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->door1, (x * 64), (y * 64));
	}
	else if (help->map[y][x] == '1')
		mlx_put_image_to_window(help->mlx, help->mlx_win \
			, help->wall, (x * 64), (y * 64));
}

static void	draw_the_window_part_2(t_tools *help, int x, int y)
{
	if (help->map[y][x] == 'P')
	{
		mlx_put_image_to_window(help->mlx, help->mlx_win \
			, help->space, (x * 64), (y * 64));
		mlx_put_image_to_window(help->mlx, help->mlx_win \
			, help->hero1, (x * 64), (y * 64));
	}
	else if (help->map[y][x] == 'C')
	{
		mlx_put_image_to_window(help->mlx, help->mlx_win \
			, help->space, (x * 64), (y * 64));
		mlx_put_image_to_window(help->mlx, help->mlx_win \
			, help->coins, (x * 64), (y * 64));
	}
}

static void	draw_the_window_error(t_tools *help)
{
	ft_putstr("ERROE\nnot allowed\n");
	mlx_destroy_window(help->mlx, help->mlx_win);
	exit(1);
}

void	draw_the_window(t_tools *help)
{
	int	x;
	int	y;

	y = 0;
	get_the_image_xpm(help);
	while (help->map[y])
	{
		x = 0;
		while (help->map[y][x] != '\0')
		{
			if (help->map[y][x] == 'C' || help->map[y][x] == 'P')
				draw_the_window_part_2(help, x, y);
			else if (help->map[y][x] == 'M' || help->map[y][x] == 'E'
				|| help->map[y][x] == '1')
				draw_the_window_part_3(help, x, y);
			else if (help->map[y][x] == '0')
				mlx_put_image_to_window(help->mlx, help->mlx_win \
					, help->space, (x * 64), (y * 64));
			else
				draw_the_window_error(help);
			x++;
		}
		y++;
	}
}

int	key_hook(int key, t_tools *help)
{
	if (help->coin > 0)
		func_move_hero_part1(key, help);
	else if (help->coin == 0)
		func_move_hero_part2(key, help);
	return (0);
}
