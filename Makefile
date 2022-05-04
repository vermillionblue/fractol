# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 11:29:43 by danisanc          #+#    #+#              #
#    Updated: 2022/05/03 22:22:03 by danisanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS =  main.c help.c start_win.c color.c keys.c operations.c render.c fractals.c

CC = gcc


CFLAGS = -Wextra -Wall -Werror 

UNAME_S := $(shell uname -s)

OBJS	= ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Imlx_linux -c $< -o $@

$(NAME): $(OBJS)
ifeq ($(UNAME_S), Linux)
	$(MAKE) -C mlx_linux
	$(MAKE) -C libft
	$(CC) $(OBJS) libft/libft.a mlx_linux/libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
else
	$(MAKE) -C mlx
	$(MAKE) -C libft
	$(CC) $(OBJS) -Lmlx -lmlx libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)
endif

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f libft/*.o
#	rm -f MLX42/src/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
#	rm -f MLX42/libmlx42.a

re: fclean all

.PHONY: all clean fclean re


