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

SOURCES_FILES	=	ft_split.c ft_get_infile.c ft_get_outfile.c ft_get_cmd_path.c
SOURCES_FILES	+=	ft_fill_cmd.c ft_free_command.c error.c main.c

SOURCES_DIR		=	sources
HEADER_DIR		=	includes
OBJ_DIR			=	objects

HEADER			=	$(HEADER_DIR)/pipex.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	pipex
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -ggdb3
RM				=	rm -rf

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					@$(CC) $(CFLAGS) -c $< -o $@

all: 				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADER)
					@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@$(RM) $(OBJ_DIR)

fclean: 			clean
					@$(RM) $(NAME)

re:					fclean all

.PHONY:				clean fclean all re
