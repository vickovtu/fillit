/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_scan.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:21:33 by mrudzik           #+#    #+#             */
/*   Updated: 2018/05/03 20:59:39 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SCAN_H
# define S_SCAN_H

typedef struct	s_scan
{
	int	inmap;
	int infiga;
	int	nah;
	int	alp;
}				t_scan;

struct			s_gen_map
{
	int			index;
	char		*map;
	int			conty;
	int			contx;
};

#endif
