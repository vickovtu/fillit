/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:19:57 by mrudzik           #+#    #+#             */
/*   Updated: 2018/05/03 15:22:17 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		calc_map(char **figu)
{
	int fig_area;
	int	size;

	size = 2;
	fig_area = calc_figav_figu(figu) * 4;
	while (size * size < fig_area)
		size++;
	return (size);
}
