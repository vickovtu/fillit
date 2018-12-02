/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:52:27 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/22 20:17:49 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**gen_two_map(int size)
{
	char	**map;
	int		row;

	row = 0;
	map = ft_memalloc((size + 1) * sizeof(char *));
	while (row < size)
	{
		map[row] = ft_strnew(((size + 1) * sizeof(char)));
		row++;
	}
	row = 0;
	while (row < size)
	{
		ft_memset(map[row], '.', size);
		map[row][size] = '\n';
		row++;
	}
	return (map);
}
