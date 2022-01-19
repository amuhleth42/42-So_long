/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:47:09 by amuhleth          #+#    #+#             */
/*   Updated: 2022/01/19 18:02:40 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parser(char *path)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	map = ft_calloc(50, sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	map[i] = ft_strtrim(get_next_line(fd), "\n");
	while (map[i] != NULL)
	{
		i++;
		map[i] = ft_strtrim(get_next_line(fd), "\n");
	}
	close(fd);
	return (map);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	a;

	(void) argc;
	a.map = parser(argv[1]);
	if (a.map == NULL)
		ft_printf("Invalid map.\n");
	else
		print_map(a.map);
	return (0);
}
