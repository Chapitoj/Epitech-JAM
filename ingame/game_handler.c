/*
** EPITECH PROJECT, 2023
** jam
** File description:
** game_handler
*/

#include "jam.h"

static int is_alive(game_t *game)
{
    for (int i = 0; FAMILY[i] != NULL; i++) {
        if (FAMILY[i]->alive)
            return 1;
    }
    return 0;
}

static void place_cam(game_t *game)
{
    CAMERA->position.x = PLAYER->pos.x - CAM_WIDTH / 2;
    CAMERA->position.y = PLAYER->pos.y - CAM_HEIGHT / 2;
    CAMERA->res_rect.left = CAMERA->position.x;
    CAMERA->res_rect.top = CAMERA->position.y;
    sfView_reset(CAMERA->view, CAMERA->res_rect);
    sfRenderWindow_setView(WINDOW, CAMERA->view);
}

void game_handler(game_t *game)
{
    place_cam(game);
    while (sfRenderWindow_isOpen(WINDOW)
    && is_alive(game) && INGAME->time <= TIME) {
        display_game(game);
        if (sfClock_getElapsedTime(INGAME->clock).microseconds > 1000000.0) {
            sfClock_restart(INGAME->clock);
            INGAME->time++;
        }
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            analyze_game_events(game);
    }
    sfMusic_stop(MENU->music);
    sfClock_destroy(INGAME->clock);
    clear_ingame(INGAME);
}
