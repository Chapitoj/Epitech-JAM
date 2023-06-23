/*
** EPITECH PROJECT, 2023
** jam
** File description:
** background
*/

#include "jam.h"

sfVector2f scale_background(sfRenderWindow *window, sfTexture *texture)
{
    sfVector2f vect;
    sfVector2u vwind = sfRenderWindow_getSize(window);
    sfVector2u vtext = sfTexture_getSize(texture);

    vect.x = (double)vwind.x / (double)vtext.x;
    vect.y = (double)vwind.y / (double)vtext.y;
    return vect;
}

background_t *init_background(char *filepath, sfRenderWindow *w)
{
    background_t *b = malloc(sizeof(background_t));

    b->t = sfTexture_createFromFile(filepath, NULL);
    b->s = sfSprite_create();
    sfSprite_setTexture(b->s, b->t, 1);
    sfSprite_scale(b->s, scale_background(w, b->t));
    return b;
}
