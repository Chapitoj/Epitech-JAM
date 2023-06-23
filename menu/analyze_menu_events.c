/*
** EPITECH PROJECT, 2023
** jam
** File description:
** menu events
*/

#include "jam.h"

void is_button_hover(button_t *b, sfMouseMoveEvent *e)
{
    sfFloatRect a;

    a.height = b->size.y;
    a.left = b->pos.x;
    a.top = b->pos.y;
    a.width = b->size.x;
    if (sfFloatRect_contains(&a, e->x, e->y))
        b->state = HOVER;
    else
        b->state = NONE;
}

void check_hover(menu_t *m, sfMouseMoveEvent *e)
{
    is_button_hover(m->play_b, e);
    is_button_hover(m->settings_b, e);
    is_button_hover(m->quit_b, e);
}

int is_button_pressed(button_t *b, sfMouseButtonEvent *e)
{
    sfFloatRect a;

    a.height = b->size.y;
    a.left = b->pos.x;
    a.top = b->pos.y;
    a.width = b->size.x;
    if (sfFloatRect_contains(&a, e->x, e->y))
        return 1;
    return 0;
}

static void check_click(game_t *game)
{
    if (is_button_pressed(MENU->play_b, &EVENT.mouseButton))
        MENU->leave = sfTrue;
    if (is_button_pressed(MENU->settings_b, &EVENT.mouseButton))
        settings_handler(game);
    if (is_button_pressed(MENU->quit_b, &EVENT.mouseButton))
        sfRenderWindow_close(WINDOW);
}

void analyze_menu_events(game_t *game)
{
    if (EVENT.type == sfEvtMouseMoved) {
        sfSprite_setPosition(game->cursor->sprite,
        (sfVector2f){EVENT.mouseMove.x - 35, EVENT.mouseMove.y - 25});
        check_hover(MENU, &EVENT.mouseMove);
    }
    if (EVENT.type == sfEvtKeyPressed) {
        if (EVENT.key.code == sfKeyEscape)
            sfRenderWindow_close(WINDOW);
    }
    if (EVENT.type == sfEvtMouseButtonPressed) {
        play_sound(game, game->cursor->sound);
        check_click(game);
    }
}
