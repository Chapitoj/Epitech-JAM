/*
** EPITECH PROJECT, 2023
** jam
** File description:
** display game
*/

#include "jam.h"

void display_game(game_t *game)
{
    sfRenderWindow_display(WINDOW);
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW, INGAME->back, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER->sprite, NULL);
}
