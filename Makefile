# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/11 15:22:50 by thomkim           #+#    #+#              #
#    Updated: 2018/04/04 13:46:18 by thomkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  ft_tetriminos.c \
	  ft_board.c \
	  ft_check_board.c \
	  ft_err_msg.c \
	  ft_fillit.c \
	  ft_check_line.c \
	  ft_no_line.c \
	  ft_check_connect.c \
	  ft_single_line.c \

LIBDIR = libs/Libft
OBJ = $(SRC:.c=.o)
LIBS = $(LIBDIR)/libft.a
HEADER = -I $(LIBDIR)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $(HEADER) $^ -o $@

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a

re: fclean all

.PHONY: all fclean clean re
