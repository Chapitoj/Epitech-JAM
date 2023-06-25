/*
** EPITECH PROJECT, 2023
** jam
** File description:
** end
*/

#include "jam.h"

static void display_end(game_t *game, sfSprite *sprite)
{
    sfRenderWindow_display(WINDOW);
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW, sprite, NULL);
}

static void analyze_end_events(game_t *game)
{
    if (EVENT.type == sfEvtKeyPressed) {
        if (EVENT.key.code == sfKeyEscape || EVENT.key.code == sfKeyL)
            sfRenderWindow_close(WINDOW);
    }
}

void end_screen(game_t *game, char *filepath, sfVector2f scale)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 1);
    sfSprite_setScale(sprite, scale);
    sfView_reset(CAMERA->view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(WINDOW, CAMERA->view);
    while (sfRenderWindow_isOpen(WINDOW)) {
        display_end(game, sprite);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            analyze_end_events(game);

    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
