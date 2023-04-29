/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus_8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:42:52 by osabir            #+#    #+#             */
/*   Updated: 2023/03/31 14:53:16 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_enemy(t_tools *help)
{
	static int	i;

	if (i == 1500)
	{
		send_enemy((rand() % 4), help);
		i = 0;
	}
	else
		i++;
	return (0);
}

void	send_enemy(int i, t_tools *help)
{
	if (i == 1)
		move_enemy_part_2((rand() % 4), help);
}

void	found_enemy(t_tools *help)
{
	int	x;
	int	y;

	y = 0;
	while (help->map[y] != NULL)
	{
		x = 0;
		while (help->map[y][x])
		{
			if (help->map[y][x] == 'M')
			{
				help->enemy2_x = x;
				help->enemy2_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	check_map_end_wth_ber(char *file_num)
{
	char	*check;

	check = check_maps_nume(file_num, ".ber");
	if (!check)
	{
		ft_putstr("ERROR\nnot correct file\n");
		exit(1);
	}	
}
