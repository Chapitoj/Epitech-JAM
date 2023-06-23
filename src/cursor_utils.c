/*
** EPITECH PROJECT, 2023
** jam
** File description:
** crusror
*/

#include "jam.h"


cursor_t *init_cursor(void)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    cursor->sprite = sfSprite_create();
    cursor->texture = sfTexture_createFromFile("visu/cursor.png", NULL);
    sfSprite_setTexture(cursor->sprite, cursor->texture, 1);
    sfSprite_setScale(cursor->sprite, (sfVector2f){0.3, 0.3});
    cursor->buffer = sfSoundBuffer_createFromFile("visu/click.wav");
    cursor->sound = sfSound_create();
    sfSound_setBuffer(cursor->sound, cursor->buffer);
    return cursor;
}

void clear_cursor(cursor_t *cursor)
{
    sfSprite_destroy(cursor->sprite);
    sfTexture_destroy(cursor->texture);
    sfSoundBuffer_destroy(cursor->buffer);
    sfSound_destroy(cursor->sound);
    free(cursor);
}
