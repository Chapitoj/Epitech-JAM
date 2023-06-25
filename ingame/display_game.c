/*
** EPITECH PROJECT, 2023
** jam
** File description:
** display game
*/

#include "jam.h"

static void display_timer(game_t *game, sfVector2f pos)
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

static void display_kills(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile("visu/skull.png", NULL);
    sfSprite *sprite = NULL;
    int tmp = 7;
    sfVector2f pos = (sfVector2f){CAMERA->position.x, CAMERA->position.y};
    pos.x += CAM_WIDTH;

    for (int i = 0; i < INGAME->kills; i++) {
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, 1);
        sfSprite_setScale(sprite, (sfVector2f){0.05, 0.05});
        pos.x -= tmp;
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(WINDOW, sprite, NULL);
        sfSprite_destroy(sprite);
    }
    sfTexture_destroy(texture);
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
    }
    if (INGAME->ath) {
        display_timer(game, (sfVector2f){CAMERA->position.x,
        CAMERA->position.y - 4});
        display_kills(game);
    }
}
