
#include "so_long.h"

void	init_window(t_game *a)
{
	int	x;
	int	y;

	x = a->parsing->x * 32;
	y = a->parsing->y * 32;
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, x, y, "So_long");
}

void	init_img(t_img *img, char *file, void *mlx)
{
	img->w = 16;
	img->h = 16;
	img->img = mlx_xpm_file_to_image(mlx, file, &img->w, &img->h);
}

void	init_images(t_game *a)
{
	a->wall = ft_calloc(1, sizeof(t_img));
	a->empty = ft_calloc(1, sizeof(t_img));
	init_img(a->wall, "assets/wallgrass32.xpm", a->mlx);
	init_img(a->empty, "assets/star_l_32.xpm", a->mlx);
}

void	put_img(t_game *a, int i, int j, char c)
{
	int	x;
	int	y;

	x = j * 32;
	y = i * 32;
	if (c == '1')
		mlx_put_image_to_window(a->mlx, a->win, a->wall->img, x, y);
	else if (c == '0')
		mlx_put_image_to_window(a->mlx, a->win, a->empty->img, x, y);
}

void	put_images(t_game *a, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			put_img(a, i, j, map[i][j]);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	a;

	if (argc != 2)
	{
		ft_printf("T'es bourre bro/sis!");
		return (0);
	}
	a.map = parser(argv[1], &a);
	if (a.map == NULL)
	{
		ft_printf("Invalid map.\n");
		return (0);
	}
	print_map(a.map);
	init_window(&a);
	init_images(&a);
	put_images(&a, a.map);

	mlx_key_hook(a.win, &key_hook, &a);

	mlx_loop(a.mlx);
	return (0);
}
