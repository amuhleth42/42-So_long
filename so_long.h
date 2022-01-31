/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:05:05 by amuhleth          #+#    #+#             */
/*   Updated: 2022/01/19 19:10:22 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

#include "mlx.h"
#include "libft.h"
#include <fcntl.h>

typedef struct	s_ids
{
	void	*mlx;
	void	*win;
}			t_ids;

typedef struct	s_img
{
	void	*img;
	int		w;
	int		h;
}			t_img;

typedef struct	s_parse
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

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_img	*wall;
	t_img	*collect;
	t_img	*empty;
	t_img	*exit;
	t_img	*player;
	t_parse	*parsing;
}			t_game;

char	**parser(char *path, t_game *a);
void	print_map(char **map);

#endif
