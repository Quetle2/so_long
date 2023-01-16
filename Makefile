# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:59:27 by miandrad          #+#    #+#              #
#    Updated: 2023/01/16 11:16:48 by miandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# animation idea:
#
# using lists and the map checker. Look for the block with animation, 
# change the sprite with every call of function render iterating the list.
# PS: need a way to return to the top of the list after wich cycle of sprites.


NAME = so_long

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

ANM_SRC = collectibles.c

MAIN_SRC = main.c wlaking.c images.c

GNL_SRC = get_next_line_utils.c get_next_line.c

MAP_SRC = map_checker.c map_cpy.c

all: $(NAME)

run:	all
	@./so_long map.ber

valgrind:	all
	@valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map.ber

clean:
	@make clean -s -C ft_printf_100
	@make clean -s -C minilibx-linux

fclean:
	@make fclean -s -C ft_printf_100
	@$(RM) so_long

re: fclean all

$(NAME): 
	@make -s -C ft_printf_100
	@make -s -C minilibx-linux
	@$(CC) -g $(CFLAGS) $(MAIN_SRC) $(addprefix animations/,$(ANM_SRC)) $(addprefix map_checker/,$(MAP_SRC)) $(addprefix get_next_line_100/,$(GNL_SRC)) ft_printf_100/libftprintf.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)
