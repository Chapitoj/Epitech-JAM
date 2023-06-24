/*
** EPITECH PROJECT, 2023
** jam
** File description:
** analyze
*/

#include "jam.h"

static void go_to_settings(game_t *game)
{
    sfView_reset(CAMERA->view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(WINDOW, CAMERA->view);
    settings_handler(game);
    sfView_reset(CAMERA->view, CAMERA->res_rect);
    sfRenderWindow_setView(WINDOW, CAMERA->view);
}

static void check_movement(game_t *game, sfKeyCode code)
{
    if (code == sfKeyEscape)
        go_to_settings(game);
    if (code == sfKeyL)
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
