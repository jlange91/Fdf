/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:56:39 by jlange            #+#    #+#             */
/*   Updated: 2017/05/03 13:52:47 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# define AMP 10
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define ZOOM 12
# define DEZOOM 14
# define PLUS 27
# define MINUS 24
# define PROJECTION 35
# define COLOR 8
# define ROT_Y1 13
# define ROT_X1 0
# define ROT_Y2 1
# define ROT_X2 2
# define ROT_Z1 15
# define ROT_Z2 3
# define MUL_COLOR1 6
# define MUL_COLOR2 7
# define BLANC 0x00FFFFFF
# define VERT_F 0x428C01
# define VERT_C 0x25FA3A
# define BLEU_F 0x013CFE
# define BLEU_C 0x2BC7FF
# define MARON_F 0x975600
# define MARON_C 0xC37612
# define JAUNE 0xF2F266
# define WIN_X 1200
# define WIN_Y 700
# define SPEED_ROT 0.1
# define SPEED_Z 0.1
# define SPEED_TRANS 20

typedef struct		s_line
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
}					t_line;

typedef struct		s_remap
{
	float in_min;
	float in_max;
	float out_min;
	float out_max;
}					t_remap;

typedef struct		s_matrice
{
	float a;
	float b;
	float c;
	float d;
	float e;
	float f;
	float g;
	float h;
	float i;
}					t_matrice;

typedef struct		s_point
{
	int x;
	int y;
	int z;
}					t_point;

typedef struct		s_point2
{
	float x;
	float y;
	float z;
}					t_point2;

typedef struct		s_map
{
	char		*file;
	int			len_x;
	int			len_y;
	int			min_z;
	int			max_z;
	int			x;
	int			y;
	float		z;
	int			opt_rot;
	float		rot_x;
	float		rot_y;
	float		rot_z;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*mlx_img;
	char			*str_img;
	int				z;
	int				color;
	float			color_opt;
	int				x_win;
	int				y_win;
	int				opt;
	unsigned int	*img;
	int				taille;
	t_point			**map;
	t_map			info;
}					t_mlx;

void				ft_display_img(t_mlx *mlx, int zoom);
int					ft_remap2(float x, t_remap info);
bool				ft_parse(char *file, t_map *map);
void				ft_fill_tab(t_map *info_map, t_point **map);
int					ft_display_hook(int keycode, void *mlx);
int					ft_redcross(void *lol);
void				ft_calc_xy(t_map *info, t_point **map, int zoom, int opt);
void				ft_color_hor(t_mlx *mlx, int x, int y);
void				ft_color_ver(t_mlx *mlx, int x, int y);
t_point2			ft_calc_rot(t_map *info, int x, int y, float z);
void				line(t_point map0, t_point map1, t_mlx *mlx);
void				ft_free_map(t_mlx *mlx);
#endif
