# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lartes-s <lartes-s@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 20:56:00 by lartes-s          #+#    #+#              #
#    Updated: 2025/09/18 20:56:03 by lartes-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = 

LIBFT_DIR = ./lib/libft/
LIBMLX	:= ./lib/minilibx-linux

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