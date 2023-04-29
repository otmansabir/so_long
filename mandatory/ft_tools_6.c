/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:11:06 by osabir            #+#    #+#             */
/*   Updated: 2023/03/23 11:15:56 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	func_move_hero1(t_tools *help)
{
	move_the_hero((help->plyer_x - 1), help->plyer_y, 2, help);
}

static void	func_move_hero2(t_tools *help)
{
	move_the_hero((help->plyer_x + 1), help->plyer_y, 3, help);
}

static void	func_move_hero3(t_tools *help)
{
	move_the_hero(help->plyer_x, (help->plyer_y - 1), 4, help);
}

static void	func_move_hero4(t_tools *help)
{
	move_the_hero(help->plyer_x, (help->plyer_y + 1), 1, help);
}

void	func_move_hero_part2(int key, t_tools *help)
{
	if ((key == 123 || key == 0)
		&& help->map[help->plyer_y][help->plyer_x - 1] != '1')
		func_move_hero1(help);
	if ((key == 124 || key == 2)
		&& help->map[help->plyer_y][help->plyer_x + 1] != '1')
		func_move_hero2(help);
	if ((key == 126 || key == 13)
		&& help->map[help->plyer_y - 1][help->plyer_x] != '1')
		func_move_hero3(help);
	if ((key == 125 || key == 1)
		&& help->map[help->plyer_y + 1][help->plyer_x] != '1')
		func_move_hero4(help);
	if (key == 53)
		key_esc(help);
}
