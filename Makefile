# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 09:39:40 by bvarea-k          #+#    #+#              #
#    Updated: 2025/08/07 12:18:02 by bvarea-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = MLX42
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)/include -I/usr/local/include

MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -lglfw -lm -ldl -lX11 -lpthread -lXrandr -lXinerama -lXcursor -lXext -lGL

SRC_DIR = src/
OBJ_DIR = obj/

FILES = so_long \
	  copy_map \
	  map_check \
	  map_size \
	  error \
	  load_images \
	  move \
	  utils \
	  check_utils \
	  draw \

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(CYAN)Compiling $(GRAY)$< $(CYAN)to $(BLUE)$@$(DEF_COLOR)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ========================
# RULES
# ========================

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME) $(MLX_FLAGS)
	@echo "$(MAGENTA)So_long fully compiled$(DEF_COLOR)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled successfully$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLX_DIR)/build
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)Cleaned all files and project$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re

