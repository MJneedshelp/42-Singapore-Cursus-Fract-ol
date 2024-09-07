# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 22:10:59 by mintan            #+#    #+#              #
#    Updated: 2024/09/07 19:40:42 by mintan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler + compile flags
CC = cc
CFLAGS = -Wall -Wextra #-Werror
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -L/usr/lib/X11 -lX11 \
           -lm -lz -Iminilibx-linux -O3

# Definitions
NAME = fractol
SRCDIR = src
LIBDIR = $(SRCDIR)/libft
LIBFT_LIB = $(LIBDIR)/libft.a
FRACTOL_SRCS = $(SRCDIR)/main.c $(SRCDIR)/init_fract.c $(SRCDIR)/utils_hooks.c \
               $(SRCDIR)/utils_win_mgmt.c $(SRCDIR)/utils_transformation.c \
			   $(SRCDIR)/mandelbrot.c $(SRCDIR)/utils_complex.c	#double check later
FRACTOL_OBJ = $(FRACTOL_SRCS:.c=.o)

# Target to make using Make all
all: $(NAME) print_art

# Generate the mandatory programme by compiling the objects with libft.a
$(NAME): $(LIBFT_LIB) $(FRACTOL_OBJ)
	$(CC) $(CFLAGS) $(FRACTOL_OBJ) $(LIBFT_LIB) -o $@ $(MLXFLAGS)

# Build the libft.a library
$(LIBFT_LIB):
	cd $(LIBDIR) && make all

# Generate all the .o files from the .c files for fractol
%.o: %.c
	$(CC) -c $(CFLAGS) $(MLXFLAGS) $< -o $@

# Clear the build files
clean:
	rm -f $(FRACTOL_OBJ)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

# Rule to rebuild the target
re:	fclean all

# Phony targets
.PHONY: all clean re fclean

print_art:
# 	           *                                                  *
#                  ______  _____  _____  ______
#                 /      \/    /  \    \/      \   *
#      *         /  \    / ___/    \___ \    /  \
#               /    \  / /            \ \  /    \           *
#              _\____ \ \ \     /\     / / / ____/_
#             /   __ \ \ \ \    \/*   / / / / __   \
#            /   /  \ \ \ \ \        / / / / /  \   \      *
#      *    /___/    \ \ \ \ \______/ / / / /    \___\
#                     \ \ \ \        / / / /
#  *      /\    __     \ \ \ \______/ / / /     __    /\
#        /  \   \_\    /  \ \        / /  \    /_/   /  \     *
#       /   /         /   /  \      /  \   \         \   \
#      _\  /         /   /    \    /    \   \         \  /_
#     /  \ \--------/   /      \__/      \   \--------/ /  \
#    /    \------------/       /  \       \------------/    \
#   < ------------------------<    >------------------------ >
#    \    /------------\       \__/       /------------\    /
#     \__/ /--------\ * \      /  \      /   /--------\ \__/
#       /  \         \   \    /    \    /   /         /  \
#       \   \    __   \   \  /      \  /   /   __    /   /
#        \  /   /_/    \  / / ______ \ \  /    \_\   \  /
#  *      \/           / / / /      \ \ \ \           \/     *
#            ___      / / / / ______ \ \ \ \       ___
#           \   \    / / / / /      \ \ \ \ \    /   /
#            \   \__/ / / / /        \ \ \ \ \__/   /  *
#             \_ ____/ / / /    /\    \ \ \ \____ _/
#               /     / / /     \/     \ \ \     \
#               \    /  \ \___      ___/ /  \    /
#                \  /    \    \    /    / *  \  /        *
#     *           \______/\____\  /____/\______/
#            *                              *
