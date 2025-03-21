/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:00:40 by osabir            #+#    #+#             */
/*   Updated: 2023/03/23 11:02:56 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

#include <stdio.h>
#include <unistd.h>

static size_t	ft_cw(char const *s, char c)
{
	size_t	j;
	size_t	w;

	j = 0;
	w = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
	{
		j++;
		w++;
	}
	while (s[j] != '\0')
	{
		if (s[j] == c && s[j + 1] != c && s[j + 1] != '\0')
			w++;
		j++;
	}
	return (w);
}

static size_t	ft_clen(char const *s, char c, size_t len)
{
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	**ft_free(char	**str, int i)
{
	int	n;

	n = 0;
	while (n <= i)
	{
		free(str[n]);
		n++;
	}
	free(str);
	return (NULL);
}

static char	**ft_splitv2(char **str, char const *s, char c, size_t count)
{
	size_t	len;
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	while (i < count)
	{
		while (s[start] == c)
			start++;
		len = ft_clen(s, c, start);
		str[i] = ft_substr(s, start, (len - start));
		if (str[i] == NULL)
			return (ft_free(str, i));
		start = 0;
		start += len;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_cw(s, c);
	str = malloc(((count + 1) * sizeof(char *)));
	if (!str)
		return (NULL);
	str = ft_splitv2(str, s, c, count);
	return (str);
}
