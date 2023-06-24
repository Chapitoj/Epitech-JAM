/*
** EPITECH PROJECT, 2023
** jam
** File description:
** game struct
*/

#ifndef GAME_STRUCT_H
    #define GAME_STRUCT_H

    #include "menu_struct.h"
    #include "settings_struc.h"
    #include "ingame.h"

typedef struct game_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    cursor_t *cursor;
    menu_t *menu;
    settings_t *settings;
    ingame_t *ingame;
}game_t;

#endif /* !GAME_STRUCT_H */
