/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_figav_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:01:48 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/30 16:35:28 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		calc_figa(char **figu_fxd)
{
	int figa;

	figa = 0;
	while (figu_fxd[figa])
		figa++;
	return (figa);
}

int		calc_figav_map(char *map)
{
	int index;
	int symb;

	index = 0;
	symb = 0;
	while (map[index] != '\0')
	{
		if (ft_isalpha(map[index]))
			symb++;
		index++;
	}
	return (symb / 4);
}
