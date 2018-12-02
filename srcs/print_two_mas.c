/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_two_mas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:15:54 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/28 17:06:34 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_two_mas(char **str)
{
	int		figure;

	figure = 0;
	while (str[figure])
	{
		ft_putstr("++++\n");
		ft_putstr(str[figure]);
		write(1, "++++\n", 5);
		figure++;
	}
}
