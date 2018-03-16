/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:51:48 by jlange            #+#    #+#             */
/*   Updated: 2017/04/02 15:52:56 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int		ft_color_tmp3(t_mlx *mlx, t_remap info, int x, int y)
{
	int z;

	z = (mlx->map[y + 1][x].z > mlx->map[y][x].z) ?
	ft_remap2(mlx->map[y + 1][x].z, info) :
	ft_remap2(mlx->map[y][x].z, info);
	if (z == 0)
		z = BLEU_F;
	else if (z == 1)
		z = BLEU_C;
	else if (z == 2)
		z = JAUNE;
	else if (z == 3 || z == 4)
		z = VERT_C;
	else if (z == 5 || z == 6)
		z = VERT_F;
	else if (z == 7)
		z = MARON_C;
	else if (z == 8 || z == 9)
		z = MARON_F;
	else
		z = BLANC;
	return (z);
}

static inline int		ft_color_tmp2(t_mlx *mlx, t_remap info, int x, int y)
{
	int z;

	z = (mlx->map[y + 1][x].z > mlx->map[y][x].z) ?
	ft_remap2(mlx->map[y + 1][x].z, info) :
	ft_remap2(mlx->map[y][x].z, info);
	if (z < 1)
		z = BLEU_F;
	else if (z < 2)
		z = JAUNE;
	else if (z < 3)
		z = JAUNE;
	else if (z < 10)
		z = VERT_C;
	else if (z < 15)
		z = VERT_F;
	else if (z < 60)
		z = MARON_F;
	else if (z < 70)
		z = BLANC;
	else
		z = BLANC;
	return (z);
}

static inline int		ft_color_tmp1(t_mlx *mlx, t_remap info, int x, int y)
{
	int z;
	int z1;
	int z2;

	if (mlx->color % 8 == 0)
		info.out_max = 0x00FFFFFF - (0xFF << (mlx->color - 8));
	else
		info.out_max = 0xF;
	z1 = ft_remap2(mlx->map[y + 1][x].z, info);
	z2 = ft_remap2(mlx->map[y][x].z, info);
	z = (z1 > z2) ? z1 : z2;
	z = (mlx->color % 8 == 0) ? z : (z << (mlx->color)) * mlx->color_opt;
	return (z);
}

void					ft_color_ver(t_mlx *mlx, int x, int y)
{
	int			z;
	t_remap		info;

	info.in_min = mlx->info.min_z;
	info.in_max = mlx->info.max_z;
	info.out_min = 0;
	if (mlx->color < 28)
		z = ft_color_tmp1(mlx, info, x, y);
	else if (mlx->color == 28)
	{
		info.out_max = 100;
		z = ft_color_tmp2(mlx, info, x, y);
	}
	else
	{
		info.out_max = 10;
		z = ft_color_tmp3(mlx, info, x, y);
	}
	mlx->z = (mlx->color > 0) ? z : 0x00FFFFFF;
}
