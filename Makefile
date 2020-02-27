# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:13:19 by kmira             #+#    #+#              #
#    Updated: 2020/02/26 18:24:01 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror
# -Wno-deprecated-declarations
LIB = libglfw3.a
INCS = -I includes/
BINARY_DIR = bin/

OPENGL = \
		-framework Cocoa \
		-framework OpenGL \
		-framework IOKit

FILES = \
	initialization \
	main \

SRCS = $(addsuffix .c, $(addprefix srcs/, $(FILES)))
OBJS = $(addsuffix .o, $(FILES))

all: $(OBJS)
	gcc -o $(NAME) $(FLAGS) $(INCS) $(OPENGL) $(LIB) $(OBJS)

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
