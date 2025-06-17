##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makfile
##

SRC	=	src/main.c	\
		src/init_ncurses.c	\
		src/init_game.c	\
		src/print_help.c	\
		src/check_win.c	\
		src/map/count_lines.c	\
		src/map/load_map.c	\
		src/map/copy_map.c	\
		src/map/display_map.c	\
		src/map/count_box_storage.c	\
		src/player/find_player.c	\
		src/player/move_player.c	\
		src/player/check_player_move.c	\
		src/error_handling/args_handling.c	\
		src/error_handling/map_handling.c	\
		src/error_handling/sounds_handling.c	\
		src/csfml/free_cells.c	\
		src/csfml/game_loop.c	\
		src/csfml/get_color.c	\
		src/csfml/init_csfml.c	\


NAME	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include/ -L./lib/my -lmy -Wall -Wextra -lncurses

CFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: build_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

build_lib:
		make -C ./lib/my/

clean_lib:
		make clean -C ./lib/my/

clean: clean_lib
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

valgrind: build_lib $(OBJ)
		  gcc -o $(NAME) $(OBJ) $(CFLAGS) -g
		  valgrind --leak-check=full --track-origins=yes ./$(NAME) map.txt

.PHONY: all fclean clean re
