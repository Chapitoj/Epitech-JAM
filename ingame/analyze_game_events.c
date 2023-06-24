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
        move_player_left(game);
        move_cam_left(game);
    }
    if (code == sfKeyDown) {
        move_player_down(game);
        move_cam_down(game);
    }
    if (code == sfKeyRight) {
        move_player_right(game);
        move_cam_right(game);
    }
    if (code == sfKeyUp) {
        move_player_up(game);
        move_cam_up(game);
    }
}

void analyze_game_events(game_t *game)
{
    if (EVENT.type == sfEvtKeyPressed)
        check_movement(game, EVENT.key.code);
}
