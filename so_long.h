

#ifndef SO_LONG_H

# define SO_LONG_H

#include "mlx.h"
#include "libft.h"

typedef struct	s_win
{
	void	*mlx;
	void	*win;
}			t_win;

typedef struct	s_img
{
	t_win	*ids;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}			t_img;


#endif
