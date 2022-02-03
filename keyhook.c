/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:37:28 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/03 15:12:16 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *a, int x, int y)
{
	if (!((a->map[y - 1][x] == '1')
			|| (a->map[y - 1][x] == 'E' && a->c_all != a->c_count)))
	{
		a->p_y = y - 1;
		mlx_put_image_to_window(a->mlx, a->win,
			a->player->img, x * 32, (y - 1) * 32);
		mlx_put_image_to_window(a->mlx, a->win, a->empty->img, x * 32, y * 32);
	}
}

void	down(t_game *a, int x, int y)
{
	if (!((a->map[y + 1][x] == '1')
			|| (a->map[y + 1][x] == 'E' && a->c_all != a->c_count)))
	{
		a->p_y = y + 1;
		mlx_put_image_to_window(a->mlx, a->win,
			a->player->img, x * 32, (y + 1) * 32);
		mlx_put_image_to_window(a->mlx, a->win, a->empty->img, x * 32, y * 32);
	}
}

void	left(t_game *a, int x, int y)
{
	if (!((a->map[y][x - 1] == '1')
			|| (a->map[y][x - 1] == 'E' && a->c_all != a->c_count)))
	{
		a->p_x = x - 1;
		mlx_put_image_to_window(a->mlx, a->win,
			a->player->img, (x - 1) * 32, y * 32);
		mlx_put_image_to_window(a->mlx, a->win, a->empty->img, x * 32, y * 32);
	}
}

void	right(t_game *a, int x, int y)
{
	if (!((a->map[y][x + 1] == '1')
			|| (a->map[y][x + 1] == 'E' && a->c_all != a->c_count)))
	{
		a->p_x = x + 1;
		mlx_put_image_to_window(a->mlx, a->win,
			a->player->img, (x + 1) * 32, y * 32);
		mlx_put_image_to_window(a->mlx, a->win, a->empty->img, x * 32, y * 32);
	}
}

void	check_items_count(t_game *a, int x, int y)
{
	if (a->map[y][x] == 'C')

	{
		a->c_count++;
		a->map[y][x] = '0';
	}
	ft_printf("Items : %d\n", a->c_count);
}

void	movement(int key, t_game *a)
{
	if (key == 13)
		up(a, a->p_x, a->p_y);
	if (key == 1)
		down(a, a->p_x, a->p_y);
	if (key == 0)
		left(a, a->p_x, a->p_y);
	if (key == 2)
		right(a, a->p_x, a->p_y);
	check_items_count(a, a->p_x, a->p_y);
}

int	key_hook(int key, t_game *a)
{
	if (key == 53)
		mlx_destroy_window(a->mlx, a->win);
	if (key == 13 || key == 1 || key == 0 || key == 2)
		movement(key, a);
	return (0);
}
