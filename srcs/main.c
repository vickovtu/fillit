/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:28:23 by vickovtu          #+#    #+#             */
/*   Updated: 2018/05/03 20:50:35 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_scan(char **argv)
{
	char	*buf;
	char	*buff;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	while (read(fd, &buf[i], 1) > 0)
		i++;
	if (buf[0] == '\0')
		return (NULL);
	if (!(buff = ft_strnew(i)))
		return (NULL);
	ft_strcpy(buff, buf);
	free(buf);
	buf = NULL;
	if ((close(fd)) < 0)
		return (NULL);
	return (buff);
}

int			main(int argc, char **argv)
{
	char	*str;
	char	**str1;
	int		i;

	i = 0;
	str1 = NULL;
	if (argc == 2)
	{
		if (!(str = ft_scan(argv)))
		{
			ft_putendl("error");
			ft_strdel(&str);
		}
		else if (!(str1 = ft_valid(str)))
		{
			ft_putendl("error");
			ft_strdel(str1);
		}
		if (str1)
			fillit_calc(str1);
	}
	else
		ft_putendl("usage: ./fillit source_file_name");
	return (0);
}
