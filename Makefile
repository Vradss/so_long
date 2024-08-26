# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 16:43:41 by vflorez           #+#    #+#              #
#    Updated: 2024/08/26 19:32:35 by vflorez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
RED 	= \033[0;91m
GREEN	= \033[1;92m
YELLOW	= \033[1;93m
BLUE	= \033[0;96m
ORANGE	= \033[0;33m
GRAY	= \033[0;90m

#Main
NAME_PROJECT = so_long

#Sources
SRC_DIR = src
SRC_FILES = \
			src/check_args.c \
			src/read_map.c \
			src/check_maps.c \
			src/error.c \
			src/main.c \
			src/check_path.c \
			src/textures.c

MLX = $(SRC_DIR)/MLX42
LIBFT = $(SRC_DIR)/libft
PRINTF = $(SRC_DIR)/Printf

#Compiler
CC = gcc
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
MLX_FLAGS = -L./$(MLX)/build -lmlx42 -I $(MLX)/include -ldl -lglfw -pthread -lm
LINKFLAGS = -L./$(LIBFT) -lft -L./$(PRINTF) -lftprintf

#Objects
OBJ_DIR = obj
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

#Rules
all: $(NAME_PROJECT)

$(NAME_PROJECT) : $(OBJ_FILES)
	@$(MAKE) -C $(LIBFT) -s
	@$(MAKE) -C $(PRINTF) -s
	@$(CC) $(CFLAGS) -o $(NAME_PROJECT) $(OBJ_FILES) $(MLX_FLAGS) $(LINKFLAGS)
	@echo "$(BLUE) $(NAME_PROJECT) --> Created & compiled 👀$(END)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(MLX)/include -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_FILES)
	@$(MAKE) clean -C $(LIBFT) -s
	@$(MAKE) clean -C $(PRINTF) -s
	@echo "$(GREEN) All .o files deleted 💀💀 $(END)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT) -s
	@$(MAKE) fclean -C $(PRINTF) -s
	@rm -f $(NAME_PROJECT)
	@echo "$(RED) $(NAME_PROJECT) deleted 💀💀 $(END)"

re: fclean all

.PHONY: all clean fclean re
