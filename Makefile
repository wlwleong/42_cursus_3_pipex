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

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	ft_get_infile.c ft_get_outfile.c ft_get_cmd_path.c error.c
SOURCES_FILES	+=	ft_fill_cmd.c ft_free_command.c main.c
BONUS_FILES		=	ft_check_infile_bonus.c ft_check_outfile_bonus.c
BONUS_FILES		+=	ft_get_cmd_path_bonus.c error_bonus.c pipex_bonus.c
BONUS_FILES		+=	ft_fill_cmd_bonus.c ft_free_command_bonus.c main_bonus.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus
HEADER_DIR		=	includes
OBJ_DIR			=	objects

HEADER			=	$(HEADER_DIR)/pipex.h
BONUS_HEADER	=	$(HEADER_DIR)/pipex_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_SOURCES	=	$(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJECTS	=	$(BONUS_SOURCES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	pipex
BONUS_NAME		=	pipex_bonus
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -ggdb3
RM				=	rm -rf

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c $(BONUS_HEADER)
					@$(CC) $(CFLAGS) -c $< -o $@

all: 				$(NAME)

bonus:				$(BONUS_NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJECTS) $(HEADER)
					@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

$(BONUS_NAME):		$(LIBFT) $(OBJ_DIR) $(BONUS_OBJECTS) $(BONUS_HEADER)
					@$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -o $(NAME)
					@cp $(NAME) $(BONUS_NAME)
					@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

$(LIBFT):
					@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean
					@$(RM) $(OBJ_DIR)

fclean: 			clean
					@$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean
					@$(RM) $(NAME) $(BONUS_NAME)
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:					fclean all

.PHONY:				all clean fclean re libft bonus
