# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:13:19 by kmira             #+#    #+#              #
#    Updated: 2020/03/01 17:330:58 by kmira            ###   ########.fr        #
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

LEVEL_FILES = \
	level_main_menu \
	level_first_level \

ASSET_FILES = \
	assets_play_button \
	assets_player \
	assets_tittle \
	assets_wall \
	assets_wall2 \

FILES = \
	animations \
	assets \
	ft_curses \
	initialization \
	main \
	map \
	meta_state \
	player \
	texture_render \
	window_render \
	wolf_destroy \

SRCS = \
	$(addsuffix .c, $(addprefix srcs/, $(FILES))) \
	$(addsuffix .c, $(addprefix srcs/levels/, $(LEVEL_FILES))) \
	$(addsuffix .c, $(addprefix srcs/assets/, $(ASSET_FILES)))

OBJS = \
	$(addsuffix .o, $(FILES)) \
	$(addsuffix .o, $(LEVEL_FILES)) \
	$(addsuffix .o, $(ASSET_FILES))

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

save: clean
	git add .
	git commit -m "$(MSG)"
	git pull
	git push

quick: re
	make clean

play: quick
	clear
	./$(NAME)

