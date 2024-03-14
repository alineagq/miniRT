# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 00:31:29 by fsuomins          #+#    #+#              #
#    Updated: 2024/03/13 20:24:05 by aqueiroz         ###   ########.fr        #
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
	@make -s _color-test

_color-test:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))

# PATHS

SRC_PATH = .
TEST_PATH = tests
PATH_INC = ./

# FILES

NAME = libvector.a
FILES = vector_add vector_create vector_cross vector_diff vector_div_self \
		vector_div vector_dot vector_lenght_squared vector_lenght \
		vector_mult vector_mult_self vector_negate_self vector_product \
		vector_project_onto_plane vector_reflect vector_subtr \
		vector_sum_self vector_sum vector_unit
		
SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(FILES)))
OBJS := ${SRCS:.c=.o}

# FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror

# TARGETS

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

valgrind:
	valgrind --track-origins=yes --error-exitcode=42 --leak-check=full --show-leak-kinds=all --quiet ./test

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re