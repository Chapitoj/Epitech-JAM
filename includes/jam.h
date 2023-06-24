/*
** EPITECH PROJECT, 2023
** jam
** File description:
** jam.h
*/

#ifndef JAM_H
    #define JAM_H

    #include <stdlib.h>
    #include "game_struct.h"

    #define WINDOW game->window
    #define MODE game->mode
    #define EVENT game->event
    #define CURSOR game->cursor
    #define MENU game->menu
    #define SETTINGS game->settings
    #define INGAME game->ingame
    #define CAMERA game->ingame->camera
    #define PLAYER game->ingame->player
    #define WALLS game->ingame->walls
    #define VELOCITY 2
    #define LEFT 100
    #define PLEFT 166
    #define UP 150
    #define PUP 173
    #define RIGHT 1042
    #define PRIGHT 981
    #define DOWN 510
    #define PDWON 496
    #define CAM_HEIGHT 100
    #define CAM_WIDTH 200
    #define NB_WALLS 28

game_t *init_game(void);

void clear_game(game_t *game);

void menu_handler(game_t *game);

cursor_t *init_cursor(void);

void clear_cursor(cursor_t *cursor);

background_t *init_background(char *filepath, sfRenderWindow *w);

settings_t *init_settings(sfRenderWindow *w);

void clear_settings(settings_t *set);

button_t *init_button(char *filepath1, char *filepath2, dimensions_t *dim);

dimensions_t *init_dimensions(sfVector2f pos, sfVector2f size);

void clear_button(button_t *b);

void settings_handler(game_t *game);

void display_button(sfRenderWindow *w, button_t *b);

void is_button_hover(button_t *b, sfMouseMoveEvent *e);

void check_hover(menu_t *m, sfMouseMoveEvent *e);

int is_button_pressed(button_t *b, sfMouseButtonEvent *e);

void play_sound(game_t *game, sfSound *sound);

ingame_t *init_ingame(void);

void clear_ingame(ingame_t *ingame);

void game_handler(game_t *game);

void display_game(game_t *game);

void analyze_game_events(game_t *game);

void move_cam_left(game_t *game);

void move_cam_up(game_t *game);

void move_cam_right(game_t *game);

void move_cam_down(game_t *game);

void move_player_left(game_t *game);

void move_player_right(game_t *game);

void move_player_up(game_t *game);

void move_player_down(game_t *game);

sfFloatRect **init_walls(void);

int can_go_left(game_t *game);

int can_go_right(game_t *game);

int can_go_up(game_t *game);

int can_go_down(game_t *game);

#endif /* !JAM_H */
