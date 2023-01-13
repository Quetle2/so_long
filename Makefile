# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:59:27 by miandrad          #+#    #+#              #
#    Updated: 2023/01/13 14:51:20 by miandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MAIN_SRC = main.c wlaking.c images.c

GNL_SRC = get_next_line_utils.c get_next_line.c

MAP_SRC = map_checker.c map_cpy.c

MAIN_OBJ = $(MAIN_SRC:.c=.o)

GNL_OBJ = $(GNL_SRC:.c=.o)

MAP_OBJ = $(MAP_SRC:.c=.o)

all: $(NAME)

run:	all
	./a.out map.ber

valgrind:	all
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out map.ber

clean:
	@$(RM) a.out
	

$(NAME):
	$(CC) -g $(CFLAGS) $(MAIN_SRC) $(addprefix map_checker/,$(MAP_SRC)) $(addprefix get_next_line_100/,$(GNL_SRC)) ft_printf_100/libftprintf.a minilibx-linux/libmlx_Linux.a -lXext -lX11


