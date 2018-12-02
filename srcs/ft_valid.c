/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 20:04:04 by vickovtu          #+#    #+#             */
/*   Updated: 2018/05/03 21:16:04 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_valid3(char **str)
{
	int i[5];

	i[0] = 0;
	while (str[i[0]])
	{
		i[1] = 0;
		i[2] = 0;
		i[3] = 0;
		i[4] = 0;
		while (str[i[0]][i[1]])
		{
			if (str[i[0]][i[1]] == '#')
				i[2]++;
			if (str[i[0]][i[1]] == '.')
				i[3]++;
			if (str[i[0]][i[1]] == '\n')
				i[4]++;
			i[1]++;
		}
		if (i[2] != 4 || i[3] != 12 || i[4] != 4 || i[0] > 25)
			return (1);
		i[0]++;
	}
	return (0);
}

static void	ft_replacement(char **str)
{
	int		a;
	int		b;
	char	c;

	a = -1;
	c = 'A';
	while (str[++a])
	{
		b = -1;
		while (str[a][++b])
			if (str[a][b] == '#')
				str[a][b] = c;
		c++;
	}
}

static int	ft_test(char *str, int i, int c, int a)
{
	while (str[++c] && ++i > 0 && ++a > 0)
	{
		if (str[c] != '#' && str[c] != '.' && i != 5 && a != 21)
			return (1);
		if (a == 21)
		{
			if (str[c] != '\n')
				return (1);
			if (str[c] == '\n')
				str[c] = '*';
			i = 0;
			a = 0;
		}
		if (i == 5)
		{
			if (str[c] != '\n')
				return (1);
			i = 0;
		}
	}
	return (0);
}

static int	ft_test2(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	if (str[index - 2] == '\n')
		return (1);
	return (0);
}

char		**ft_valid(char *str)
{
	int		i;
	int		a;
	int		c;
	char	**str1;

	i = 0;
	a = 0;
	c = -1;
	if (ft_test2(str))
		return (NULL);
	if (ft_test(str, i, c, a) == 1)
		return (NULL);
	if (!(str1 = ft_strsplit(str, '*')))
		return (NULL);
	if (ft_valid2(str1) == 1)
		return (NULL);
	if (ft_valid3(str1) == 1)
		return (NULL);
	ft_replacement(str1);
	return (str1);
}
