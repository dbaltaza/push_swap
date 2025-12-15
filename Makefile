# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 16:56:43 by dbaltaza          #+#    #+#              #
#    Updated: 2025/12/15 14:33:10 by dbaltaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ══════════════════════════════════════════════════════════════════════════════
#                                   PROGRAM
# ══════════════════════════════════════════════════════════════════════════════

NAME		= push_swap

# ══════════════════════════════════════════════════════════════════════════════
#                                   COMPILER
# ══════════════════════════════════════════════════════════════════════════════

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# ══════════════════════════════════════════════════════════════════════════════
#                                 DIRECTORIES
# ══════════════════════════════════════════════════════════════════════════════

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
LIBFT_DIR	= libft

# ══════════════════════════════════════════════════════════════════════════════
#                                   SOURCES
# ══════════════════════════════════════════════════════════════════════════════

# Main
MAIN		= main.c

# Operations
OPS_DIR		= operations
OPS_SRC		= swap_ops.c push_ops.c rotate_ops.c rev_rotate_ops.c

# Sorting
SORT_DIR	= sorting
SORT_SRC	= sort.c turk_sort.c turk_utils.c turk_rotate.c

# Parsing
PARSE_DIR	= parsing
PARSE_SRC	= parse.c

# Utils
UTILS_DIR	= utils
UTILS_SRC	= utils.c stack.c

# All sources with paths
SRCS		= $(addprefix $(SRC_DIR)/, $(MAIN)) \
			  $(addprefix $(SRC_DIR)/$(OPS_DIR)/, $(OPS_SRC)) \
			  $(addprefix $(SRC_DIR)/$(SORT_DIR)/, $(SORT_SRC)) \
			  $(addprefix $(SRC_DIR)/$(PARSE_DIR)/, $(PARSE_SRC)) \
			  $(addprefix $(SRC_DIR)/$(UTILS_DIR)/, $(UTILS_SRC))

# Object files
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ══════════════════════════════════════════════════════════════════════════════
#                                   LIBRARY
# ══════════════════════════════════════════════════════════════════════════════

LIBFT		= $(LIBFT_DIR)/libft.a

# ══════════════════════════════════════════════════════════════════════════════
#                                    FLAGS
# ══════════════════════════════════════════════════════════════════════════════

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)

# ══════════════════════════════════════════════════════════════════════════════
#                                   COLORS
# ══════════════════════════════════════════════════════════════════════════════

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
RED			= \033[0;31m
RESET		= \033[0m

# ══════════════════════════════════════════════════════════════════════════════
#                                    RULES
# ══════════════════════════════════════════════════════════════════════════════

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(LIBFT):
	@echo "$(BLUE)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR) --silent
	@echo "$(GREEN)✓ libft ready$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CYAN)Compiling: $(notdir $<)$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --silent
	@echo "$(YELLOW)✓ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent
	@echo "$(RED)✓ $(NAME) removed$(RESET)"

re: fclean all

# ══════════════════════════════════════════════════════════════════════════════
#                                    UTILS
# ══════════════════════════════════════════════════════════════════════════════

norm:
	@echo "$(BLUE)Checking norminette...$(RESET)"
	@norminette $(SRC_DIR) $(INC_DIR) | grep -E "Error|OK" || true

.PHONY: all clean fclean re norm