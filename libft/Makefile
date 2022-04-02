# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 21:14:03 by wlow              #+#    #+#              #
#    Updated: 2021/08/05 13:54:06 by wlow             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

FILES	= ft_split.c ft_putstr_fd.c

OBJ		= $(FILES:.c=.o)

RM		= rm -rf

all:	$(NAME)

$(NAME):
		@$(CC) $(CFLAGS) -c $(FILES)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:	clean
		@$(RM) $(NAME)

re: 	fclean all

.PHONY: clean fclean all re
