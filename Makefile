# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 12:43:06 by flvoicu           #+#    #+#              #
#    Updated: 2024/09/16 19:23:46 by flvoicu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =	so_long.c\
		manage_assets.c\
		check_map.c\
		manage_game.c\
		read_ber.c\
		utils.c

OBJ = $(SRC:.c=.o)

CFLAGS := -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm
RM = rm -f
CC := cc

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
