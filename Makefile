# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 11:29:43 by danisanc          #+#    #+#              #
#    Updated: 2022/04/18 22:35:12 by danisanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = start.c help.c mandelbrot.c color.c

CC = gcc

CFLAGS = -Wextra -Wall -Werror 

UNAME_S := $(shell uname -s)

#$(CC) ${SRCS} libmlx42.a libglfw3.a libft/libft.a -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

OBJS	= ${SRCS:.c=.o}

%.o: %.c
	$(CC)  -Imlx -c $< -o $@

$(NAME): $(OBJS)
#	$(MAKE) -C MLX42 && $(MAKE) -C libft
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)



all: $(NAME)

clean:
	rm -f $(OBJS)
#	rm -f libft/*.o
#	rm -f MLX42/src/*.o

fclean: clean
	rm -f $(NAME)
#	rm -f libft/libft.a
#	rm -f MLX42/libmlx42.a

re: fclean all

.PHONY: all clean fclean re


