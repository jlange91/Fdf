/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:23:16 by jlange            #+#    #+#             */
/*   Updated: 2017/04/02 17:06:42 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf(t_map *info_map, t_mlx mlx)
{
	ft_fill_tab(info_map, mlx.map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.x_win, mlx.y_win, info_map->file);
	info_map->x = mlx.x_win / 2;
	info_map->y = mlx.y_win / 2;
	info_map->z = 1;
	info_map->rot_x = 0;
	info_map->rot_y = 0;
	info_map->rot_z = 0;
	mlx.opt = 1;
	mlx.color = 0;
	mlx.color_opt = 1;
	mlx.info = *info_map;
	ft_display_img(&mlx, 0);
	mlx_hook(mlx.win, 2, (1L << 0), ft_display_hook, &mlx);
	mlx_hook(mlx.win, 17, (1L << 17), ft_redcross, &mlx);
	mlx_loop(mlx.mlx);
}

void	ft_malloc_map(t_map *info, t_mlx *mlx)
{
	int y;

	y = 0;
	mlx->map = (t_point**)malloc(sizeof(t_point*) * (info->len_y));
	while (y < info->len_y)
	{
		mlx->map[y] = (t_point*)malloc(sizeof(t_point) * (info->len_x));
		y++;
	}
}

int		main(int ac, char **av)
{
	t_map	map;
	t_mlx	mlx;

	if (ac < 2)
	{
		ft_putendl("usage : ./fdf [file]");
		return (0);
	}
	map.file = av[1];
	if (!(ft_parse(av[1], &map)))
		ft_putendl("bad file");
	else
	{
		mlx.x_win = WIN_X;
		mlx.y_win = WIN_Y;
		ft_malloc_map(&map, &mlx);
		ft_fdf(&map, mlx);
		ft_free_map(&mlx);
	}
	return (0);
}
