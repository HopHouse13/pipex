# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbret <pbret@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 17:02:37 by ubuntu            #+#    #+#              #
#    Updated: 2025/01/15 18:36:50 by pbret            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
SRCS_DIR	= srcs
OBJ_DIR 	= obj_$(NAME)
SRCS		= srcs/main.c \
			srcs/initialisation.c \
			srcs/split.c \
			srcs/messages_errors_handle.c \
			srcs/tool.c \
			srcs/pipex.c
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
# LIBFT_ARCHIVE = ./libft/libft.a
CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -ggdb -I$(SRCS_DIR)

all:		$(NAME)

$(NAME):	$(OBJS) 
			$(CC) $(OBJS) -o $(NAME)
			@echo "\033[32m""Compilation de $(NAME) est terminée!""\033[0m"

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@
			
# ${LIBFT_ARCHIVE}:
# 			make -sC ./libft
	
clean:
			$(RM) $(OBJ_DIR)
			@echo "\033[36m""Répertoire $(OBJ_DIR) supprimé.""\033[0m"

fclean:		clean
			$(RM) $(NAME)
			@echo "\033[36m""Exécutable $(NAME) supprimé.""\033[0m"

re:			fclean all

.PHONY: all clean fclean re
