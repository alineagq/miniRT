# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:04:54 by aqueiroz          #+#    #+#              #
#    Updated: 2023/11/10 01:02:12 by aqueiroz         ###   ########.fr        #
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

FILES	= main

FILES 	+= matrix/matrix

FILES 	+= vector/vector vector/scalar vector/properties

FILES 	+= validation/validate_ambient validation/validate_camera \
			validation/validate_cylinder validation/validate_light \
			validation/validate_plane validation/validate_scene \
			validation/validate_sphere validation/validate_color

FILES 	+= window/window

FILES 	+= render/aabb render/construct render/render render/intersect\
			render/aabb_test render/sphere 
			

FILES 	+= utils/data utils/objects utils/exit_error

SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

# FLAGS

CC = clang
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -Llibs/MLX42/build -Llibs/libft -lmlx42 -lft -Iinclude -ldl -lglfw -pthread -lm
VALGRIND_ARGS = --trace-children=yes --track-origins=yes  --suppressions=mini.supp \
	--leak-check=full --show-leak-kinds=all --quiet

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(purple)Compiling project...$(reset)"
	@echo "$(purple)Compiling Libft...$(reset)"
	@$(MAKE) -C libs/libft > /dev/null && \
	echo "$(purple)Compiling MLX42...$(reset)" 
	@cmake -B libs/MLX42/build -S libs/MLX42  > /dev/null && \
	echo "$(purple)Building MLX42...$(reset)" && \
	cmake --build libs/MLX42/build -j4 > /dev/null && \
	$(CC) $(OBJS) -o $@ $(LIBFLAGS) && \
	echo "$(purple)Project compiled. Run './$(NAME)' to start.$(reset)"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(PATH_INC) -c $< -o $@
    
valgrind: $(NAME)
	valgrind $(VALGRIND_ARGS) ./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

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
	
.PHONY: all color clean fclean re valgrind icon