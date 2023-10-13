# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:04:54 by aqueiroz          #+#    #+#              #
#    Updated: 2023/10/12 22:09:51 by aqueiroz         ###   ########.fr        #
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

NAME = miniRT

SRC_PATH = srcs
LIB_PATH = libs
PATH_INC = includes

FILES  = 	minirt

SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

# FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFLAGS = -Llibs/MLX42/build -lmlx42 -Iinclude -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(purple)Compiling project...$(reset)"
	@echo "$(purple)Compiling Libft...$(reset)"
	@$(MAKE) -C libs/libft > /dev/null && \
	echo "$(purple)Compiling MLX42...$(reset)" 
	@cmake -B libs/MLX42/build -S libs/MLX42  > /dev/null && \
	echo "$(purple)Building MLX42...$(reset)" && \
	cmake --build libs/MLX42/build -j4 > /dev/null && \
	$(CC) $(OBJS) -o $@ -Llibs/MLX42/build -lmlx42 $(LIBFLAGS) && \
	echo "$(purple)Project compiled. Run './$(NAME)' to start.$(reset)"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(PATH_INC) -c $< -o $@

valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes \
	--leak-check=full --show-leak-kinds=all --quiet ./miniRT
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C libs/libft clean > /dev/null
	@rm -rf libs/MLX42/build
	$(info $(yellow)All object files were removed.$(reset))

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libs/libft fclean > /dev/null
	$(info $(yellow)Executables files were removed.$(reset))

re: fclean all
	
.PHONY: all color clean fclean re valgrind