/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_ignr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:37:01 by mrudzik           #+#    #+#             */
/*   Updated: 2018/05/01 16:03:53 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	ft_strlen_ignr(const char *s, char ignr)
{
	size_t	index;
	size_t	skip;

	skip = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == ignr)
			skip++;
		index++;
	}
	return (index - skip);
}

char	*ft_strsub_ignr(char const *s, unsigned int start,
		size_t len, char ignr)
{
	size_t	index;
	char	*sub;
	int		alp;

	alp = 0;
	if (!s)
		return (NULL);
	if ((sub = ft_strnew(ft_strlen_ignr(s, ignr))) == NULL)
		return (NULL);
	index = 0;
	while (start < len && alp < 4)
	{
		if (s[start] == ignr)
			start++;
		else
		{
			sub[index] = s[start];
			if (ft_isalpha(sub[index++]))
				alp++;
			start++;
		}
	}
	sub[index] = '\n';
	sub[index + 1] = '\0';
	return (sub);
}
