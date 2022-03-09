/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:47:09 by amuhleth          #+#    #+#             */
/*   Updated: 2022/03/09 14:41:24 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file(char *path)
{
	t_list	*lines;
	char	**map;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		die("open : an error occured when opening file.");
	line = ft_strtrim(get_next_line(fd), "\n");
	if (!line)
		return (NULL);
	lines = NULL;
	while (line)
	{
		ft_lstadd_back(&lines, ft_lstnew(line));
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	close(fd);
	map = lst_to_split(lines);
	ft_lstclear(&lines, &free);
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
		die("parsing allocation failed");
	a->parsing->ber_format = check_ber(path);
	init_parser(a->map, a->parsing);
	if (!check_valid_map(a->parsing))
	{
		free_map(a);
		a->map = NULL;
	}
}
