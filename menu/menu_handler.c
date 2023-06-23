/*
** EPITECH PROJECT, 2023
** jam
** File description:
** menu handler
*/

#include "jam.h"
#include "menu.h"

void display_button(sfRenderWindow *w, button_t *b)
{
    if (b->state == HOVER)
        sfRectangleShape_setTexture(b->r, b->hover_t, 1);
    else
        sfRectangleShape_setTexture(b->r, b->t, 1);
    sfRenderWindow_drawRectangleShape(w, b->r, NULL);
}

static void display_menu(game_t *game)
{
    sfRenderWindow_display(WINDOW);
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW, MENU->back->s, NULL);
    display_button(WINDOW, MENU->play_b);
    display_button(WINDOW, MENU->settings_b);
    display_button(WINDOW, MENU->quit_b);
    sfRenderWindow_drawSprite(WINDOW, CURSOR->sprite, NULL);
}

void menu_handler(game_t *game)
{
    MENU = init_menu(WINDOW);

    sfMusic_play(MENU->music);
    while (sfRenderWindow_isOpen(WINDOW)) {
        display_menu(game);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            analyze_menu_events(game);
    }
    sfMusic_stop(MENU->music);
    clear_menu(MENU);
}
