/*
** EPITECH PROJECT, 2023
** jam
** File description:
** button utils
*/

#include "jam.h"

dimensions_t *init_dimensions(sfVector2f pos, sfVector2f size)
{
    dimensions_t *dim = malloc(sizeof(dimensions_t));

    dim->pos = pos;
    dim->size = size;
    return dim;
}

button_t *init_button(char *filepath1, char *filepath2, dimensions_t *dim)
{
    button_t *b = malloc(sizeof(button_t));

    b->r = sfRectangleShape_create();
    b->t = sfTexture_createFromFile(filepath1, NULL);
    b->hover_t = sfTexture_createFromFile(filepath2, NULL);
    b->state = NONE;
    b->size = dim->size;
    b->pos = dim->pos;
    sfRectangleShape_setSize(b->r, b->size);
    sfRectangleShape_setPosition(b->r, b->pos);
    return b;
}

void clear_button(button_t *b)
{
    sfTexture_destroy(b->hover_t);
    sfTexture_destroy(b->t);
    sfRectangleShape_destroy(b->r);
    free(b);
}
