# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 16:43:41 by vflorez           #+#    #+#              #
#    Updated: 2024/08/09 21:11:08 by vflorez          ###   ########.fr        #
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
SRC_FILES = main.c\

MLX = $(SRC_DIR)/MLX42/build/libmlx42.a
LIBFT = $(SRC_DIR)/libft
PRINTF = $(SRC_DIR)/Printf

GNL = $(SRC_DIR)/gnl 
GNL_FILES = get_next_line.c \
			get_next_line_utils.c \

#All Sources
SRCS  = $(addprefix $(SRC_DIR)/, $(SRC_FILES) $(GNL_FILES))

#Compiler
CC = gcc -g
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
# LINKFLAGS = -L./$(LIBFT) -lft -L./$(PRINTF) -lftprintf
LINKFLAGS = -LMLX42/build/libmlx42.a -lmlx42 -I MLX42/include -ldl -lglfw -pthread -lm

#Objects
OBJ_DIR = obj
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJ_GNL_DIR = $(OBJ_DIR)/gnl


#Rules
all: $(NAME_PROJECT)

$(NAME_PROJECT) : $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $(NAME_PROJECT) $(OBJ_FILES) $(LINKFLAGS)
	@echo "$(BLUE) $(NAME_PROJECT) --> Created & compiled 👀$(END)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I MLX42/include -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_FILES)
	@echo "$(GREEN) All .o files deleted 💀💀 $(END)"

fclean: clean
	@rm -f $(NAME_PROJECT)
	@echo "$(BLUE) $(NAME_PROJECT) deleted 💀💀 $(END)"

re: fclean all

.PHONY: all clean fclean re
