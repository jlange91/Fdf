/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:31:14 by jlange            #+#    #+#             */
/*   Updated: 2016/02/07 18:31:15 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	if (s1[i] == '\0')
	{
		while (s2[j] && j < n)
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
	}
	s1[i] = '\0';
	return (s1);
}
