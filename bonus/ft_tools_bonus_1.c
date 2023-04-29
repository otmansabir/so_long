/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:41:03 by osabir            #+#    #+#             */
/*   Updated: 2023/03/31 14:54:59 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	looking_for_one_part1(t_tools *help)
{
	int	i;

	i = 0;
	while (help->map[i] != NULL)
	{
		if (looking_for_one_part2(help->map[i]) == 0)
		{
			ft_putstr("ERROE\nnot perfect map\n");
			ft_free_all(help->map);
			ft_free_all(help->map_to_valid_path);
			exit(1);
		}
		i++;
	}
}

int	looking_for_one_part2(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[0] == '1' && s[i] == '1')
		return (1);
	return (0);
}

void	count_line_of_map(t_tools *help)
{
	size_t	first_line;
	int		i;

	first_line = ft_strlen(help->map[0]);
	i = 0;
	while (help->map[i])
	{
		if (first_line != ft_strlen(help->map[i]))
		{
			ft_putstr("ERROR\nline of map not perfect\n");
			ft_free_all(help->map);
			ft_free_all(help->map_to_valid_path);
			exit(1);
		}
		i++;
	}
}

void	ft_free_all(char **str)
{
	int	n;

	n = 0;
	while (str[n] != NULL)
	{
		free(str[n]);
		n++;
	}
	free(str);
}

char	*check_maps_nume(char *file_num, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (file_num[i])
	{
		j = 0;
		while (file_num[i + j] == s[j])
		{
			if (file_num[i + j] != '\0' && s[j] == '\0')
				return (NULL);
			if (file_num[i + j] == '\0' && s[j] == '\0')
			{
				return (file_num);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
