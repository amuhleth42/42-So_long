/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:05 by amuhleth          #+#    #+#             */
/*   Updated: 2022/04/12 18:40:48 by amuhleth         ###   ########.fr       */
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
	int		move_count;
	t_tile	*wall;
	t_tile	*item;
	t_tile	*empty;
	t_tile	*exit;
	t_tile	*player;
	t_parse	*parsing;
}			t_game;

void	parser(char *path, t_game *a);
void	print_map(char **map);
int		key_hook(int key, t_game *game);
int		key_down(int key, t_game *game);

int		is_rectangle(char **map, t_parse *parsing);
int		is_closed(char **map, t_parse *parsing);
int		check_no_other(char **map);
int		check_ber(char *path);
int		is_there_char(char **map, char c);
int		char_is_valid(char c);

void	init_tile(t_tile *tile, char *file, void *mlx);
void	init_tiles(t_game *a);
void	put_tile(t_game *a, int i, int j, char c);
void	put_tiles(t_game *a, char **map);

void	up(t_game *a, int x, int y);
void	down(t_game *a, int x, int y);
void	left(t_game *a, int x, int y);
void	right(t_game *a, int x, int y);

void	exit_game(t_game *a);
void	free_map(t_game *a);
void	die(char *s);

char	**lst_to_split(t_list *lines);

#endif
