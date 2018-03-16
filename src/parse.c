/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 22:26:55 by jlange            #+#    #+#             */
/*   Updated: 2017/04/02 17:04:17 by jlange           ###   ########.fr       */
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

static inline int	ft_count_nb(char *line)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			i += ft_intlen2(ft_atoi(&line[i]));
			while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
				i++;
			tmp++;
		}
		else if (line[i] != ' ')
			return (-1);
		else
			i++;
	}
	return (tmp);
}

bool				ft_parse(char *str, t_map *map)
{
	char	*line;
	int		nb;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (false);
	if (get_next_line(fd, &line) > 0)
	{
		nb = ft_count_nb(line);
		free(line);
		if (nb == -1)
			return (false);
	}
	else
		return (false);
	map->len_x = nb;
	map->len_y = 1;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		map->len_y++;
	}
	close(fd);
	return (true);
}
