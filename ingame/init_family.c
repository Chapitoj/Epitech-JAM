/*
** EPITECH PROJECT, 2023
** jam
** File description:
** init family
*/

#include "jam.h"
#include <time.h>

int is_in_wall(sfFloatRect *rec, sfFloatRect **walls)
{
    for (int i = 0; walls[i] != NULL; i++) {
        if (sfFloatRect_intersects(rec, walls[i], NULL))
            return 1;
    }
    return 0;
}

static void generate_vect(unit_t *unit, sfFloatRect **walls)
{
    unit->rec->left = (rand() % (PRIGHT - PLEFT + 1)) + PLEFT;
    unit->rec->top = (rand() % (PDWON - PUP + 1)) + PUP;
    while (is_in_wall(unit->rec, walls)) {
        unit->rec->left = (rand() % (PRIGHT - PLEFT + 1)) + PLEFT;
        unit->rec->top = (rand() % (PDWON - PUP + 1)) + PUP;
    }
}

static unit_t *add_family_member(char *filepath, sfVector2f scale,
sfFloatRect **walls)
{
    unit_t *unit = malloc(sizeof(unit_t));

    unit->rec = malloc(sizeof(sfFloatRect));
    unit->rec->height = 11;
    unit->rec->width = 4;
    generate_vect(unit, walls);
    unit->tex = sfTexture_createFromFile(filepath, NULL);
    unit->sprite = sfSprite_create();
    unit->alive = sfTrue;
    sfSprite_setTexture(unit->sprite, unit->tex, 1);
    sfSprite_setScale(unit->sprite, scale);
    sfSprite_setPosition(unit->sprite,
    (sfVector2f){unit->rec->left, unit->rec->top});
    return unit;
}

unit_t **init_family(sfFloatRect **walls)
{
    unit_t **family = malloc(sizeof(unit_t) * 6);

    family[5] = NULL;
    family[0] = add_family_member("visu/son.png", (sfVector2f){0.015, 0.016}
    , walls);
    family[1] = add_family_member("visu/mot.png", (sfVector2f){0.019, 0.022}
    , walls);
    family[2] = add_family_member("visu/son.png", (sfVector2f){0.015, 0.016}
    , walls);
    family[3] = add_family_member("visu/mot.png", (sfVector2f){0.019, 0.022}
    , walls);
    family[4] = add_family_member("visu/mot.png", (sfVector2f){0.019, 0.022}
    , walls);
    return family;
}
