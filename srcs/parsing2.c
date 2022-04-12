/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:48:02 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/03 14:04:09 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map, t_parse *parsing)
{
	int	x;
	int	i;

	x = ft_strlen(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		if ((int)ft_strlen(map[i]) != x)
			return (0);
		i++;
	}
	parsing->y = i;
	return (1);
}

int	is_closed(char **map, t_parse *parsing)
{
	int	i;

	i = 0;
	while (i < parsing->x)
	{
		if (map[0][i] != '1' || map[parsing->y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < parsing->y)
	{
		if (map[i][0] != '1' || map[i][parsing->x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_no_other(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!char_is_valid(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_ber(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (ft_strncmp(path + len - 4, ".ber", 4) != 0)
		return (0);
	else
		return (1);
}

int	is_there_char(char **map, char c)
{
	char	*p;
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (map[i] != NULL)
	{
		p = ft_strchr(map[i], c);
		if (p != NULL)
			result = 1;
		i++;
	}
	return (result);
}
