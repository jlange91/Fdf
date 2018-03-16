/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:51:11 by jlange            #+#    #+#             */
/*   Updated: 2017/04/02 15:51:13 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_calc_xy(t_map *info, t_point **map, int zoom, int opt)
{
	int				y;
	int				x;
	t_point2		tmp;
	static float	zoum = 1;

	y = -1;
	zoum += (zoom == 1) ? 0.1 : 0;
	zoum -= (zoom == 2 && zoum > 0.1) ? 0.1 : 0;
	while (++y < info->len_y)
	{
		x = -1;
		while (++x < info->len_x)
		{
			tmp = ft_calc_rot(info, x, y, ((map[y][x].z != 0) ?
			map[y][x].z * info->z : map[y][x].z));
			map[y][x].x = (opt == 1) ? ((1.0 * tmp.x - 1.0 * tmp.y)
			* zoum * AMP) + 0.5 : ((tmp.x + 1.0 * tmp.z) * zoum * AMP) + 0.5;
			map[y][x].y = (opt == 1) ? (((tmp.z * -1) + 1.0 / 2 * tmp.x + 1.0
			/ 2 * tmp.y) * zoum * AMP) + 0.5 : ((tmp.y + 1.0 / 2 * tmp.z) *
			zoum * AMP) + 0.5;
			map[y][x].x += info->x;
			map[y][x].y += info->y;
		}
	}
}
