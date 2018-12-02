/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:14:13 by mrudzik           #+#    #+#             */
/*   Updated: 2018/05/03 20:58:54 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*gen_map(int size)
{
	struct s_gen_map gen;

	gen.conty = 0;
	gen.contx = 0;
	gen.index = 0;
	if (!(gen.map = ft_strnew(((size + 1) * size) + 1)))
		return (NULL);
	gen.map[gen.index++] = '\n';
	while (gen.conty < size + 1)
	{
		if (gen.contx <= size)
		{
			gen.map[gen.index] = '.';
			gen.contx++;
		}
		else if (gen.contx == size + 1)
		{
			gen.contx = 0;
			gen.conty++;
			gen.map[gen.index] = '\n';
		}
		gen.index++;
	}
	gen.map[gen.index] = '\0';
	return (gen.map);
}
