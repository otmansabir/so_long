/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus_9.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:43:02 by osabir            #+#    #+#             */
/*   Updated: 2023/03/23 10:53:36 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_enemy_part4(t_tools *help)
{
	help->map[help->enemy2_y][help->enemy2_x] = '0';
	help->map[help->enemy2_y - 1][help->enemy2_x] = 'M';
	mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->space, (help->enemy2_x * 64), (help->enemy2_y * 64));
	help->enemy2_y--;
	if (help->enemy2_y == help->plyer_y && help->enemy2_x == help->plyer_x)
		loser(help);
	mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->enemy, (help->enemy2_x * 64), (help->enemy2_y * 64));
}

static void	move_enemy_part3(t_tools *help)
{
	help->map[help->enemy2_y][help->enemy2_x] = '0';
	help->map[help->enemy2_y][help->enemy2_x - 1] = 'M';
	mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->space, (help->enemy2_x * 64), (help->enemy2_y * 64));
	help->enemy2_x--;
	if (help->enemy2_y == help->plyer_y && help->enemy2_x == help->plyer_x)
		loser(help);
	mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->enemy, (help->enemy2_x * 64), (help->enemy2_y * 64));
}

static void	move_enemy_part2(t_tools *help)
{
	help->map[help->enemy2_y][help->enemy2_x] = '0';
	help->map[help->enemy2_y + 1][help->enemy2_x] = 'M';
	mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->space, (help->enemy2_x * 64), (help->enemy2_y * 64));
	help->enemy2_y++;
	if (help->enemy2_y == help->plyer_y && help->enemy2_x == help->plyer_x)
		loser(help);
	mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->enemy, (help->enemy2_x * 64), (help->enemy2_y * 64));
}

static void	move_enemy_part1(t_tools *help)
{
	help->map[help->enemy2_y][help->enemy2_x] = '0';
	help->map[help->enemy2_y][help->enemy2_x + 1] = 'M';
	mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->space, (help->enemy2_x * 64), (help->enemy2_y * 64));
	help->enemy2_x++;
	if (help->enemy2_y == help->plyer_y && help->enemy2_x == help->plyer_x)
		loser(help);
	mlx_put_image_to_window(help->mlx, help->mlx_win \
		, help->enemy, (help->enemy2_x * 64), (help->enemy2_y * 64));
}

void	move_enemy_part_2(int i, t_tools *help)
{
	if (help->map[help->enemy2_y][help->enemy2_x + 1] != '1'
		&& help->map[help->enemy2_y][help->enemy2_x + 1] != 'C'
		&& help->map[help->enemy2_y][help->enemy2_x + 1] != 'E'
		&& help->map[help->enemy2_y][help->enemy2_x + 1] != 'M'
		&& i == 0)
		move_enemy_part1(help);
	else if (help->map[help->enemy2_y + 1][help->enemy2_x] != '1'
		&& help->map[help->enemy2_y + 1][help->enemy2_x] != 'C'
		&& help->map[help->enemy2_y + 1][help->enemy2_x] != 'E'
		&& help->map[help->enemy2_y + 1][help->enemy2_x] != 'M'
		&& i == 1)
		move_enemy_part2(help);
	else if (help->map[help->enemy2_y][help->enemy2_x - 1] != '1'
		&& help->map[help->enemy2_y][help->enemy2_x - 1] != 'C'
		&& help->map[help->enemy2_y][help->enemy2_x - 1] != 'E'
		&& help->map[help->enemy2_y][help->enemy2_x - 1] != 'M'
		&& i == 2)
		move_enemy_part3(help);
	else if (help->map[help->enemy2_y - 1][help->enemy2_x] != '1'
		&& help->map[help->enemy2_y - 1][help->enemy2_x] != 'C'
		&& help->map[help->enemy2_y - 1][help->enemy2_x] != 'E'
		&& help->map[help->enemy2_y - 1][help->enemy2_x] != 'M'
		&& i == 3)
		move_enemy_part4(help);
}
