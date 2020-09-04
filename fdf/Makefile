# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiego <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 15:32:54 by sdiego            #+#    #+#              #
#    Updated: 2019/10/18 15:33:05 by sdiego           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ./src/create_lists.c ./src/draw2.c ./src/key3.c ./src/read_color.c ./src/color.c ./src/menu.c ./src/key2.c ./src/key.c ./src/xyz.c ./src/view.c ./src/draw.c ./src/move.c ./src/print_err.c ./src/ft_strsplit.c ./src/get_next_line.c ./src/main.c ./src/mem_lst.c ./src/mini_lib.c ./src/mini_lib2.c ./src/read.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -o

INCLUDES = ./includes

HEADERS = $(INCLUDES)/errors.h $(INCLUDES)/FdF.h $(INCLUDES)/get_next_line.h $(INCLUDES)/mem_lst.h

LDLIBS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@make -C ./minilibx_macos/
	@gcc $(CFLAGS) $(NAME) $(OBJ) -I /usr/local/include  -I$(INCLUDES) -L ./minilibx_macos/ $(LDLIBS)
	@echo "Compiling FdF"

.c.o:
	@gcc $(CFLAGS) -I./$(INCLUDES) -c $< -o $@

clean:
	@make clean -C ./minilibx_macos/
	@/bin/rm -f $(OBJ)
	@echo "Clear files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Fclear files"

re: fclean all
