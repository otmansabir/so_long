/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:44:25 by osabir            #+#    #+#             */
/*   Updated: 2023/03/31 14:56:15 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error_line_1(t_tools *help)
{
	ft_putstr("ERROR\nfirst line not perfect\n");
	ft_free_all(help->map);
	ft_free_all(help->map_to_valid_path);
	ft_free_all(help->map_to_valid_path2);
	exit(1);
}

static void	error_line_2(t_tools *help)
{
	ft_putstr("ERROR\nlast line not perfect\n");
	ft_free_all(help->map);
	ft_free_all(help->map_to_valid_path);
	ft_free_all(help->map_to_valid_path2);
	exit(1);
}

void	check_first_line_and_last(t_tools *help)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (help->map[0][i])
	{
		if (help->map[0][i] != '1')
			error_line_1(help);
		i++;
	}
	i = 0;
	while (help->map[i])
		i++;
	i--;
	while (help->map[i][j])
	{
		if (help->map[i][j] != '1')
			error_line_2(help);
		j++;
	}
}

void	key_esc(t_tools *help)
{
	ft_putstr("U enter ESC\n");
	ft_free_all(help->map);
	ft_free_all(help->map_to_valid_path);
	ft_free_all(help->map_to_valid_path2);
	mlx_destroy_window(help->mlx, help->mlx_win);
	exit(0);
}

void	loser(t_tools *help)
{
	ft_putstr("U LOSE THE GAME\n");
	ft_free_all(help->map);
	ft_free_all(help->map_to_valid_path);
	ft_free_all(help->map_to_valid_path2);
	mlx_destroy_window(help->mlx, help->mlx_win);
	exit(1);
}
