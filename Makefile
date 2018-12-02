# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vickovtu <vickovtu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/15 11:09:14 by vickovtu          #+#    #+#              #
#    Updated: 2018/05/04 13:17:00 by mrudzik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFILE = srcs/ft_valid2.c \
		srcs/main.c \
		srcs/ft_valid.c \
		srcs/print_two_mas.c \
		srcs/fillit_calc.c \
		srcs/gen_map.c \
		srcs/merge_map.c \
		srcs/figury_fix.c \
		srcs/ft_strsub_ignr.c \
		srcs/remv_figav_map.c \
		srcs/calc_figav_map.c \
		srcs/calc_figav_figu.c \
		srcs/calc_size_map.c \
		srcs/calc_map.c \
		srcs/scan_help.c

OFILE = ft_valid2.o main.o ft_valid.o\
		print_two_mas.o\
		fillit_calc.o gen_map.o merge_map.o\
		figury_fix.o ft_strsub_ignr.o remv_figav_map.o\
		calc_figav_map.o calc_size_map.o calc_figav_figu.o\
		calc_map.o scan_help.o

HEADER = srcs/header.h

all: $(NAME)

$(NAME):
	@make re -C libft
	@gcc -Wall -Wextra -Werror -I $(HEADER) -c $(CFILE)
	@gcc -Wall -Wextra -Werror $(OFILE) -o $(NAME) libft/libft.a

clean:
	@make clean -C libft
	@/bin/rm -f $(OFILE)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
