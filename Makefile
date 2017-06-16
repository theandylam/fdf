# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: alam <theandylam@gmail.com>                +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 14:29:56 by alam              #+#    #+#              #
#    Updated: 2017/03/10 14:29:58 by alam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILES = fdf.c color.c draw.c key.c load_file.c map.c vector.c v_rotate.c hooks.c \
		image.c

INCLUDES = -I libft -I minilibx

LIBRARY = -L libft -lft -L minilibx -lmlx

FRAMEWORK = -framework OpenGL -framework AppKit

OBJECTS = $(FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME): libft minilibx $(OBJECTS)
	gcc $(CFLAGS) $(INCLUDES) $(LIBRARY) $(FRAMEWORK) -o $(NAME) $(OBJECTS)

libft:
	make -C libft/ all

minilibx:
	make -C minilibx/ 

%.o: %.c
	@gcc $(CFLAGS) $(INCLUDES) -o $@ -c $^

clean:
	make -C libft/ clean
	make -C minilibx/ clean
	rm -f $(OBJECTS)

fclean: clean
	make -C libft/ fclean
	make -C minilibx/ clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft minilibx
