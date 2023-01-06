# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:59:27 by miandrad          #+#    #+#              #
#    Updated: 2023/01/06 13:52:35 by miandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = cc

RM = rm -f


MAIN_SRC = main.c wlaking.c

GNL_SRC = get_next_line_utils.c get_next_line.c

MAP_SRC = map_checker.c map_cpy.c

MAIN_OBJ = $(MAIN_SRC:.c=.o)

GNL_OBJ = $(GNL_SRC:.c=.o)

MAP_OBJ = $(MAP_SRC:.c=.o)

all:
	cc $(MAIN_SRC) $(addprefix map_checker/,$(MAP_SRC)) $(addprefix get_next_line_100/,$(GNL_SRC)) minilibx-linux/libmlx_Linux.a -lXext -lX11

run:	all
	./a.out map.ber

path:
	cc $(addprefix map_checker/,$(MAP_SRC)) $(addprefix get_next_line_100/,$(GNL_SRC)) && ./a.out map.ber

NAME:
	cc $(MAIN_SRC) $(addprefix map_checker/,$(MAP_SRC)) $(addprefix get_next_line_100/,$(GNL_SRC)) minilibx-linux/libmlx_Linux.a -lXext -lX11


