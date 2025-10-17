# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025/08/07 09:36:24 by mnaouss           #+#    #+#             #
#   Updated: 2025/08/07 09:36:24 by mnaouss          ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Source files
SRCS = main.c \
       check_valid_map.c \
       check_valid_path.c \
       read_map.c \
       utils.c \
	   render_map.c\
	   movements.c\
	   utils2.c\
       get_next_line/get_next_line.c \
	   check_if_over.c\
       get_next_line/get_next_line_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = so_long.h get_next_line/get_next_line.h

# Default target
all: $(NAME)

# Build the executable
$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

# Note: Do NOT pass CFLAGS to minilibx. It uses its own Makefile and flags.
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re 