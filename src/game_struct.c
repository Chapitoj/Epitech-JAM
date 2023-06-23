/*
** EPITECH PROJECT, 2023
** jam
** File description:
** game struct utils
*/

#include "jam.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    MODE = (sfVideoMode){1920, 1080, 32};
    WINDOW = sfRenderWindow_create(MODE, "parasite", sfFullscreen, NULL);
    CURSOR = init_cursor();
    SETTINGS = init_settings(WINDOW);
    return game;
}

void clear_game(game_t *game)
{
    sfRenderWindow_destroy(WINDOW);
    clear_cursor(CURSOR);
    clear_settings(SETTINGS);
    free(game);
}
