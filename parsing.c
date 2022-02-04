/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:47:09 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/04 18:03:11 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file(char *path)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(42);
	map = ft_calloc(200, sizeof(char *));
	if (!map)
		exit(41);
	i = 0;
	map[i] = ft_strtrim(get_next_line(fd), "\n");
	while (map[i] != NULL && i < 200)
	{
		i++;
		map[i] = ft_strtrim(get_next_line(fd), "\n");
	}
	close(fd);
	return (map);
}

int	char_is_valid(char c)
{
	return (c == '1' || c == '0'
		|| c == 'C' || c == 'E' || c == 'P');
}

void	init_parser(char **map, t_parse *parsing)
{
	if (!map[0])
	{
		ft_printf("Invalid path\n");
		exit(12);
	}
	parsing->x = ft_strlen(map[0]);
	parsing->rectangle = is_rectangle(map, parsing);
	parsing->closed = is_closed(map, parsing);
	parsing->exit = is_there_char(map, 'E');
	parsing->collect = is_there_char(map, 'C');
	parsing->position = is_there_char(map, 'P');
	parsing->no_other = check_no_other(map);
}

int	check_valid_map(t_parse *p)
{
	return (p->rectangle && p->closed && p->exit
		&& p->collect && p->position
		&& p->no_other && p->ber_format);
}

void	parser(char *path, t_game *a)
{
	a->map = read_file(path);
	a->parsing = ft_calloc(1, sizeof(t_parse));
	if (!a->parsing)
		exit(12);
	a->parsing->ber_format = check_ber(path);
	init_parser(a->map, a->parsing);
	if (!check_valid_map(a->parsing))
	{
		free_map(a);
		a->map = NULL;
	}
}
