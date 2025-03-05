# Compiler and flags
CC     = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
GNL_DIR = gnl
INC_DIR = inc
OBJ_DIR = obj
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX_DIR = minilibx-linux  

# Libraries
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINTF_FLAGS = -L$(PRINTF_DIR) -lftprintf

# Source files
SRC_FILES = flood_fill.c hooks.c map_utils.c map.c mlx_utils.c \
            player_move.c render.c so_long.c
GNL_FILES = get_next_line.c get_next_line_utils.c

# Object files
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) \
      $(patsubst %.c, $(OBJ_DIR)/%.o, $(GNL_FILES))

# Executable
NAME = so_long

# Rules
all: $(LIBFT) $(PRINTF) $(NAME)

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compile ft_printf
$(PRINTF):
	make -C $(PRINTF_DIR)

# Create object directory if not exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(GNL_DIR) -c $< -o $@

# Compile GNL files
$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(GNL_DIR) -c $< -o $@

# Build the executable
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

# Rebuild project
re: fclean all

.PHONY: all clean fclean re
