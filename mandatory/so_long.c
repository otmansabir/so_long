/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:43:59 by osabir            #+#    #+#             */
/*   Updated: 2023/03/24 13:25:27 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line_x_and_y(t_tools *help)
{
	if (help->line_x == help->line_y)
	{
		ft_putstr("ERROR\nline x = line y\n");
		exit(1);
	}
}

static int	exit1(int key, t_tools *help)
{
	(void)key;
	(void)help;
	ft_putstr("Clicked on the cross\n");
	exit(0);
}

void	check_everthing(char *s, t_tools *help)
{
	check_map_end_wth_ber(s);
	help->map_befor_split = get_next_line_work(s, help);
	check_double_new_line(help);
	help->map = ft_split(help->map_befor_split, '\n');
	help->map_to_valid_path = ft_split(help->map_befor_split, '\n');
	help->map_to_valid_path2 = ft_split(help->map_befor_split, '\n');
	free(help->map_befor_split);
	count_line_of_map(help);
	check_first_line_and_last(help);
	looking_for_one_part1(help);
	finder_door_plyer_coin(help);
	help->plyer_x2 = help->plyer_x;
	help->plyer_y2 = help->plyer_y;
	check_valid_path_part_v1(help, help->plyer_y2, help->plyer_x2);
	check_valid_path_part_v2(help->map_to_valid_path2, help);
	check_valid_path_part_1(help, help->plyer_y2, help->plyer_x2);
	check_valid_path_part_2(help->map_to_valid_path, help);
	help->line_x = ft_strlen(help->map[0]);
}

int	main(int ac, char **av)
{
	t_tools	help;

	if (ac == 2)
	{
		check_everthing(av[1], &help);
		help.mlx = mlx_init();
		help.mlx_win = mlx_new_window(help.mlx, (help.line_x * 64) \
			, (help.line_y * 64), "so_long");
		draw_the_window(&help);
		mlx_hook(help.mlx_win, 17, 0, &exit1, &help);
		mlx_hook(help.mlx_win, 2, 0, &key_hook1, &help);
		mlx_loop(help.mlx);
	}
}
