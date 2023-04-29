/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:43:38 by osabir            #+#    #+#             */
/*   Updated: 2023/03/24 11:11:16 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_not_valid(void)
{
	ft_putstr("ERROR\nmap not valid !!\n");
	exit(1);
}

void	check_valid_path_part_2(char **map2, t_tools *help)
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
			if (map2[y][x] != '1' && help->map[y][x] == 'E')
				map_not_valid();
			x++;
		}
		y++;
	}
}

void	check_double_new_line(t_tools *help)
{
	int	i;
	int	j;

	i = 0;
	if (help->map_befor_split[i] == '\n')
	{
		ft_putstr("ERROE\nextra new line\n");
		exit(1);
	}
	j = ft_strlen(help->map_befor_split);
	while (help->map_befor_split[i])
	{
		if (help->map_befor_split[i] == '\n'
			&& help->map_befor_split[i + 1] == '\n')
		{
			ft_putstr("ERROE\nextra new line\n");
			exit(1);
		}
		i++;
	}
	if (help->map_befor_split[j - 1] == '\n')
	{
		ft_putstr("ERROE\nextra new line\n");
		exit(1);
	}
}

void	check_valid_path_part_3(t_tools *help, int y, int x)
{
	int	x2;
	int	y2;

	x2 = x;
	y2 = y;
	if (help->map_to_valid_path[y][x + 1] != '1'
		&& help->map_to_valid_path[y][x + 1] != 'M')
	{
		help->map_to_valid_path[y][x + 1] = '1';
		x = (x + 1);
		check_valid_path_part_1(help, y, x);
		check_valid_path_part_1(help, y2, x2);
	}
	if (help->map_to_valid_path[y][x - 1] != '1'
		&& help->map_to_valid_path[y][x - 1] != 'M')
	{
		help->map_to_valid_path[y][x - 1] = '1';
		x = (x - 1);
		check_valid_path_part_1(help, y, x);
		check_valid_path_part_1(help, y2, x2);
	}
}

void	check_valid_path_part_1(t_tools *help, int y, int x)
{
	int	x2;
	int	y2;

	x2 = x;
	y2 = y;
	if (help->map_to_valid_path[y - 1][x] != '1'
		&& help->map_to_valid_path[y - 1][x] != 'M')
	{
		help->map_to_valid_path[y - 1][x] = '1';
		y = (y - 1);
		check_valid_path_part_1(help, y, x);
		check_valid_path_part_1(help, y2, x2);
	}
	if (help->map_to_valid_path[y + 1][x] != '1'
		&& help->map_to_valid_path[y + 1][x] != 'M')
	{
		help->map_to_valid_path[y + 1][x] = '1';
		y = (y + 1);
		check_valid_path_part_1(help, y, x);
		check_valid_path_part_1(help, y2, x2);
	}
	else
		check_valid_path_part_3(help, y, x);
}
