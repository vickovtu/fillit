/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remv_figav_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:32:56 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/28 18:36:24 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		remv_figav_map(char *map, int figa)
{
	size_t index;

	index = 0;
	while (map[index] != '\0')
	{
		if (map[index] == 'A' + figa)
			map[index] = '.';
		index++;
	}
	return (1);
}
