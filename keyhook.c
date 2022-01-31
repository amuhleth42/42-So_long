#include "so_long.h"

int	key_hook(int keycode, t_game *a)
{
	if (keycode == 53)
		mlx_destroy_window(a->mlx, a->win);
	return (0);
}
