/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:42:34 by amuhleth          #+#    #+#             */
/*   Updated: 2022/01/19 18:06:14 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_img *img, char *file, void *mlx)
{
	img->w = 16;
	img->h = 16;
	img->img = mlx_xpm_file_to_image(mlx, file, &img->w, &img->h);
}

int	main(void)
{
	t_ids	ids;
	t_img	wall;
	t_img	collect;

	ids.mlx = mlx_init();
	ids.win = mlx_new_window(ids.mlx, 1000, 1000, "So_long");
	init_img(&wall, "assets/wall_block.xpm", ids.mlx);
	init_img(&collect, "assets/orb.xpm", ids.mlx);
	mlx_put_image_to_window(ids.mlx, ids.win, wall.img, 100, 100);
	mlx_put_image_to_window(ids.mlx, ids.win, collect.img, 200, 200);
	mlx_loop(ids.mlx);
}
