/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figury_fix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:50:29 by mrudzik           #+#    #+#             */
/*   Updated: 2018/05/03 15:33:25 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	figa_mark2(char *figa)
{
	int	index;
	int start;

	start = 0;
	while (start < 4)
	{
		index = start;
		while (index < 20)
		{
			if (ft_isalpha(figa[index]))
				break ;
			index = index + 5;
		}
		if (index >= 20)
		{
			index = start;
			while (index < 20)
			{
				figa[index] = '#';
				index = index + 5;
			}
		}
		start++;
	}
}

void	figa_mark1(char *figa)
{
	int	index;
	int start;

	index = 0;
	while (figa[index] != '\0')
	{
		start = index;
		while (figa[index] != '\n' && !(ft_isalpha(figa[index])))
			index++;
		if (figa[index] == '\n')
		{
			index = start;
			while (figa[index] != '\n')
				figa[index++] = '#';
		}
		index++;
	}
	figa_mark2(figa);
}

char	*figa_cut_hor(char *figa)
{
	int		ind1;
	char	*new;

	ind1 = 0;
	new = NULL;
	while (figa[ind1] == '#' || figa[ind1] == '\n')
		ind1++;
	if (figa[ind1] == '.' || (ft_isalpha(figa[ind1]) == 1))
		new = ft_strsub_ignr(figa, ind1, ft_strlen(figa), '#');
	return (new);
}

char	*figa_fix(char *figura)
{
	char *new;

	figa_mark1(figura);
	new = figa_cut_hor(figura);
	return (new);
}

char	**figury_fix(char **figury)
{
	int		figa;
	int		figura;
	char	**figury_fxd;

	figura = 0;
	figa = 0;
	while (figury[figura])
		figura++;
	figury_fxd = (char **)malloc((figura + 1) * sizeof(char *));
	figury_fxd[figura] = NULL;
	while (figury[figa])
	{
		figury_fxd[figa] = figa_fix(figury[figa]);
		figa++;
	}
	return (figury_fxd);
}
