#include "so_long.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	put_lign(t_data *data, int x, int y, int color, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		put_pixel(data, x + i, y, color);
		i++;
	}
}

void	put_rectangle(t_data *data, int x, int y, int color, int l, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		put_lign(data, x, y + i, color, l);
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	put_rectangle(&img, 200, 200, 0x00FF0000, 50, 50);
	win = mlx_new_window(mlx, 1920, 1080, "So_long");
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
