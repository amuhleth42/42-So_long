/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:22:04 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/03 14:58:27 by amuhleth         ###   ########.fr       */
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

void	init_tile(t_tile *tile, char *file, void *mlx)
{
	tile->w = 32;
	tile->h = 32;
	tile->img = mlx_xpm_file_to_image(mlx, file, &tile->w, &tile->h);
}

void	init_tiles(t_game *a)
{
	a->wall = ft_calloc(1, sizeof(t_tile));
	a->empty = ft_calloc(1, sizeof(t_tile));
	a->player = ft_calloc(1, sizeof(t_tile));
	a->collect = ft_calloc(1, sizeof(t_tile));
	a->exit = ft_calloc(1, sizeof(t_tile));
	init_tile(a->wall, "assets/wallgrass32.xpm", a->mlx);
	init_tile(a->collect, "assets/star_l_32.xpm", a->mlx);
	init_tile(a->empty, "assets/grass32.xpm", a->mlx);
	init_tile(a->player, "assets/flower32.xpm", a->mlx);
	init_tile(a->exit, "assets/orb.xpm", a->mlx);
}

void	put_tile(t_game *a, int i, int j, char c)
{
	int	x;
	int	y;

	x = j * 32;
	y = i * 32;
	if (c == '1')
		mlx_put_image_to_window(a->mlx, a->win, a->wall->img, x, y);
	else
		mlx_put_image_to_window(a->mlx, a->win, a->empty->img, x, y);
	if (c == 'C')
		mlx_put_image_to_window(a->mlx, a->win, a->collect->img, x, y);
	if (c == 'P')
	{
		a->p_x = j;
		a->p_y = i;
		mlx_put_image_to_window(a->mlx, a->win, a->player->img, x, y);
	}
	if (c == 'E')
		mlx_put_image_to_window(a->mlx, a->win, a->exit->img, x, y);
}

void	put_tiles(t_game *a, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			put_tile(a, i, j, map[i][j]);
			j++;
		}
		i++;
	}
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
	ft_printf("All items : %d\n", a->c_all);
}

int	main(int argc, char **argv)
{
	t_game	a;

	if (argc != 2)
	{
		ft_printf("T'es bourre bro/sis!");
		return (0);
	}
	a.map = parser(argv[1], &a);
	if (a.map == NULL)
	{
		ft_printf("Invalid map.\n");
		return (0);
	}
	init_data(&a);
	init_window(&a);
	init_tiles(&a);
	put_tiles(&a, a.map);
	mlx_key_hook(a.win, &key_hook, &a);
	mlx_loop(a.mlx);
	return (0);
}
