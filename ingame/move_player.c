/*
** EPITECH PROJECT, 2023
** jam
** File description:
** move player
*/

#include "jam.h"

static void change_player_rect(game_t *game)
{
    PLAYER->rec_pos.left = PLAYER->pos.x;
    PLAYER->rec_pos.top = PLAYER->pos.y;
}

void move_player_left(game_t *game)
{
    if (PLAYER->pos.x - VELOCITY >= PLEFT
    && can_go_left(game) == 1) {
        PLAYER->pos.x -= VELOCITY;
        sfSprite_setPosition(PLAYER->sprite, PLAYER->pos);
        change_player_rect(game);
    }
}

void move_player_right(game_t *game)
{
    if (PLAYER->pos.x + VELOCITY + PLAYER->rec_pos.width <= PRIGHT
    && can_go_right(game) == 1) {
        PLAYER->pos.x += VELOCITY;
        sfSprite_setPosition(PLAYER->sprite, PLAYER->pos);
        change_player_rect(game);
    }
}

void move_player_up(game_t *game)
{
    if (PLAYER->pos.y - VELOCITY >= PUP
    && can_go_up(game) == 1) {
        PLAYER->pos.y -= VELOCITY;
        sfSprite_setPosition(PLAYER->sprite, PLAYER->pos);
        change_player_rect(game);
    }
}

void move_player_down(game_t *game)
{
    if (PLAYER->pos.y + VELOCITY + PLAYER->rec_pos.height <= PDWON
    && can_go_down(game) == 1) {
        PLAYER->pos.y += VELOCITY;
        sfSprite_setPosition(PLAYER->sprite, PLAYER->pos);
        change_player_rect(game);
    }
}
