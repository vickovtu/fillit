/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:35:05 by mrudzik           #+#    #+#             */
/*   Updated: 2018/05/03 15:43:07 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_exist(int figa, char *map)
{
	size_t	index;
	int		alp;

	alp = 0;
	index = 0;
	while (map[index] != '\0')
	{
		if (map[index] == 'A' + figa)
			alp++;
		index++;
	}
	if (alp == 4)
		return (1);
	else
		return (0);
}

int		fillit_slowly(char **figu_fxd, char *map, int figa)
{
	int	check;
	int size;
	int dop;

	dop = 0;
	size = calc_size_map(map);
	check = 0;
	while (figu_fxd[figa])
	{
		check = merge_map(map, figu_fxd[figa], size, 1 + dop);
		if (check == 1)
		{
			if ((fillit_slowly(figu_fxd, map, figa + 1)))
				break ;
			remv_figav_map(map, figa);
			dop++;
		}
		else if (check == 0)
			return (0);
	}
	return (1);
}

int		map_ready(char *map, int fig_count)
{
	int	alp;
	int index;

	index = 0;
	alp = 0;
	while (map[index] != '\0')
	{
		if (ft_isalpha(map[index]))
			alp++;
		index++;
	}
	if (alp / 4 == fig_count)
		return (1);
	else
		return (0);
}

int		fillit_fast(char **figu, char *map, int figa, int fig_count)
{
	int size;
	int dep;

	dep = -1;
	size = calc_size_map(map);
	if (figa == fig_count)
		return (1);
	while (++dep <= fig_count)
	{
		if (!(is_exist(dep, map)))
		{
			if (merge_map(map, figu[dep], size, 1))
			{
				if (fillit_fast(figu, map, figa + 1, fig_count))
					break ;
				if (map_ready(map, fig_count))
					return (1);
				remv_figav_map(map, dep);
			}
			else
				return (0);
		}
	}
	return (1);
}

void	fillit_calc(char **figury)
{
	char	*map;
	char	**figu_fxd;
	int		size;

	figu_fxd = figury_fix(figury);
	size = calc_map(figu_fxd) - 1;
	map = gen_map(size);
	if (calc_figav_figu(figu_fxd) < 5)
	{
		while (fillit_slowly(figu_fxd, map, 0) != 1)
		{
			ft_strdel(&map);
			map = gen_map(++size);
		}
	}
	else
	{
		while (fillit_fast(figu_fxd, map, 0, calc_figav_figu(figu_fxd)) != 1)
		{
			ft_strdel(&map);
			map = gen_map(++size);
		}
	}
	ft_putstr(++map);
}
