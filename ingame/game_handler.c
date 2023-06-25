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

static int not_captured(game_t *game)
{
    sfFloatRect *tmp = NULL;

    if (!POLICE->called)
        return 1;
    tmp = malloc(sizeof(sfFloatRect));
    tmp->height = PLAYER->rec_pos.height;
    tmp->left = PLAYER->rec_pos.left;
    tmp->width = PLAYER->rec_pos.width;
    tmp->top = PLAYER->rec_pos.top;
    if (sfFloatRect_intersects(POLICE->rect, tmp, NULL)) {
        free(tmp);
        play_sound(game, POLICE->sound);
        return 0;
    }
    free(tmp);
    return 1;
}

static void change_police_speed(game_t *game)
{
    if (INGAME->time == TIME) {
        POLICE->called = sfTrue;
        play_sound(game, POLICE->sound);
    }
    if (POLICE->called && INGAME->time % 7 == 0)
        POLICE->speed -= 10000;
    if (TIME - INGAME->time == 10)
        play_sound(game, INGAME->timer);
}

void game_handler(game_t *game)
{
    place_cam(game);
    while (sfRenderWindow_isOpen(WINDOW)
    && is_alive(game) && not_captured(game)) {
        display_game(game);
        if (sfClock_getElapsedTime(INGAME->clock).microseconds > 1000000.0) {
            sfClock_restart(INGAME->clock);
            INGAME->time++;
            change_police_speed(game);
        }
        move_police(game, POLICE);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            analyze_game_events(game);
    }
    sfMusic_stop(MENU->music);
    if (is_alive(game))
        end_screen(game, "visu/lost.jpg", (sfVector2f){0.96, 1.1});
    else
        end_screen(game, "visu/won.jpg", (sfVector2f){2.4, 2.1});
    sfClock_destroy(INGAME->clock);
    clear_ingame(INGAME);
}
