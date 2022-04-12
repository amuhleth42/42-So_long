/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:27:58 by amuhleth          #+#    #+#             */
/*   Updated: 2022/01/19 18:06:42 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_lign(t_img *img, int x, int y, int color, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		put_pixel(img, x + i, y, color);
		i++;
	}
}

void	put_row(t_img *img, int x, int y, int color, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		put_pixel(img, x, y + i, color);
		i++;
	}
}

void	put_rectangle(t_img *img, int x, int y, int color, int l, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		put_lign(img, x, y + i, color, l);
		i++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		mlx_destroy_window(game->ids->mlx, game->ids->win);
	if (keycode == 13)
	{
		mlx_clear_window(game->ids->mlx, game->ids->win);
		game->player->y -= 20;
		mlx_put_image_to_window(game->ids->mlx, game->ids->win, game->player->img, game->player->x, game->player->y);
	}
	if (keycode == 1)
	{
		mlx_clear_window(game->ids->mlx, game->ids->win);
		game->player->y += 20;
		mlx_put_image_to_window(game->ids->mlx, game->ids->win, game->player->img, game->player->x, game->player->y);
	}
	if (keycode == 0)
	{
		mlx_clear_window(game->ids->mlx, game->ids->win);
		game->player->x -= 20;
		mlx_put_image_to_window(game->ids->mlx, game->ids->win, game->player->img, game->player->x, game->player->y);
	}
	if (keycode == 2)
	{
		mlx_clear_window(game->ids->mlx, game->ids->win);
		game->player->x += 20;
		mlx_put_image_to_window(game->ids->mlx, game->ids->win, game->player->img, game->player->x, game->player->y);
	}
	return (0);
}

int	main(void)
{
	t_game	game;
	t_ids	ids;
	t_img	img;

	ids.mlx = mlx_init();
	img.img = mlx_new_image(ids.mlx, 20, 20);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	put_rectangle(&img, 0, 0, 0x00FFFFFF, 20, 20);
	ids.win = mlx_new_window(ids.mlx, 1920, 1080, "So_long");
	game.ids = &ids;
	game.player = &img;
	img.x = 200;
	img.y = 200;
	mlx_put_image_to_window(ids.mlx, ids.win, img.img, img.x, img.y);
	mlx_key_hook(ids.win, &key_hook, &game);
	mlx_loop(ids.mlx);
	return (0);
}
