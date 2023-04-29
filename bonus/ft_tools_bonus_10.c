/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus_10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:43:15 by osabir            #+#    #+#             */
/*   Updated: 2023/03/31 15:17:27 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_valid_path_part_v3(t_tools *help, int y, int x)
{
	int	x2;
	int	y2;

	x2 = x;
	y2 = y;
	if (help->map_to_valid_path2[y][x + 1] != '1'
		&& help->map_to_valid_path2[y][x + 1] != 'M'
		&& help->map_to_valid_path2[y][x + 1] != 'M')
	{
		help->map_to_valid_path2[y][x + 1] = '1';
		x = (x + 1);
		check_valid_path_part_v1(help, y, x);
		check_valid_path_part_v1(help, y2, x2);
	}
	if (help->map_to_valid_path2[y][x - 1] != '1'
		&& help->map_to_valid_path2[y][x - 1] != 'M'
		&& help->map_to_valid_path2[y][x - 1] != 'E')
	{
		help->map_to_valid_path2[y][x - 1] = '1';
		x = (x - 1);
		check_valid_path_part_v1(help, y, x);
		check_valid_path_part_v1(help, y2, x2);
	}
}

void	check_valid_path_part_v2(char **map2, t_tools *help)
{
	int	y;
	int	x;

	y = 0;
	while (map2[y] != NULL)
	{
		x = 0;
		while (map2[y][x] != '\0')
		{
			if (map2[y][x] != '1' && help->map[y][x] == 'C')
				map_not_valid();
			x++;
		}
		y++;
	}
}

void	check_valid_path_part_v1(t_tools *help, int y, int x)
{
	int	x2;
	int	y2;

	x2 = x;
	y2 = y;
	if (help->map_to_valid_path2[y - 1][x] != '1'
		&& help->map_to_valid_path2[y - 1][x] != 'M'
		&& help->map_to_valid_path2[y - 1][x] != 'E')
	{
		help->map_to_valid_path2[y - 1][x] = '1';
		y = (y - 1);
		check_valid_path_part_v1(help, y, x);
		check_valid_path_part_v1(help, y2, x2);
	}
	if (help->map_to_valid_path2[y + 1][x] != '1'
		&& help->map_to_valid_path2[y + 1][x] != 'M'
		&& help->map_to_valid_path2[y + 1][x] != 'E')
	{
		help->map_to_valid_path2[y + 1][x] = '1';
		y = (y + 1);
		check_valid_path_part_v1(help, y, x);
		check_valid_path_part_v1(help, y2, x2);
	}
	else
		check_valid_path_part_v3(help, y, x);
}

void	ft___error(t_tools *help)
{
	ft_free_all(help->map);
	ft_free_all(help->map_to_valid_path);
	ft_free_all(help->map_to_valid_path2);
}
