# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 17:02:37 by ubuntu            #+#    #+#              #
#    Updated: 2025/01/18 19:12:53 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
SRCS_DIR	= srcs
OBJ_DIR 	= obj_$(NAME)
SRCS		= srcs/main.c \
			srcs/initialisation_struct.c \
			srcs/errors_messages.c \
			srcs/handle_cmds.c \
			srcs/handle_paths.c \
			srcs/handle_files.c \
			srcs/exec.c \
			srcs/free_and_close.c
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -ggdb -I$(SRCS_DIR)
LIBFT_AR	= ./includes/libft/libft.a
PRINTF_AR	= ./includes/printf/printf.a

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@
			
all:		$(NAME)
			
$(NAME):	$(OBJS) $(LIBFT_AR) $(PRINTF_AR)
			$(CC) $(OBJS) $(LIBFT_AR) $(PRINTF_AR) -o $(NAME)
			@echo "\033[32m""Compilation de $(NAME) est terminée!""\033[0m"

$(LIBFT_AR):
			make -sC ./includes/libft

$(PRINTF_AR):
			make -sC ./includes/printf

clean:
			make clean -sC ./includes/libft
			make clean -sC ./includes/printf
			$(RM) $(OBJ_DIR)
			@echo "\033[36m""Répertoire $(OBJ_DIR) supprimé.""\033[0m"

fclean:		clean
			$(RM) $(LIBFT_AR)
			$(RM) $(PRINTF_AR)
			$(RM) $(NAME)
			@echo "\033[36m""Exécutable $(NAME) supprimé.""\033[0m"

re:			fclean 	all

.PHONY: all clean fclean re
