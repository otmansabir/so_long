/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:41:54 by osabir            #+#    #+#             */
/*   Updated: 2023/03/24 14:45:16 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_next_line_work(char *file_num, t_tools *help)
{
	int		fd;
	char	*tmp;
	char	*long_str;

	fd = open(file_num, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ERROR\nnot correct name !! \n");
		exit(1);
	}
	long_str = ft_calloc(1, 1);
	help->check_null_and_line_y = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp && help->check_null_and_line_y == 0)
			errror(tmp, long_str);
		if (!tmp)
			break ;
		long_str = ft_strjoin(long_str, tmp);
		free(tmp);
		help->check_null_and_line_y++;
	}
	help->line_y = help->check_null_and_line_y;
	return (free(tmp), long_str);
}

void	errror(char *tmp, char *long_str)
{
	free(tmp);
	free(long_str);
	ft_putstr("ERROR\nthe file is empty\n");
	exit(1);
}

void	if_image_not_there(t_tools *help)
{
	mlx_destroy_window(help->mlx, help->mlx_win);
	ft_free_all(help->map);
	ft_free_all(help->map_to_valid_path);
	exit(1);
}

static void	get_the_image_xpm1(t_tools *help)
{
	help->space = mlx_xpm_file_to_image(help->mlx, "./bonus/TOTO/space.xpm",
			&help->width, &help->height);
	if (!help->space)
		if_image_not_there(help);
	help->door1 = mlx_xpm_file_to_image(help->mlx \
		, "./bonus/TOTO//door1.xpm", &help->width, &help->height);
	if (!help->door1)
		if_image_not_there(help);
	help->door2 = mlx_xpm_file_to_image(help->mlx, "./bonus/TOTO/door2.xpm" \
			, &help->width, &help->height);
	if (!help->door2)
		if_image_not_there(help);
	help->coins = mlx_xpm_file_to_image(help->mlx, "./bonus/TOTO/coin.xpm",
			&help->width, &help->height);
	if (!help->coins)
		if_image_not_there(help);
	help->enemy = mlx_xpm_file_to_image(help->mlx, "./bonus/TOTO/enemy.xpm",
			&help->width, &help->height);
	if (!help->enemy)
		if_image_not_there(help);
}

void	get_the_image_xpm(t_tools *help)
{
	help->hero1 = mlx_xpm_file_to_image(help->mlx \
		, "./bonus/TOTO/raghit.xpm", &help->width, &help->height);
	if (!help->hero1)
		if_image_not_there(help);
	help->hero2 = mlx_xpm_file_to_image(help->mlx, "./bonus/TOTO/left.xpm" \
		, &help->width, &help->height);
	if (!help->hero2)
		if_image_not_there(help);
	help->hero3 = mlx_xpm_file_to_image(help->mlx, "./bonus/TOTO/up.xpm" \
		, &help->width, &help->height);
	if (!help->hero3)
		if_image_not_there(help);
	help->hero4 = mlx_xpm_file_to_image(help->mlx, "./bonus/TOTO/down.xpm" \
		, &help->width, &help->height);
	if (!help->hero4)
		if_image_not_there(help);
	help->wall = mlx_xpm_file_to_image(help->mlx, "./bonus/TOTO/wall.xpm",
			&help->width, &help->height);
	if (!help->wall)
		if_image_not_there(help);
	get_the_image_xpm1(help);
}
