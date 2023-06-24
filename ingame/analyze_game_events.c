/*
** EPITECH PROJECT, 2023
** jam
** File description:
** analyze
*/

#include "jam.h"

static void check_movement(game_t *game, sfKeyCode code)
{
    if (code == sfKeyEscape)
        sfRenderWindow_close(WINDOW);
    if (code == sfKeyLeft) {
        move_cam_left(game);
    }
    if (code == sfKeyDown) {
        move_cam_down(game);
    }
    if (code == sfKeyRight) {
        move_cam_right(game);
    }
    if (code == sfKeyUp) {
        move_cam_up(game);
    }
}

void analyze_game_events(game_t *game)
{
    if (EVENT.type == sfEvtKeyPressed)
        check_movement(game, EVENT.key.code);
}
