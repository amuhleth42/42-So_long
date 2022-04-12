/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:00:49 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/04 15:41:56 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	a->item = ft_calloc(1, sizeof(t_tile));
	a->exit = ft_calloc(1, sizeof(t_tile));
	init_tile(a->wall, "assets/wallgrass32.xpm", a->mlx);
	init_tile(a->item, "assets/star_l_32.xpm", a->mlx);
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
		mlx_put_image_to_window(a->mlx, a->win, a->item->img, x, y);
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
