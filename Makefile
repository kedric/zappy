#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 22:10:13 by jmancero          #+#    #+#              #
#    Updated: 2014/04/30 00:29:18 by jmancero         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_C		=	client

SRC			=	src/

INCDIR 		=	includes/

SRC_C		=	$(SRC)main.cpp\
				$(SRC)serveur/tcp_connect.cpp\
				$(SRC)serveur/receve.cpp\
				$(SRC)game/game.cpp\
				$(SRC)map/map.cpp\
				$(SRC)player/player.cpp\

OBJ_C		=	$(SRC_C:.cpp=.o)


CC 			=	g++

CFLAG 		= -g -Wall -Wextra -Werror

RED = \033[33;31m
BLUE = \033[33;34m
GREEN = \033[33;32m
RESET = \033[0m

.PHONY: all re fclean

all: $(NAME_C)


$(NAME_C): $(OBJ_C)
		@$(CC) -o $(NAME_C) $(CFLAG) $^ -lncurses
		@echo "[$(GREEN)Compilation $(BLUE)$(NAME_C) $(GREEN)ok$(RESET)]"

%.o: %.c
		$(CC) -c -g -o $@ $(CFLAG) $^

clean:
	@rm -f $(OBJ_C)
	@echo "[$(RED)Supression des .o de $(BLUE)$(NAME_C) $(GREEN)ok$(RESET)]"

fclean: clean
		@rm -f $(NAME_C)
		@echo "[$(RED)Supression de $(BLUE)$(NAME_C) $(GREEN)ok$(RESET)]"

re: fclean all
