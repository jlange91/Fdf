/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:52:00 by jlange            #+#    #+#             */
/*   Updated: 2017/04/02 15:52:36 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void		ft_tmp(t_mlx *mlx, int x, int y)
{
	while (y < mlx->info.len_y)
	{
		x = 0;
		while (x < mlx->info.len_x - 1)
		{
			ft_color_hor(mlx, x, y);
			line(mlx->map[y][x], mlx->map[y][x + 1], mlx);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < mlx->info.len_y - 1)
	{
		x = 0;
		while (x < mlx->info.len_x)
		{
			ft_color_ver(mlx, x, y);
			line(mlx->map[y][x], mlx->map[y + 1][x], mlx);
			x++;
		}
		y++;
	}
}

void					ft_display_img(t_mlx *mlx, int zoom)
{
	int		bpb;
	int		size_l;
	int		endian;

	mlx->mlx_img = mlx_new_image(mlx->mlx, mlx->x_win, mlx->y_win);
	mlx->str_img = mlx_get_data_addr(mlx->mlx_img, &bpb, &size_l, &endian);
	mlx->img = (unsigned int *)mlx->str_img;
	ft_calc_xy(&(mlx->info), mlx->map, zoom, mlx->opt);
	ft_tmp(mlx, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->mlx_img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->str_img);
}
