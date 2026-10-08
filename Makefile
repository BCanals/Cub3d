# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 20:56:00 by lartes-s          #+#    #+#              #
#    Updated: 2026/10/08 20:27:15 by becanals         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d
SRC		=	src/main.c             \
			src/parser/parser.c     \
			src/parser/scene_read.c  \
			src/parser/parser_utils.c \
			src/parser/get_next_line.c \
			src/parser/parse_map.c      \
			src/parser/parse_map_utils.c \
			src/parser/flood_fill.c       \
			src/render/render.c            \
			src/render/render_utils.c       \
			src/render/mlx_entry.c           \
			src/render/key_hooks.c            \
			src/render/operations.c            \
			src/setup_clean/errors_utils.c      \
			src/setup_clean/loaders.c            \
			src/setup_clean/cleaners.c 

LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBMLX	:= ./lib/MLX42

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(SRC:%.c=$(OBJ_DIR)/%.d)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g -Wunreachable-code -O3 -fsanitize=address

INCLUDES = -I$(LIBFT_DIR) -I$(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: libft libmlx $(NAME)

-include $(DEP)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)
	
libft:
	$(MAKE) -C $(LIBFT_DIR)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)/%.o: %.c | Makefile $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -MMD -MP $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft libmlx
