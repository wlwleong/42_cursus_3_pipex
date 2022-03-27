# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 19:03:58 by wlwleong          #+#    #+#              #
#    Updated: 2022/02/20 01:10:12 by wlwleong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -ggdb3

FILES = main.c ft_split.c ft_get_cmd_path.c ft_fill_cmd.c ft_get_infile.c ft_get_outfile.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(FILES)

clean:
	rm -rf $(OBJ)
	echo "clean: Objects cleaned."

fclean: clean
	rm -rf $(NAME)
	echo "fclean(ed)"

re: fclean all

.PHONY: clean fclean all re
