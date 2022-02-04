/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:37:28 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/04 15:48:42 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_items_count(t_game *a, int x, int y)
{
	if (a->map[y][x] == 'C')
	{
		a->c_count++;
		a->map[y][x] = '0';
	}
}

void	check_end(t_game *a, int x, int y)
{
	if (a->map[y][x] == 'E')
	{
		ft_printf("Well done! You've done it in %d moves!\n", a->move_count);
		exit_game(a);
	}
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
	ft_printf("Move : %d\n", a->move_count);
	check_end(a, a->p_x, a->p_y);
}

int	key_hook(int key, t_game *a)
{
	if (key == 53)
		exit_game(a);
	if (key == 13 || key == 1 || key == 0 || key == 2)
		movement(key, a);
	return (0);
}
