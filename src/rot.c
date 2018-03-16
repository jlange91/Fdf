/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:52:10 by jlange            #+#    #+#             */
/*   Updated: 2017/04/02 15:52:11 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline t_matrice		ft_mult_mat(t_matrice mat1, t_matrice mat2)
{
	t_matrice ret;

	ret.a = ((mat1.a * mat2.a) + (mat1.b * mat2.d) + (mat1.c * mat2.g));
	ret.b = ((mat1.a * mat2.b) + (mat1.b * mat2.e) + (mat1.c * mat2.h));
	ret.c = ((mat1.a * mat2.c) + (mat1.b * mat2.f) + (mat1.c * mat2.i));
	ret.d = ((mat1.d * mat2.a) + (mat1.e * mat2.d) + (mat1.f * mat2.g));
	ret.e = ((mat1.d * mat2.b) + (mat1.e * mat2.e) + (mat1.f * mat2.h));
	ret.f = ((mat1.d * mat2.c) + (mat1.e * mat2.f) + (mat1.f * mat2.i));
	ret.g = ((mat1.g * mat2.a) + (mat1.h * mat2.d) + (mat1.i * mat2.g));
	ret.h = ((mat1.g * mat2.b) + (mat1.h * mat2.e) + (mat1.i * mat2.h));
	ret.i = ((mat1.g * mat2.c) + (mat1.h * mat2.f) + (mat1.i * mat2.i));
	return (ret);
}

static inline t_matrice		ft_mat_x(t_map *info)
{
	t_matrice mat;

	mat.a = 1;
	mat.b = 0;
	mat.c = 0;
	mat.d = 0;
	mat.e = cos(info->rot_x);
	mat.f = (sin(info->rot_x) * -1);
	mat.g = 0;
	mat.h = sin(info->rot_x);
	mat.i = cos(info->rot_x);
	return (mat);
}

static inline t_matrice		ft_mat_y(t_map *info)
{
	t_matrice mat;

	mat.a = cos(info->rot_y);
	mat.b = 0;
	mat.c = sin(info->rot_y);
	mat.d = 0;
	mat.e = 1;
	mat.f = 0;
	mat.g = (sin(info->rot_y) * -1);
	mat.h = 0;
	mat.i = cos(info->rot_y);
	return (mat);
}

static inline t_matrice		ft_mat_z(t_map *info)
{
	t_matrice mat;

	mat.a = cos(info->rot_z);
	mat.b = (sin(info->rot_z) * -1);
	mat.c = 0;
	mat.d = sin(info->rot_z);
	mat.e = cos(info->rot_z);
	mat.f = 0;
	mat.g = 0;
	mat.h = 0;
	mat.i = 1;
	return (mat);
}

t_point2					ft_calc_rot(t_map *info, int x, int y, float z)
{
	t_point2	tmp;
	t_matrice	matx;
	t_matrice	maty;
	t_matrice	matz;
	t_matrice	final;

	matx = ft_mat_x(info);
	maty = ft_mat_y(info);
	matz = ft_mat_z(info);
	final = ft_mult_mat(matx, maty);
	final = ft_mult_mat(final, matz);
	x = x - info->len_x / 2;
	y = y - info->len_y / 2;
	z = z - info->max_z / 2;
	tmp.x = x * final.a + y * final.b + z * final.c;
	tmp.y = x * final.d + y * final.e + z * final.f;
	tmp.z = x * final.g + y * final.h + z * final.i;
	return (tmp);
}
