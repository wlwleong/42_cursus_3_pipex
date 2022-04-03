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
AR		= ar
ARFLAGS = rcs

FILES	= ft_split.c ft_putstr_fd.c

HEADER	= libft.h

OBJ_DIR	= ../objects
OBJECTS	= $(FILES:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:		%.c $(HEADER)
					@$(CC) $(CFLAGS) -c $< -o $@

RM		= rm -rf

all:	$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADER)
					@$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)
					@echo "\033[33m----Compiling libft----"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
		@$(RM) $(OBJ_DIR)

fclean:	clean
		@$(RM) $(NAME)

re: 	fclean all

.PHONY: clean fclean all re
