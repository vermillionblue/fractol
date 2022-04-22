# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 11:29:43 by danisanc          #+#    #+#              #
#    Updated: 2022/04/22 22:45:17 by danisanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS =  start.c help.c mandelbrot.c color.c

CC = gcc

CFLAGS = -Wextra -Wall -Werror 

UNAME_S := $(shell uname -s)

# $(CC) ${SRCS} libmlx42.a libglfw3.a libft/libft.a -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

OBJS	= ${SRCS:.c=.o}

# %.o: %.c
# 	$(CC)  -Imlx -c $< -o $@

%.o: %.c
	$(CC) -Imlx_linux -c $< -o $@


$(NAME): $(OBJS)
#	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11  -lm -lz -o $(NAME)
	$(CC) $(OBJS) mlx_linux/libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


# $(NAME): $(OBJS)
# 	$(MAKE) -C MLX42 && $(MAKE) -C libft
# 	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


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


