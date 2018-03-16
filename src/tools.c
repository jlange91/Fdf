/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:51:53 by jlange            #+#    #+#             */
/*   Updated: 2017/04/02 16:36:45 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_mlx *mlx)
{
	int y;

	y = 0;
	while (y < mlx->info.len_y)
	{
		free(mlx->map[y]);
		y++;
	}
	free(mlx->map);
}

void	ft_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int test;

	test = (y * mlx->x_win) + x;
	if ((y > 0 && y < mlx->y_win) && (x > 0 && x < mlx->x_win))
		mlx->img[test] = color;
}

void	line(t_point map0, t_point map1, t_mlx *mlx)
{
	t_line l;

	l.dy = abs(map1.y - map0.y);
	l.dx = abs(map1.x - map0.x);
	l.sx = map0.x < map1.x ? 1 : -1;
	l.sy = map0.y < map1.y ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	while (1)
	{
		ft_pixel_put(mlx, map0.x, map0.y, mlx->z);
		if (map0.x == map1.x && map0.y == map1.y)
			break ;
		l.e2 = l.err;
		l.err -= (l.e2 > -l.dx) ? l.dy : 0;
		map0.x += (l.e2 > -l.dx) ? l.sx : 0;
		l.err += (l.e2 < l.dy) ? l.dx : 0;
		map0.y += (l.e2 < l.dy) ? l.sy : 0;
	}
}

int		ft_remap2(float x, t_remap info)
{
	int		ret;
	float	ret1;

	ret1 = ((x - info.in_min) * (info.out_max - info.out_min) / (info.in_max -
	info.in_min) + info.out_min);
	ret = ret1 + 0.49;
	return (ret);
}

int		ft_redcross(void *mlx)
{
	t_mlx *mlx2;

	mlx2 = (t_mlx*)mlx;
	ft_free_map(mlx2);
	exit(0);
}
