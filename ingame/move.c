/*
** EPITECH PROJECT, 2023
** jam
** File description:
** move police
*/

#include "jam.h"
#include <math.h>

static sfVector2f give_speed(int s, sfVector2f ppos, sfVector2f pos)
{
    int dx = sqrt(pow(ppos.x - pos.x, 2));
    int dy = sqrt(pow(ppos.y - pos.y, 2));
    double res = 0;
    sfVector2f speed;

    speed.x = s;
    speed.y = s;
    res = (double)dx / (double)dy;
    (res < 1) ? (speed.x *= res) : (speed.y /= res);
    if (ppos.x - pos.x < 0)
        speed.x *= -1;
    if (ppos.y - pos.y < 0)
        speed.y *= -1;
    return speed;
}

static int is_in_camera(game_t *game)
{
    if ((POLICE->rect->left >= CAMERA->position.x
    && POLICE->rect->left <= CAMERA->position.x + CAM_WIDTH)
    && (POLICE->rect->top >= CAMERA->position.y
    && POLICE->rect->top <= CAMERA->position.y + CAM_HEIGHT))
        return 1;
    return 0;
}

static void shout(game_t *game)
{
    if (sfClock_getElapsedTime(INGAME->stop).microseconds < 1500000.0)
        return;
    if (is_in_camera(game)) {
        sfClock_restart(INGAME->stop);
        play_sound(game, INGAME->shout);
    }
}

void move_police(game_t *game, police_t *police)
{
    sfVector2f speed;
    sfVector2f pos = (sfVector2f){police->rect->left, police->rect->top};

    if (!POLICE->called)
        return;
    else
        shout(game);
    if (sfClock_getElapsedTime(INGAME->move).microseconds < police->speed)
        return;
    else
        sfClock_restart(INGAME->move);
    speed = give_speed(1, PLAYER->pos, pos);
    police->rect->left += speed.x;
    police->rect->top += speed.y;
    pos = (sfVector2f){police->rect->left, police->rect->top};
    sfSprite_setPosition(police->sprite, pos);
}
