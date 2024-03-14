# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:04:54 by aqueiroz          #+#    #+#              #
#    Updated: 2024/03/14 13:36:04 by aqueiroz         ###   ########.fr        #
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

FILES	+= intersect/basics intersect/calculate_instersection

FILES	+= matrix/identity_matrix matrix/inverse_matrix matrix/multiply_matrix \
		matrix/convertions matrix/utils \
		matrix/rotate matrix/transform matrix/transpose_matrix

FILES	+= object/add_object object/remove_object object/clear_object \
		object/copy_content

FILES	+= validate/args validate/validate validate/ambient validate/camera validate/cylinder \
		validate/light validate/plane validate/sphere validate/utils validate/setters

FILES	+= scene/init_camera scene/view_transform scene/init_objects

FILES	+= render/render render/color_at render/getters render/hit_cylinder \
		render/hit_plane render/hit_sphere render/intersect_sphere \
		render/intersect_cylinder render/light render/normal_at \
		render/shade_hit render/shadow render/transform_ray

FILES	+= window/window

FILES 	+= utils/data utils/color utils/file utils/header utils/errors \
		utils/get_orientation utils/space_tabs

FILES	+= debug

SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

# FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFLAGS = -Llibs/MLX42/build -Llibs/libft -Llibs/libvector -lmlx42 -lft -lvector -Iinclude -ldl -lglfw -pthread -lm
VALGRIND_ARGS = --trace-children=yes --track-origins=yes  --suppressions=mini.supp \
	--leak-check=full --show-leak-kinds=all --quiet

all: $(NAME)

$(NAME): $(OBJS) libft mlx42 libvector
	@echo "$(purple)Compiling project...$(reset)"
	@$(CC) $(OBJS) -o $@ $(LIBFLAGS) && \
	echo "$(purple)Project compiled. Run './$(NAME)' to start.$(reset)"
	
libft:
	@echo "$(purple)Compiling Libft...$(reset)"
	@$(MAKE) -C libs/libft > /dev/null

mlx42:
	@echo "$(purple)Compiling MLX42...$(reset)" 
	@cmake -B libs/MLX42/build -S libs/MLX42  > /dev/null && \
	echo "$(purple)Building MLX42...$(reset)" && \
	cmake --build libs/MLX42/build -j4 > /dev/null

libvector:
	@echo "$(purple)Compiling Libvector...$(reset)"
	@$(MAKE) -C libs/libvector > /dev/null

%.o: %.c
	@echo "$(purple)Compiling $<...$(reset)"
	@$(CC) $(CFLAGS) -I$(PATH_INC) -c $< -o $@
    
valgrind: re
	valgrind $(VALGRIND_ARGS) ./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C libs/libft clean > /dev/null
	@rm -rf libs/MLX42/build
	@$(MAKE) -C libs/libvector clean > /dev/null
	$(info $(yellow)All object files were removed.$(reset))

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libs/libft fclean > /dev/null
	@$(MAKE) -C libs/libvector fclean > /dev/null
	$(info $(yellow)Executables files were removed.$(reset))

re: fclean all
	
.PHONY: all color clean fclean re valgrind