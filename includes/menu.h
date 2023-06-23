/*
** EPITECH PROJECT, 2023
** jam
** File description:
** menu
*/

#ifndef MENU_H
    #define MENU_H

    #include "game_struct.h"
    #include "menu_struct.h"

menu_t *init_menu(sfRenderWindow *w);

void clear_menu(menu_t *menu);

void analyze_menu_events(game_t *game);

#endif /* !MENU_H */
