# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 17:02:25 by gpirozzi          #+#    #+#              #
#    Updated: 2025/07/16 11:57:11 by gpirozzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# File sorgenti (da scrivere manualmente)
SRC = \
	main/main.c main/3d.c main/animation.c main/collision_utils.c\
	main/data_init.c main/data_init2.c main/define_textures.c\
	main/draw_bresenham.c main/draw_game.c main/draw_minimap.c\
	main/free_utils.c main/free_utils2.c main/handle_keys.c\
	main/init_texture_data.c main/load_texture.c main/mouse_functions.c main/my_drawing_functions.c\
	main/player_movement.c main/raycasting.c main/weapons_utils.c\
	parsing/check_data.c parsing/check_external_map.c parsing/check_map.c\
	parsing/doors.c parsing/extract_data.c parsing/find_id_to_pars.c parsing/general_utils.c\
	parsing/parsing_map_utils.c parsing/init_padded_map.c\
	parsing/parsing_map_utils2.c parsing/parsing.c\

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

INC = -I$(LIBFT_DIR) -I$(MLX_DIR) -Iinclude
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(LDFLAGS) -o $(NAME)
	@echo "Created $(NAME)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(MLX):
	@$(MAKE) -C $(MLX_DIR) --quiet

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR) --quiet
	@$(MAKE) clean -C $(MLX_DIR) --quiet

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --quiet

re: fclean all

vall: all clean
	@valgrind --track-origins=yes --leak-check=full \
		--show-leak-kinds=all --track-fds=yes \
		--trace-children=yes ./$(NAME)

.PHONY: all clean fclean re vall

