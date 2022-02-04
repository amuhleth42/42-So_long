/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:07:40 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/04 15:20:32 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *a, int x, int y)
{
	if (!((a->map[y - 1][x] == '1')
		|| (a->map[y - 1][x] == 'E' && a->c_all != a->c_count)))
	{
		a->p_y = y - 1;
		a->move_count++;
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
		a->move_count++;
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
		a->move_count++;
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
		a->move_count++;
		mlx_put_image_to_window(a->mlx, a->win,
			a->player->img, (x + 1) * 32, y * 32);
		mlx_put_image_to_window(a->mlx, a->win, a->empty->img, x * 32, y * 32);
	}
}
