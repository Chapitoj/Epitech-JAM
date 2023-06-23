/*
** EPITECH PROJECT, 2023
** jam
** File description:
** menu
*/

#include "jam.h"
#include "menu.h"

menu_t *init_menu(sfRenderWindow *w)
{
    menu_t *m = malloc(sizeof(menu_t));
    dimensions_t *dim = init_dimensions((sfVector2f){685, 450},
    (sfVector2f){550, 150});

    m->back = init_background("visu/test1.jpg", w);
    m->leave = sfFalse;
    m->play_b = init_button("visu/play.jpg", "visu/hplay.jpg", dim);
    dim->pos.y = 660;
    m->settings_b = init_button("visu/set.jpg", "visu/hset.jpg", dim);
    dim->pos.y = 870;
    m->quit_b = init_button("visu/leave.jpg", "visu/hleave.jpg", dim);
    free(dim);
    m->music = sfMusic_createFromFile("visu/menum.ogg");
    sfMusic_setLoop(m->music, sfTrue);
    return m;
}

void clear_menu(menu_t *menu)
{
    sfSprite_destroy(menu->back->s);
    sfTexture_destroy(menu->back->t);
    clear_button(menu->play_b);
    clear_button(menu->settings_b);
    clear_button(menu->quit_b);
    free(menu->back);
    sfMusic_destroy(menu->music);
    free(menu);
}
