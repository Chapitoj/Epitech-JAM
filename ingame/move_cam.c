/*
** EPITECH PROJECT, 2023
** jam
** File description:
** came movements
*/

#include "jam.h"

void replace_cam(game_t *game)
{
    CAMERA->res_rect.left = CAMERA->position.x;
    CAMERA->res_rect.top = CAMERA->position.y;
    sfView_reset(CAMERA->view, CAMERA->res_rect);
    sfRenderWindow_setView(WINDOW, CAMERA->view);
}

void move_cam_left(game_t *game)
{
    if (CAMERA->position.x - VELOCITY >= LEFT) {
        CAMERA->position.x -= VELOCITY;
        replace_cam(game);
    }
}

void move_cam_right(game_t *game)
{
    if (CAMERA->position.x + VELOCITY + CAM_WIDTH <= RIGHT) {
        CAMERA->position.x += VELOCITY;
        replace_cam(game);
    }
}

void move_cam_up(game_t *game)
{
    if (CAMERA->position.y - VELOCITY >= UP) {
        CAMERA->position.y -= VELOCITY;
        replace_cam(game);
    }
}

void move_cam_down(game_t *game)
{
    if (CAMERA->position.y + VELOCITY + CAM_HEIGHT <= DOWN) {
        CAMERA->position.y += VELOCITY;
        replace_cam(game);
    }
}
