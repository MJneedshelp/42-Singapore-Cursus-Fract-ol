# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 22:10:59 by mintan            #+#    #+#              #
#    Updated: 2024/09/15 16:06:39 by mintan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler + compile flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
LIBFLAGS = -Lminilibx-linux -lmlx -lXext -L/usr/lib/X11 -lX11 -lm -lz
INC = -Iminilibx-linux

# Definitions
NAME = fractol
SRCDIR = src
LIBDIR = $(SRCDIR)/libft
LIBFT_LIB = $(LIBDIR)/libft.a


MLXDIR = minilibx-linux/
MLXREPO = https://github.com/42Paris/minilibx-linux.git
MLX_LIB = $(MLXDIR)/libmlx_Linux.a



FRACTOL_SRCS = $(SRCDIR)/main.c $(SRCDIR)/init_fract.c \
               $(SRCDIR)/init_events.c $(SRCDIR)/init_checks.c \
			   $(SRCDIR)/utils_complex.c $(SRCDIR)/draw_fractal.c
FRACTOL_OBJ = $(FRACTOL_SRCS:.c=.o)

# Target to make using Make all
all: $(NAME) print_art

# Generate the mandatory programme by compiling the objects with libft.a
# and libmlx_Linux.a
$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(FRACTOL_OBJ)
	$(CC) $(CFLAGS) $(FRACTOL_OBJ) $(LIBFT_LIB) $(LIBFLAGS) -o $@

# Build the libft.a library
$(LIBFT_LIB):
	cd $(LIBDIR) && make all

# Git clone and build MLX
$(MLX_LIB):
	if [ ! -d $(MLXDIR) ] || [ ! -f $(MLX_LIB) ]; then \
		echo "mlx directory or mlx lib not found"; \
		echo "Clear directory, git clone, then remake mlx library"; \
		rm -rf $(MLXDIR); \
		git clone $(MLXREPO) $(MLXDIR); \
		cd $(MLXDIR) && make; \
	else \
		echo "mlx library present already"; \
	fi

# Generate all the .o files from the .c files for fractol
%.o: %.c
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

# Clear the build files
clean:
	rm -f $(FRACTOL_OBJ)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean
	rm -rf $(MLXDIR)

# Rule to rebuild the target
re:	fclean all

print_art:
	@echo "      /\\"
	@echo " __   \\/   __"
	@echo " \\_\\_\\/\\/_/_/"
	@echo "   _\\_\\/_/_"
	@echo "  __/_/\\_\\__"
	@echo " /_/ /\\/\\ \\_\\"
	@echo "      /\\"
	@echo "      \\/"


# Phony targets
.PHONY: all clean re fclean print_art
