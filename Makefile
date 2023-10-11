# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:04:54 by aqueiroz          #+#    #+#              #
#    Updated: 2023/10/11 14:48:19 by aqueiroz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

## COLORS DEFINITIONS

red:=$(shell tput setaf 1)
green:=$(shell tput setaf 2)
yellow:=$(shell tput setaf 3)
blue:=$(shell tput setaf 4)
purple:=$(shell tput setaf 5)
cyan:=$(shell tput setaf 6)
white:=$(shell tput setaf 7)
reset:=$(shell tput sgr0)

color:
	@$(MAKE) -s _color-test

_color-test:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))

# MANDATORY FILES

NAME = minirt

SRC_PATH = srcs
LIB_PATH = libs
PATH_INC = includes

FILES  = 	minirt

SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

# FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFLAGS = libs/MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJS)
	# @$(MAKE) -s -k -C $(LIB_PATH)
	@$(CC) $(OBJS) $(INCLUDE) $(LIBFLAGS) -o $@
	$(info $(purple)Project compiled. Run './$(NAME)' to start.$(reset))

valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes \
	--leak-check=full --show-leak-kinds=all --quiet ./minirt
clean:
	@rm -f $(OBJS)
	# @$(MAKE) -C $(LIB_PATH) --silent clean
	$(info $(yellow)All object files were removed.$(reset))

fclean: clean
	@rm -f $(NAME)
	# @$(MAKE) -C $(LIB_PATH) --silent fclean
	$(info $(yellow)Executables files were removed.$(reset))

re: fclean all
	
.PHONY: all color clean fclean re valgrind