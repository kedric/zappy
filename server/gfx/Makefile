# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthebaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/04 17:31:08 by rthebaud          #+#    #+#              #
#    Updated: 2014/06/08 08:25:12 by noumazza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MODULES=\
###ENDMODULES###
#vars
NAME:=gfx
DEBUG=1
PROFILE=0
# Paths
DSRC=src
DBIN=bin
DOBJ=obj
LIBS=ft
DLIB=lib/libft/bin
DINC=inc lib/libft/inc
DMAKE=lib/libft
# Commands & flags
NODBGFLAGS=-Werror
DBGFLAGS=-g3 -DDEBUG
PROFFLAGS=-pg
CFLAGS:=-Wall -Wextra -Wno-attributes
#OPENGL = -lglfw3 -framework Cocoa -framework GLEW -framework OpenGL -framework IOKit -framework CoreVideo
OPENGL1 = `pkg-config --cflags glfw3 glew assimp libpng`
OPENGL2 = `pkg-config --static --libs glfw3 glew assimp libpng`
LDFLAGS:=$(addprefix -L, $(DLIB))
LDLIBS:=$(addprefix -l, $(LIBS))
LNK:=$(CC)
CFLAGS+=$(addprefix -I, $(DINC))
ifeq ($(PROFILE), 1)
	LDFLAGS+= $(PROFFLAGS)
	CFLAGS+= $(PROFFLAGS)
endif
ifeq ($(DEBUG), 1)
	CFLAGS+= $(DBGFLAGS)
else
	CFLAGS+= $(NODBGFLAGS)
endif
# Path & includes
export FILES=
-include $(DSRC)/Makefile
OBJS:=$(addprefix $(DOBJ)/, $(FILES))
$(foreach i, $(MODULES),\
	$(eval -include $(DSRC)/$(i)/Makefile)\
	$(eval OBJS+=$(addprefix $(DOBJ)/$(i)/, $(FILES)))\
	$(eval FILES=))
OBJS:=$(addsuffix .o, $(OBJS))
NAME:=$(DBIN)/$(NAME)

all: makelib $(NAME)

$(NAME): $(OBJS) | $(DBIN)
	gcc $(LDFLAGS) $(OPENGL1) $^ -o $@ $(LDLIBS) $(OPENGL2)

$(DOBJ)/%.o: $(DSRC)/%.c | $(DOBJ)
	gcc -c $(CFLAGS) $(OPENGL1) $< -o $@ $(OPENGL2)

makelib:
	@$(MAKE) -C $(DMAKE)

$(DBIN):
	@mkdir $@

$(DOBJ):
	@mkdir $@
	@$(foreach i, $(MODULES), mkdir $@/$(i);)

opengl_install:
	export PATH=$$HOME/.brew/bin:$$PATH
	brew update
	brew tap homebrew/versions
	brew install --build-bottle --static glfw3
	brew install glew
	brew install assimp

opengl_uninstall:
	brew uninstall glew
	brew uninstall glfw3
	brew uninstall assimp

.PHONY: clean
clean:
	@rm -Rf $(DOBJ)

fclean: clean
	@rm -Rf $(DBIN)

re: fclean all
