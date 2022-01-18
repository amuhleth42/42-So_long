/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:27:58 by amuhleth          #+#    #+#             */
/*   Updated: 2022/01/18 18:47:33 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
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

int	key_hook(int keycode, t_img *img)
{
	if (keycode == 53)
		mlx_destroy_window(img->ids->mlx, img->ids->win);
	if (keycode == 13)
	{
		mlx_clear_window(img->ids->mlx, img->ids->win);
		img->y -= 20;
		mlx_put_image_to_window(img->ids->mlx, img->ids->win, img->img, img->x, img->y);
	}
	if (keycode == 1)
	{
		mlx_clear_window(img->ids->mlx, img->ids->win);
		img->y += 20;
		mlx_put_image_to_window(img->ids->mlx, img->ids->win, img->img, img->x, img->y);
	}
	if (keycode == 0)
	{
		mlx_clear_window(img->ids->mlx, img->ids->win);
		img->x -= 20;
		mlx_put_image_to_window(img->ids->mlx, img->ids->win, img->img, img->x, img->y);
	}
	if (keycode == 2)
	{
		mlx_clear_window(img->ids->mlx, img->ids->win);
		img->x += 20;
		mlx_put_image_to_window(img->ids->mlx, img->ids->win, img->img, img->x, img->y);
	}
	return (0);
}

int	main(void)
{
	t_win	win;
	t_img	img;

	win.mlx = mlx_init();
	img.img = mlx_new_image(win.mlx, 20, 20);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	put_rectangle(&img, 0, 0, 0x00FFFFFF, 20, 20);
	win.win = mlx_new_window(win.mlx, 1920, 1080, "So_long");
	img.ids = &win;
	img.x = 200;
	img.y = 200;
	mlx_put_image_to_window(win.mlx, win.win, img.img, img.x, img.y);
	mlx_key_hook(win.win, &key_hook, &img);
	mlx_loop(win.mlx);
	return (0);
}
