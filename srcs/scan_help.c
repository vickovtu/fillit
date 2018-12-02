/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:25:20 by mrudzik           #+#    #+#             */
/*   Updated: 2018/05/03 19:20:15 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		cur_linelen(const char *figa, int curind)
{
	int	count;

	count = 0;
	if (!(figa[curind]))
		return (0);
	else
		while (figa[curind] != '\n')
		{
			count++;
			curind++;
		}
	return (count);
}

void	scan_help1(int *inmap, int *infiga, int *alp, int help)
{
	if (help == 1)
	{
		*inmap = *inmap + 1;
		*infiga = *infiga + 1;
	}
	else if (help == 2)
	{
		*inmap = *inmap + 1;
		*infiga = *infiga + 1;
		*alp = *alp + 1;
	}
}

int		scan_help2(t_scan *s, int size, const char *figa)
{
	s->inmap = s->inmap + size + 1 - s->nah;
	s->infiga = s->infiga + 1;
	s->nah = cur_linelen(figa, s->infiga);
	if (s->inmap >= (size + 1) * size)
		return (0);
	return (1);
}

int		scan_check1(char infiga, char inmap)
{
	if (ft_isalpha(infiga) &&
			(ft_isalpha(inmap) || inmap == '\n' || inmap == '\0'))
		return (1);
	else
		return (0);
}
