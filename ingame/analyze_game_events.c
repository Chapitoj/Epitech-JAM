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

static void check_random(game_t *game, sfKeyCode code)
{
    if (code == sfKeyEscape)
        go_to_settings(game);
    if (code == sfKeyL)
        sfRenderWindow_close(WINDOW);
    if (code == sfKeyZ) {
        if (INGAME->ath)
            INGAME->ath = sfFalse;
        else
            INGAME->ath = sfTrue;
    }
}

static void check_kill(game_t *game, sfKeyCode code)
{
    sfFloatRect *tmp = NULL;

    if (code != sfKeyA)
        return;
    tmp = malloc(sizeof(sfFloatRect));
    tmp->height = PLAYER->rec_pos.height;
    tmp->left = PLAYER->rec_pos.left;
    tmp->width = PLAYER->rec_pos.width;
    tmp->top = PLAYER->rec_pos.top;
    for (int i = 0; FAMILY[i] != NULL; i++) {
        if (FAMILY[i]->alive
        && sfFloatRect_intersects(tmp, FAMILY[i]->rec, NULL)) {
            play_sound(game, PLAYER->sound);
            FAMILY[i]->alive = sfFalse;
            INGAME->kills++;
        }
    }
    free(tmp);
}

void analyze_game_events(game_t *game)
{
    if (EVENT.type == sfEvtKeyPressed) {
        check_movement(game, EVENT.key.code);
        check_random(game, EVENT.key.code);
        check_kill(game, EVENT.key.code);
    }
}
