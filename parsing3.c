/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:03:38 by amuhleth          #+#    #+#             */
/*   Updated: 2022/03/09 14:27:01 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**lst_to_split(t_list *lines)
{
	char	**map;
	int		size;
	int		i;

	size = ft_lstsize(lines);
	map = ft_calloc(size + 1, sizeof(char *));
	i = 0;
	while (lines)
	{
		map[i] = ft_strdup(lines->content);
		lines = lines->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
