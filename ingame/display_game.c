/*
** EPITECH PROJECT, 2023
** jam
** File description:
** display game
*/

#include "jam.h"

void display_timer(game_t *game, sfVector2f pos)
{
    sfFont *font = sfFont_createFromFile("visu/Para.ttf");
    sfText *text = sfText_create();
    char *time = convert_time(TIME - INGAME->time);

    sfText_setFont(text, font);
    sfText_setString(text, time);
    sfText_setColor(text, sfRed);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(WINDOW, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    free(time);
}

void display_game(game_t *game)
{
    sfRenderWindow_display(WINDOW);
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW, INGAME->back, NULL);
    sfRenderWindow_drawSprite(WINDOW, PLAYER->sprite, NULL);
    for (int i = 0; FAMILY[i] != NULL; i++) {
        if (FAMILY[i]->alive)
            sfRenderWindow_drawSprite(WINDOW, FAMILY[i]->sprite, NULL);
    display_timer(game, (sfVector2f){CAMERA->position.x,
    CAMERA->position.y - 4});
    }
}
