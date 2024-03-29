# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 05:38:53 by ogokkaya          #+#    #+#              #
#    Updated: 2024/03/27 05:07:18 by ogokkaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	so_long
B_NAME			=	so_long_bonus
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC = src/main.c  src/game_start.c src/map_control_extra.c src/map_control.c src/read_map.c \
		src/walk.c src/utils.c src/utils1.c src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c src/path_finder.c

B_SRC = src_bonus/main_bonus.c  src_bonus/game_start_bonus.c src_bonus/map_control_extra_bonus.c src_bonus/map_control_bonus.c src_bonus/read_map_bonus.c \
		src_bonus/walk_bonus.c src_bonus/utils_bonus.c src_bonus/utils1_bonus.c src_bonus/get_next_line/get_next_line.c src_bonus/get_next_line/get_next_line_utils.c src_bonus/path_finder_bonus.c src_bonus/enemy_walk.c

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit

MINILIBX_PATH	=	minilibx                               

all:				$(NAME)

bonus:				$(B_NAME)

$(NAME): $(OBJ)
					@make -C $(MINILIBX_PATH)
					$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBRARY) -L$(MINILIBX_PATH)

$(B_NAME) : $(B_OBJ)
					@make -C $(MINILIBX_PATH)
					$(CC) $(CFLAGS) -o $(B_NAME) $(B_SRC) $(LIBRARY) -L$(MINILIBX_PATH)

clean:
					@$(RM) $(OBJ)
					@$(RM) $(B_OBJ)
					@make clean -C $(MINILIBX_PATH)

fclean: clean
					
					@$(RM) $(NAME)
					@$(RM) $(B_NAME)

f: fclean
					
re:					fclean all

.PHONY:				all clean fclean re bonus f