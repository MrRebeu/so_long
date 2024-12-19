NAME = so_long
SRCS_MAPS = game_maps/check_file_extension.c \
			game_maps/check_elements.c\
			game_maps/check_line_lengths.c\
			game_maps/check_walls.c\
			game_maps/count_map_lines.c\
			game_maps/fill_map_data.c\
			game_maps/free_map.c\
			game_maps/init_map_structure.c\
			game_maps/load_map.c

SRCS_LOGIC = game_logic/init_games.c \
             game_logic/move_player.c\
			 game_logic/handle_keypress.c\
			 game_logic/collect_item.c\
			 game_logic/check_win_condition.c\
			 game_logic/setup_game.c

SRCS_IMAGE = game_images/init_images.c \
             game_images/render_map.c
MLX_DIR = minilibx
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS = main.c \ $(SRCS_MAPS) \ $(SRCS_LOGIC) \ $(SRCS_IMAGES) \ $(SRCS_GNL)


OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./minilibx -I./get_next_line
MLX = -lmlx -framework OpenGL -framework AppKit
LIBFT = -L./libft -lft


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re