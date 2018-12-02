/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:01:36 by vickovtu          #+#    #+#             */
/*   Updated: 2018/05/03 20:48:39 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "s_scan.h"

# define BUFF_SIZE 4096

char		**ft_valid(char *str);
char		*ft_scan(char **argv);
int			main(int argc, char **argv);
int			ft_valid2(char **str);

void		print_two_mas(char **str);
void		fillit_calc(char **figu);
char		**gen_two_map(int size);
char		*gen_map(int size);
int			merge_map(char *map, const char *figa, int size, int start);
int			cur_linelen(const char *figa, int curind);
void		scan_help1(int *inmap, int *infiga, int *alp, int help);
int			scan_help2(t_scan *s, int size, const char *figa);
int			scan_check1(char infiga, char inmap);
int			remv_figav_map(char *map, int figa);
int			calc_figav_map(char *map);
int			calc_figav_figu(char **figu);
int			calc_size_map(const char *map);
int			calc_map(char **figu);
int			calc_figa(char **figu_fxd);
char		**figury_fix(char **figury);
char		*ft_strsub_ignr(char const *s, unsigned int start,
				size_t len, char ignr);
#endif
