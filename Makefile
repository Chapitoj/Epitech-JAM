##
## EPITECH PROJECT, 2023
## jam
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c \
		src/game_struct.c	\
		menu/menu_handler.c	\
		menu/menu_utils.c	\
		src/background_utils.c	\
		src/cursor_utils.c	\
		menu/analyze_menu_events.c	\
		menu/button_utils.c	\
		settings/settings_utils.c	\
		settings/settings_handler.c	\
		src/play_sound.c	\
		ingame/game_handler.c	\
		ingame/game_utils.c	\
		ingame/analyze_game_events.c	\
		ingame/display_game.c	\
		ingame/move_cam.c	\
		ingame/move_player.c	\
		ingame/init_walls.c	\
		ingame/check_collision.c	\
		ingame/init_family.c	\
		ingame/convert_time.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_jam

CFLAGS	=	-Wall -Wextra -lm

CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

CPPFLAGS	=	-I./includes

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CSFMLFLAGS)

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *~

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

debug: CPPFLAGS += -g3
debug: re

.PHONY: all clean fclean re
