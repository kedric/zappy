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


NAME_S		=	serveur

NAME_C		=	client

SRC			=	src/

INCDIR 		=	includes/

SRC_S		=	$(SRC)serveur/main.c \
				$(SRC)serveur/parse_av.c \
				$(SRC)serveur/use_av.c \
				$(SRC)serveur/init_map.c \
				$(SRC)serveur/serveur.c \
				$(SRC)serveur/loop.c \

OBJ_S		=	$(SRC_S:.c=.o)

SRC_C		=

OBJ_C		=	$(SRC_C:.c=.o)

LIBDIR 		=	libft/

LIB 		=	$(LIBDIR)libft.a

LIB_COMP 	=	-L ./$(LIBDIR) -lft

CC 			=	gcc

FLAG 		=	-I $(INCDIR) -g -Wall -Wextra -Werror

RED = \033[33;31m
BLUE = \033[33;34m
GREEN = \033[33;32m
RESET = \033[0m

.PHONY: all re fclean

all: $(NAME_S) $(NAME_C)

$(LIB):
		@$(MAKE) -C $(LIBDIR)

$(NAME_S): $(LIB) $(OBJ_S)
		@$(CC) -o $(NAME_S) $(FLAG) $^ $(LIB_COMP)
		@rm -f $(DEP).gch
		@echo "[$(GREEN)Compilation $(BLUE)$(NAME_S) $(GREEN)ok$(RESET)]"


$(NAME_C): $(LIB) $(OBJ_C)
		@$(CC) -o $(NAME_C) $(FLAG) $^ $(LIB_COMP)
		@rm -f $(DEP).gch
		@echo "[$(GREEN)Compilation $(BLUE)$(NAME_C) $(GREEN)ok$(RESET)]"

%.o: %.c
		@$(CC) -c -o $@ $(FLAG) $^

clean:
	@cd $(LIBDIR) && $(MAKE) $@
	@rm -f $(OBJ_S)
	@rm -f $(OBJ_C)
	@echo "[$(RED)Supression des .o de $(BLUE)$(NAME_S) $(GREEN)ok$(RESET)]"
	@echo "[$(RED)Supression des .o de $(BLUE)$(NAME_C) $(GREEN)ok$(RESET)]"

fclean: clean
		@cd $(LIBDIR) && $(MAKE) $@
		@rm -f $(NAME_S)
		@rm -f $(NAME_C)
		@echo "[$(RED)Supression de $(BLUE)$(NAME_S) $(GREEN)ok$(RESET)]"
		@echo "[$(RED)Supression de $(BLUE)$(NAME_C) $(GREEN)ok$(RESET)]"

re: fclean all
