/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:32:37 by jlange            #+#    #+#             */
/*   Updated: 2017/04/02 17:04:09 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	ft_intlen2(intmax_t nb)
{
	int len;

	len = 1;
	if (nb < 0)
		len++;
	while ((nb = nb / 10))
		len++;
	return (len);
}

static inline void	ft_fill_z(char *line, t_point *map)
{
	int i;
	int x;
	int tmp;

	i = 0;
	x = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			tmp = ft_atoi(&line[i]);
			i += ft_intlen2(tmp);
			while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
				i++;
			map[x].z = tmp;
			x++;
		}
		else
			i++;
	}
}

static inline void	ft_fill_z_info(t_map *info, t_point **map)
{
	int y;
	int x;

	y = 0;
	info->min_z = (map && map[0] && map[0][0].z) ? map[0][0].z : 0;
	info->max_z = (map && map[0] && map[0][0].z) ? map[0][0].z : 0;
	while (y < info->len_y)
	{
		x = 0;
		while (x < info->len_x)
		{
			info->min_z = (map[y][x].z < info->min_z) ?
				map[y][x].z : info->min_z;
			info->max_z = (map[y][x].z > info->max_z) ?
				map[y][x].z : info->max_z;
			x++;
		}
		y++;
	}
}

void				ft_fill_tab(t_map *info_map, t_point **map)
{
	int		y;
	char	*line;
	int		fd;

	y = 0;
	fd = open(info_map->file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_fill_z(line, map[y]);
		y++;
		free(line);
	}
	ft_fill_z_info(info_map, map);
	close(fd);
}
