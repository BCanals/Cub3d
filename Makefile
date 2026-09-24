# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 20:56:00 by lartes-s          #+#    #+#              #
#    Updated: 2026/09/24 19:20:19 by lartes-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3d
SRC         = src/render/game.c\
				src/main.c\
				src/setup.c\
				src/render/mlx_entry.c\
				src/render/free_structures.c\


LIBFT_DIR   = ./lib/libft
LIBFT       = $(LIBFT_DIR)/libft.a

LIBMLX_DIR  = ./lib/minilibx-linux
LIBMLX      = $(LIBMLX_DIR)/libmlx.a

OBJ_DIR     = obj
OBJ         = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP         = $(SRC:%.c=$(OBJ_DIR)/%.d)

CC          = cc
CCFLAGS     = -Wall -Wextra -Werror -g -O3 #-fsanitize=address

INCLUDES    = -Iinc -I$(LIBFT_DIR) -I$(LIBMLX_DIR)
LIBS        = -L$(LIBMLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz

all: libft libmlx $(NAME)

-include $(DEP)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

libmlx:
	@$(MAKE) -C $(LIBMLX_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -MMD -MP $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBMLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft libmlx