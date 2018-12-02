/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:57:39 by mrudzik           #+#    #+#             */
/*   Updated: 2018/05/03 19:39:18 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*insert_figuv_map(char *map, const char *figa, int size, int coord)
{
	int inmap;
	int infiga;
	int nah;

	inmap = coord;
	infiga = 0;
	nah = cur_linelen(figa, infiga);
	while (figa[infiga] != '\0')
	{
		if (figa[infiga] == '.')
			scan_help1(&inmap, &infiga, &nah, 1);
		else if (figa[infiga] == '\n')
		{
			inmap = inmap + size + 1 - nah;
			infiga++;
			nah = cur_linelen(figa, infiga);
		}
		else if (ft_isalpha(figa[infiga]))
		{
			map[inmap] = figa[infiga];
			inmap++;
			infiga++;
		}
	}
	return (map);
}

int		scan_space_map(char *map, const char *figa, int size, int coord)
{
	t_scan s;

	s.inmap = coord;
	s.alp = 0;
	s.infiga = 0;
	s.nah = cur_linelen(figa, s.infiga);
	while (figa[s.infiga] != '\0' && map[s.inmap] && s.alp < 4)
	{
		if (figa[s.infiga] == '.')
			scan_help1(&s.inmap, &s.infiga, &s.alp, 1);
		else if (ft_isalpha(figa[s.infiga]) && map[s.inmap] == '.')
			scan_help1(&s.inmap, &s.infiga, &s.alp, 2);
		else if (figa[s.infiga] == '\n')
			if (!(scan_help2(&s, size, figa)))
				return (0);
		if (scan_check1(figa[s.infiga], map[s.inmap]))
			return (0);
	}
	if (s.alp == 4)
		return (1);
	if (!(map[s.inmap]))
		return (0);
	return (1);
}

int		merge_map(char *map, const char *figa, int size, int start)
{
	int	index;
	int ins;

	ins = 0;
	index = start;
	if (!(figa))
		return (0);
	while (map[index] != '\0' && ins == 0)
	{
		if (scan_space_map(map, figa, size, index))
		{
			insert_figuv_map(map, figa, size, index);
			ins++;
		}
		index++;
	}
	if (map[index] == '\0' && ins == 0)
		return (0);
	return (1);
}
