# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthebaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/04 17:31:08 by rthebaud          #+#    #+#              #
#    Updated: 2014/06/03 18:32:15 by rthebaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

APPS=\
server\
gfx
APP=client
#vars
DEBUG=1
PROFILE=0
DSRC=src
DBIN=bin
DOBJ=obj
export

all: | $(DBIN)
	@$(foreach i, $(APPS), $(MAKE) -e -C $(i)\
		&& ln -sF ../$(i)/$(DBIN)/$(i) $(DBIN);)
	@ln -sF ../$(APP)/main.py $(DBIN)/$(APP)

$(DBIN):
	@mkdir $@

.PHONY: clean
clean:
	@$(foreach i, $(APPS), $(MAKE) $@ -e -C $(i);)

fclean: clean
	@$(foreach i, $(APPS), $(MAKE) $@ -e -C $(i) && rm -Rf $(DBIN)/$(i);)
	@rm -Rf $(DBIN)/$(APP)
	@rm -Rf $(DBIN)

re: fclean all
