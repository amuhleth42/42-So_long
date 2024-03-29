/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:26:24 by amuhleth          #+#    #+#             */
/*   Updated: 2022/03/09 14:21:47 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	die(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_map(t_game *a)
{
	int	i;

	i = 0;
	while (a->map[i] != NULL)
	{
		free(a->map[i]);
		i++;
	}
	if (a->map != NULL)
		free(a->map);
}

void	free_tiles(t_game *a)
{
	mlx_destroy_image(a->mlx, a->wall->img);
	mlx_destroy_image(a->mlx, a->item->img);
	mlx_destroy_image(a->mlx, a->empty->img);
	mlx_destroy_image(a->mlx, a->exit->img);
	mlx_destroy_image(a->mlx, a->player->img);
	free(a->wall);
	free(a->item);
	free(a->empty);
	free(a->exit);
	free(a->player);
}

void	free_all(t_game *a)
{
	free(a->parsing);
	free_map(a);
	free_tiles(a);
}

void	exit_game(t_game *a)
{
	mlx_destroy_window(a->mlx, a->win);
	free_all(a);
	exit(0);
}
