/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:00:51 by osabir            #+#    #+#             */
/*   Updated: 2023/03/31 15:07:10 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	finder_door_plyer_coin2(t_tools *help, int x, int y)
{
	while (help->map[y][x])
	{
		if (help->map[y][x] == 'P')
		{
			help->plyer++;
			help->plyer_x = x;
			help->plyer_y = y;
		}
		if (help->map[y][x] == 'E')
		{
			help->door_1++;
			help->door_x = x;
			help->door_y = y;
		}
		if (help->map[y][x] == 'C')
			help->coin++;
		x++;
	}
}

void	finder_door_plyer_coin(t_tools *help)
{
	int	x;
	int	y;

	y = 0;
	help->plyer = 0;
	help->door_1 = 0;
	help->coin = 0;
	while (help->map[y])
	{
		x = 0;
		finder_door_plyer_coin2(help, x, y);
		y++;
	}
	if (help->plyer != 1 || help->coin < 1
		|| help->door_1 != 1)
	{
		ft_putstr("ERROR\nsomething not righit !!\n");
		ft_putstr("check plyer\nor\ndoor\nor\ncoin\n");
		ft__error(help);
		exit(1);
	}
}

static void	func_win(t_tools *help)
{
	ft_putstr("U WIN\n");
	ft_free_all(help->map);
	ft_free_all(help->map_to_valid_path);
	ft_free_all(help->map_to_valid_path2);
	mlx_destroy_window(help->mlx, help->mlx_win);
	exit(0);
}

static void	still_move(t_tools *help, int x, int y, int i)
{
	static int	moves;

	ft_putnbr(++moves);
	ft_putstr("\n");
	mlx_put_image_to_window(help->mlx, help->mlx_win, help->wall, 32, 0);
	mlx_put_image_to_window(help->mlx, help->mlx_win, help->wall, 64, 0);
	mlx_put_image_to_window(help->mlx, help->mlx_win, help->wall, 96, 0);
	if (i == 1)
		hero_down(help, x, y);
	if (i == 4)
		hero_up(help, x, y);
	if (i == 3)
		hero_left(help, x, y);
	if (i == 2)
		hero_raghit(help, x, y);
	help->plyer_x = x;
	help->plyer_y = y;
}

void	move_the_hero(int x, int y, int i, t_tools *help)
{
	if (x == help->door_x && y == help->door_y && help->coin == 0)
		func_win(help);
	else
		still_move(help, x, y, i);
}
