# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:59:27 by miandrad          #+#    #+#              #
#    Updated: 2023/01/04 18:15:55 by miandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = cc

RM = rm -f

FT_MAP = map_checker.c 

GNL_SRC = get_next_line_utils.c get_next_line.c

GNL_OBJ = $(GNL_SRC:.c=.o)

all:

	cc main.c minilibx-linux/libmlx_Linux.a -lXext -lX11

run:	all
	./a.out

map:
	cc map_checker.c $(addprefix get_next_line_100/,$(GNL_SRC)) && ./a.out

NAME:	#$(addprefix map_checker/,$(LB_MAP)) $(FT_READER) $(SRC_LONG)


