/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:22:04 by amuhleth          #+#    #+#             */
/*   Updated: 2022/04/12 18:43:30 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *a)
{
	int	x;
	int	y;

	x = a->parsing->x * 32;
	y = a->parsing->y * 32;
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, x, y, "So_long");
}

int	count_items(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	init_data(t_game *a)
{
	a->c_count = 0;
	a->c_all = count_items(a->map);
	a->move_count = 0;
	ft_printf("All items : %d\n", a->c_all);
}

void	init_mlx_hook(t_game *a)
{
	mlx_hook(a->win, 2, 0, &key_down, a);
	mlx_key_hook(a->win, &key_hook, a);
	mlx_loop(a->mlx);
}

int	main(int argc, char **argv)
{
	t_game	a;

	if (argc != 2)
	{
		ft_printf("T'es bourre bro/sis!");
		return (0);
	}
	parser(argv[1], &a);
	if (a.map == NULL)
	{
		ft_printf("Invalid map.\n");
		free(a.parsing);
		return (0);
	}
	init_data(&a);
	init_window(&a);
	init_tiles(&a);
	put_tiles(&a, a.map);
	init_mlx_hook(&a);
	return (0);
}
