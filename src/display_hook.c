/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:32:51 by jlange            #+#    #+#             */
/*   Updated: 2017/04/02 16:42:56 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void		ft_display_hook3(int keycode, t_mlx *mlx)
{
	if (keycode == ROT_X1 || keycode == ROT_X2)
	{
		mlx->info.opt_rot = 1;
		mlx->info.rot_x += (keycode == ROT_X1) ? -SPEED_ROT : SPEED_ROT;
		ft_display_img((t_mlx*)mlx, 0);
	}
	else if (keycode == ROT_Y1 || keycode == ROT_Y2)
	{
		mlx->info.opt_rot = 2;
		mlx->info.rot_y += (keycode == ROT_Y1) ? SPEED_ROT : -SPEED_ROT;
		ft_display_img((t_mlx*)mlx, 0);
	}
	else if (keycode == ROT_Z1 || keycode == ROT_Z2)
	{
		mlx->info.opt_rot = 3;
		mlx->info.rot_z += (keycode == ROT_Z1) ? SPEED_ROT : -SPEED_ROT;
		ft_display_img((t_mlx*)mlx, 0);
	}
}

static inline void		ft_display_hook2(int keycode, t_mlx *mlx)
{
	if (keycode == COLOR)
	{
		mlx->color = (mlx->color == 32) ? 0 : mlx->color + 4;
		ft_display_img((t_mlx*)mlx, 0);
	}
	else if (keycode == MUL_COLOR1)
	{
		mlx->color_opt -= (mlx->color_opt >= 0) ? 0.1 : 0;
		ft_display_img((t_mlx*)mlx, 0);
	}
	else if (keycode == MUL_COLOR2)
	{
		mlx->color_opt += 0.1;
		ft_display_img((t_mlx*)mlx, 0);
	}
	else
		ft_display_hook3(keycode, mlx);
}

static inline void		ft_display_hook1(int keycode, t_mlx *mlx)
{
	if (keycode == ZOOM || keycode == DEZOOM)
		ft_display_img(mlx, (keycode == ZOOM) ? 1 : 2);
	else if (keycode == PROJECTION)
	{
		mlx->opt = (mlx->opt == 1) ? 2 : 1;
		ft_display_img(mlx, 0);
	}
	else if (keycode == MINUS || keycode == PLUS)
	{
		mlx->info.z += (keycode == PLUS) ? SPEED_Z : -SPEED_Z;
		ft_display_img((t_mlx*)mlx, 0);
	}
	else
		ft_display_hook2(keycode, mlx);
}

int						ft_display_hook(int keycode, void *mlx)
{
	t_mlx *test;

	test = (t_mlx*)mlx;
	if (keycode == ESC)
	{
		ft_free_map(test);
		exit(0);
	}
	else if (keycode == RIGHT || keycode == LEFT)
	{
		test->info.x = (keycode == RIGHT) ? test->info.x - SPEED_TRANS :
			test->info.x + SPEED_TRANS;
		ft_display_img((t_mlx*)mlx, 0);
	}
	else if (keycode == DOWN || keycode == UP)
	{
		test->info.y = (keycode == DOWN) ? test->info.y - SPEED_TRANS :
			test->info.y + SPEED_TRANS;
		ft_display_img((t_mlx*)mlx, 0);
	}
	else
		ft_display_hook1(keycode, test);
	return (0);
}
