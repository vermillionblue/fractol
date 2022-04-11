# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 11:29:43 by danisanc          #+#    #+#              #
#    Updated: 2022/04/11 23:57:34 by danisanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = start.c help.c mandelbrot.c color.c

CC = gcc

CFLAGS = -Wextra -Wall -Werror

#$(CC) ${SRCS} libmlx42.a libglfw3.a libft/libft.a -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(NAME): 
	$(CC) ${SRCS} libft/libft.a  MLX42/libmlx42.a -lm -ldl -lglfw -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re