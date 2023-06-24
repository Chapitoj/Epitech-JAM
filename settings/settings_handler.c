/*
** EPITECH PROJECT, 2023
** jam
** File description:
** settings handler
*/

#include "jam.h"

static void display_settings(game_t *game)
{
    sfRenderWindow_display(WINDOW);
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW, SETTINGS->back->s, NULL);
    display_button(WINDOW, SETTINGS->music_b);
    display_button(WINDOW, SETTINGS->sound_b);
    sfRenderWindow_drawSprite(WINDOW, CURSOR->sprite, NULL);
}

static void check_click(game_t *game)
{
    if (is_button_pressed(SETTINGS->music_b, &EVENT.mouseButton)) {
        if (SETTINGS->music_b->state == NONE) {
            SETTINGS->music = sfFalse;
            SETTINGS->music_b->state = HOVER;
            sfMusic_stop(MENU->music);
        } else {
            SETTINGS->music = sfTrue;
            SETTINGS->music_b->state = NONE;
            sfMusic_play(MENU->music);
        }
    }
    if (is_button_pressed(SETTINGS->sound_b, &EVENT.mouseButton)) {
        if (SETTINGS->sound_b->state == NONE) {
            SETTINGS->sound = sfFalse;
            SETTINGS->sound_b->state = HOVER;
        } else {
            SETTINGS->sound = sfTrue;
            SETTINGS->sound_b->state = NONE;
        }
    }
}

static void analyze_settings_events(game_t *game)
{
    if (EVENT.type == sfEvtMouseMoved) {
        sfSprite_setPosition(game->cursor->sprite,
        (sfVector2f){EVENT.mouseMove.x - 35, EVENT.mouseMove.y - 25});
        check_hover(MENU, &EVENT.mouseMove);
    }
    if (EVENT.type == sfEvtKeyPressed) {
        if (EVENT.key.code == sfKeyEscape)
            SETTINGS->leave = sfTrue;
        if (EVENT.key.code == sfKeyL)
            sfRenderWindow_close(WINDOW);
    }
    if (EVENT.type == sfEvtMouseButtonPressed) {
        play_sound(game, game->cursor->sound);
        check_click(game);
    }
}

void settings_handler(game_t *game)
{
    while (sfRenderWindow_isOpen(WINDOW) && !SETTINGS->leave) {
        display_settings(game);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            analyze_settings_events(game);
    }
    SETTINGS->leave = sfFalse;
}
