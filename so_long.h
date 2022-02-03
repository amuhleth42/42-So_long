/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:05 by amuhleth          #+#    #+#             */
/*   Updated: 2022/02/03 14:54:09 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

typedef struct s_tile
{
	void	*img;
	int		w;
	int		h;
}			t_tile;

typedef struct s_parse
{
	int	x;
	int	y;
	int	rectangle;
	int	closed;
	int	exit;
	int	collect;
	int	position;
	int	no_other;
	int	ber_format;
}		t_parse;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		p_x;
	int		p_y;
	int		c_count;
	int		c_all;
	t_tile	*wall;
	t_tile	*collect;
	t_tile	*empty;
	t_tile	*exit;
	t_tile	*player;
	t_parse	*parsing;
}			t_game;

char	**parser(char *path, t_game *a);
void	print_map(char **map);
int		key_hook(int key, t_game *game);

int		is_rectangle(char **map, t_parse *parsing);
int		is_closed(char **map, t_parse *parsing);
int		check_no_other(char **map);
int		check_ber(char *path);
int		is_there_char(char **map, char c);
int		char_is_valid(char c);

#endif
