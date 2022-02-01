/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:37:28 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/01 19:28:22 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *a, int x, int y)
{
	if (a->map[y - 1][x] != '1')
	{
		a->p_y = y - 1;
		mlx_put_image_to_window(a->mlx, a->win,
			a->player->img, x * 32, (y - 1) * 32);
	}
}

void	down(t_game *a, int x, int y)
{
	if (a->map[y + 1][x] != '1')
	{
		a->p_y = y + 1;
		mlx_put_image_to_window(a->mlx, a->win,
			a->player->img, x * 32, (y + 1) * 32);
	}
}

void	left(t_game *a, int x, int y)
{
	if (a->map[y][x - 1] != '1')
	{
		a->p_x = x - 1;
		mlx_put_image_to_window(a->mlx, a->win,
			a->player->img, (x - 1) * 32, y * 32);
	}
}

void	right(t_game *a, int x, int y)
{
	if (a->map[y][x + 1] != '1')
	{
		a->p_x = x + 1;
		mlx_put_image_to_window(a->mlx, a->win,
			a->player->img, (x + 1) * 32, y * 32);
	}
}

int	key_hook(int keycode, t_game *a)
{
	if (keycode == 53)
		mlx_destroy_window(a->mlx, a->win);
	if (keycode == 13)
		up(a, a->p_x, a->p_y);
	if (keycode == 1)
		down(a, a->p_x, a->p_y);
	if (keycode == 0)
		left(a, a->p_x, a->p_y);
	if (keycode == 2)
		right(a, a->p_x, a->p_y);
	return (0);
}
