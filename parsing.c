/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:47:09 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/01 19:25:33 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file(char *path)
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

int	is_rectangle(char **map)
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

int	find_map_y(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
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

int	char_is_valid(char c)
{
	return (c == '1' || c == '0'
		|| c == 'C' || c == 'E' || c == 'P');
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

char	**init_parser(char **map, t_parse *parsing)
{
	parsing->x = ft_strlen(map[0]);
	parsing->y = find_map_y(map);
	parsing->rectangle = is_rectangle(map);
	parsing->closed = is_closed(map, parsing);
	parsing->exit = is_there_char(map, 'E');
	parsing->collect = is_there_char(map, 'C');
	parsing->position = is_there_char(map, 'P');
	parsing->no_other = check_no_other(map);
	return (map);
}

void	print_parsing(t_parse *parsing)
{
	ft_printf("X : %d\n", parsing->x);
	ft_printf("Y : %d\n", parsing->y);
	ft_printf("Rectangle : %d\n", parsing->rectangle);
	ft_printf("Closed : %d\n", parsing->closed);
	ft_printf("Exit : %d\n", parsing->exit);
	ft_printf("Collect : %d\n", parsing->collect);
	ft_printf("Position : %d\n", parsing->position);
	ft_printf("No other : %d\n", parsing->no_other);
	ft_printf("Ber format : %d\n", parsing->ber_format);
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

int	check_valid_map(t_parse *p)
{
	return (p->rectangle && p->closed && p->exit
		&& p->collect && p->position
		&& p->no_other && p->ber_format);
}

char	**parser(char *path, t_game *a)
{
	char	**map;

	map = read_file(path);
	a->parsing = ft_calloc(1, sizeof(t_parse));
	if (!a->parsing)
		return (NULL);
	a->parsing->ber_format = check_ber(path);
	map = init_parser(map, a->parsing);
	print_parsing(a->parsing);
	if (!check_valid_map(a->parsing))
	{
		free(map);
		// to do free correctement
		// to do display error
		map = NULL;
	}
	return (map);
}

/*int	main(int argc, char **argv)
{
	t_game	a;

	(void) argc;
	a.map = parser(argv[1]);
	if (a.map == NULL)
		ft_printf("Invalid map.\n");
	else
		print_map(a.map);
	return (0);
}*/
