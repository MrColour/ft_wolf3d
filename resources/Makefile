# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 21:32:32 by kmira             #+#    #+#              #
#    Updated: 2020/03/01 12:27:53 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE_NAMES = \
		play_active \
		play_deactive \
		quit_active \
		quit_deactive \
		tittle \
		wall \

PNG_FILES = $(addsuffix .png, $(addprefix png_files/, $(FILE_NAMES)))

FT_PNG = $(addsuffix .ft_png, $(addprefix ft_png_files/, $(FILE_NAMES)))

TEXT = "a"

all: $(FT_PNG)
	$(foreach name, $(PNG_FILES), python png_to_pixel.py $(name);)

$(FT_PNG):
	touch $(FT_PNG)

clean:
	rm -f $(FT_PNG)
