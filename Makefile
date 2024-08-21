# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edforte <edforte@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 16:31:02 by edforte           #+#    #+#              #
#    Updated: 2024/08/21 19:01:11 by edforte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFILES = \
			main.c \
			checker.c \
			checker2.c \
			checker_utils.c \
			checker_utils2.c \
			ft_split.c \
			pathfinder.c \
			game.c \
			walls.c \
			print_map.c \
			set_structs.c \
			set_structs_utils.c \
			movement.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_putchar.c \
			ft_printf/ft_putnbr.c \
			ft_printf/ft_putstr.c \

OBJ = $(CFILES:.c=.o)
CC = @ gcc
FLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


name : $(NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./mlx_linux
	$(CC) $(FLAGS) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	@ $(RM) $(OBJ)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all
