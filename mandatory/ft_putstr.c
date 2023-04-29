/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:46:20 by osabir            #+#    #+#             */
/*   Updated: 2023/03/31 15:06:05 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	return (i);
}

void	ft__error(t_tools *help)
{
	ft_free_all(help->map);
	ft_free_all(help->map_to_valid_path);
	ft_free_all(help->map_to_valid_path2);
}
