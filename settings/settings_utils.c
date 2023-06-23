/*
** EPITECH PROJECT, 2023
** jam
** File description:
** set uti
*/

#include "jam.h"

settings_t *init_settings(sfRenderWindow *w)
{
    settings_t *set = malloc(sizeof(settings_t));
    dimensions_t *dim = init_dimensions((sfVector2f){685, 450},
    (sfVector2f){550, 150});

    set->back = init_background("visu/test1.jpg", w);
    set->leave = sfFalse;
    set->music = sfTrue;
    set->sound = sfTrue;
    set->music_b = init_button("visu/muson.jpg", "visu/musoff.jpg", dim);
    dim->pos.y = 700;
    set->sound_b = init_button("visu/soundon.jpg", "visu/soundoff.jpg", dim);
    return set;
}

void clear_settings(settings_t *set)
{
    sfSprite_destroy(set->back->s);
    sfTexture_destroy(set->back->t);
    free(set->back);
    clear_button(set->music_b);
    clear_button(set->sound_b);
    free(set);
}
