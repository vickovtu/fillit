/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:34:20 by mrudzik           #+#    #+#             */
/*   Updated: 2018/04/13 16:35:43 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iswhite(int c)
{
	if ((8 < c && c < 14) || c == 32)
		return (1);
	else
		return (0);
}
