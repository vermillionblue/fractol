#target: dependencies
#	action

#targets ...: target-pattern: prereq-patterns ...
#   commands

NAME = fractol

SRCS = start.c help.c mandelbrot.c

CC = gcc

CFLAGS = -Werror -Wextra -Wall 

$(NAME): 
	$(CC) ${SRCS} libmlx42.a libglfw3.a libft/libft.a -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re