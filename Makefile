# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:04:54 by aqueiroz          #+#    #+#              #
#    Updated: 2024/03/16 15:11:44 by fsuomins         ###   ########.fr        #
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

SRC_PATH = sources
LIB_PATH = libs
PATH_INC = includes

FILES	= main debug

FILES	+= objects/add_object objects/clear_object objects/default_material \
		   objects/set_ambient_light

FILES	+= validate/args validate/validate validate/ambient validate/camera validate/cylinder \
		validate/light validate/plane validate/sphere validate/color validate/orientation \
		validate/free_split

FILES 	+= utils/data utils/print_header

FILES 	+= window/init_resolution window/window_loop

FILES 	+= render/render render/camera_on render/ray_color render/ray_at

FILES 	+= shadow/is_shadow shadow/lightning

FILES 	+= hit/init_hit hit/hit_sphere hit/hit_plane hit/hit_cylinder \
		hit/hittable_list_hit hit/body_or_cap hit/init_bhaskara \
		hit/select_hit hit/set_normal_face hit/update_hit_record

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