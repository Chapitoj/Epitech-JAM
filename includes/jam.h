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

#endif /* !JAM_H */
