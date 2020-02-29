# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 21:32:32 by kmira             #+#    #+#              #
#    Updated: 2020/02/29 00:39:02 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE_NAMES = \
	tittle_tex \
	play_tex \
	quit_tex \
	play_selected_tex \
	quit_selected_tex \

PNG_FILES = $(addsuffix .png, $(FILE_NAMES))

FT_PNG = $(addprefix con_, $(FILE_NAMES))

TEXT = "a"

all: $(FT_PNG)
	$(foreach name, $(PNG_FILES), python png_to_pixel.py $(name);)

$(FT_PNG):
	touch $(FT_PNG)

clean:
	rm -f $(FT_PNG)
