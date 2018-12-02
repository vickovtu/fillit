/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_figav_figu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:38:42 by mrudzik           #+#    #+#             */
/*   Updated: 2018/05/01 16:50:38 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		calc_figav_figu(char **figu)
{
	int count;
	int alp;
	int ind;
	int figa;

	figa = 0;
	count = 0;
	while (figu[count])
	{
		alp = 0;
		ind = 0;
		while (figu[count][ind] != '\0')
		{
			if (ft_isalpha(figu[count][ind]))
				alp++;
			ind++;
		}
		if (alp == 4)
			figa++;
		count++;
	}
	return (figa);
}
