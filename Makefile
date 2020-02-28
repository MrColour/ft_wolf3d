# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:13:19 by kmira             #+#    #+#              #
#    Updated: 2020/02/28 03:39:42 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror
# -Wno-deprecated-declarations
LIB = lib/libglfw3.a
LIBFT = srcs/libft/libft.a
INCS = -I includes/
BINARY_DIR = bin/

OPENGL = \
		-framework Cocoa \
		-framework OpenGL \
		-framework IOKit

FILES = \
	assets \
	initialization \
	level_first_level \
	level_main_menu \
	main \
	meta_state \
	texture_render \
	window_render \
	wolf_destroy \

SRCS = $(addsuffix .c, $(addprefix srcs/, $(FILES)))
OBJS = $(addsuffix .o, $(FILES))

all: $(LIBFT) $(OBJS)
	gcc -o $(NAME) $(FLAGS) $(INCS) $(OPENGL) $(LIB) $(LIBFT) $(OBJS)

$(LIBFT):
	make -C srcs/libft/

$(OBJS):
	gcc -c $(FLAGS) $(INCS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
# make fclean -C srcs/libft/

re: fclean all

save: fclean
	git add .
	git commit -m "$(MSG)"
	git push

quick: re
	make clean

play: quick
	./$(NAME)
