/*
** EPITECH PROJECT, 2023
** jam
** File description:
** game_handler
*/

#include "jam.h"

void game_handler(game_t *game)
{
    sfView_reset(CAMERA->view, CAMERA->res_rect);
    sfRenderWindow_setView(WINDOW, CAMERA->view);
    while (sfRenderWindow_isOpen(WINDOW)) {
        display_game(game);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            analyze_game_events(game);
    }
    clear_ingame(INGAME);
}
