# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 22:10:59 by mintan            #+#    #+#              #
#    Updated: 2024/09/15 09:10:44 by mintan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler + compile flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -L/usr/lib/X11 -lX11 -lm -lz -O3\
           -Iminilibx-linux

# Definitions
NAME = fractol
SRCDIR = src
LIBDIR = $(SRCDIR)/libft
LIBFT_LIB = $(LIBDIR)/libft.a
FRACTOL_SRCS = $(SRCDIR)/main.c $(SRCDIR)/init_fract.c \
               $(SRCDIR)/init_events.c $(SRCDIR)/init_checks.c \
			   $(SRCDIR)/utils_complex.c $(SRCDIR)/draw_fractal.c	#double check later
FRACTOL_OBJ = $(FRACTOL_SRCS:.c=.o)

TESTDIR = testfolder
TESTRREPO = https://github.com/42Paris/minilibx-linux.git

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

# Test Rule to git clone
test:
	git clone $(TESTRREPO) $(TESTDIR)


# Phony targets
.PHONY: all clean re fclean

print_art:
	@echo "      /\\"
	@echo " __   \\/   __"
	@echo " \\_\\_\\/\\/_/_/"
	@echo "   _\\_\\/_/_"
	@echo "  __/_/\\_\\__"
	@echo " /_/ /\\/\\ \\_\\"
	@echo "      /\\"
	@echo "      \\/"
