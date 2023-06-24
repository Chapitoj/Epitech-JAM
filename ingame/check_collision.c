/*
** EPITECH PROJECT, 2023
** jam
** File description:
** collision
*/

#include "jam.h"

int can_go_left(game_t *game)
{
    sfFloatRect *tmp = malloc(sizeof(sfFloatRect));
    tmp->height = PLAYER->rec_pos.height;
    tmp->left = PLAYER->rec_pos.left - VELOCITY;
    tmp->top = PLAYER->rec_pos.top;
    tmp->width = PLAYER->rec_pos.width;

    for (int i = 0; i < NB_WALLS; i++) {
        if (sfFloatRect_intersects(tmp, WALLS[i], NULL)) {
            free(tmp);
            return 0;
        }
    }
    free(tmp);
    return 1;
}

int can_go_right(game_t *game)
{
    sfFloatRect *tmp = malloc(sizeof(sfFloatRect));
    tmp->height = PLAYER->rec_pos.height;
    tmp->left = PLAYER->rec_pos.left + VELOCITY;
    tmp->top = PLAYER->rec_pos.top;
    tmp->width = PLAYER->rec_pos.width;

    for (int i = 0; i < NB_WALLS; i++) {
        if (sfFloatRect_intersects(tmp, WALLS[i], NULL)) {
            free(tmp);
            return 0;
        }
    }
    free(tmp);
    return 1;
}

int can_go_up(game_t *game)
{
    sfFloatRect *tmp = malloc(sizeof(sfFloatRect));
    tmp->height = PLAYER->rec_pos.height;
    tmp->left = PLAYER->rec_pos.left;
    tmp->top = PLAYER->rec_pos.top - VELOCITY;
    tmp->width = PLAYER->rec_pos.width;

    for (int i = 0; i < NB_WALLS; i++) {
        if (sfFloatRect_intersects(tmp, WALLS[i], NULL)) {
            free(tmp);
            return 0;
        }
    }
    free(tmp);
    return 1;
}

int can_go_down(game_t *game)
{
    sfFloatRect *tmp = malloc(sizeof(sfFloatRect));
    tmp->height = PLAYER->rec_pos.height;
    tmp->left = PLAYER->rec_pos.left;
    tmp->top = PLAYER->rec_pos.top + VELOCITY;
    tmp->width = PLAYER->rec_pos.width;

    for (int i = 0; i < NB_WALLS; i++) {
        if (sfFloatRect_intersects(tmp, WALLS[i], NULL)) {
            free(tmp);
            return 0;
        }
    }
    free(tmp);
    return 1;
}
