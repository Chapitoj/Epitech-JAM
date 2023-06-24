/*
** EPITECH PROJECT, 2023
** jam
** File description:
** game utils
*/

#include "jam.h"
#include "ingame.h"

static camera_t *init_camera(void)
{
    camera_t *camera = malloc(sizeof(camera_t));
    sfVector2f scale = {1080, 1080};

    camera->res_rect = (sfFloatRect){LEFT, UP, CAM_WIDTH, CAM_HEIGHT};
    camera->view = sfView_createFromRect(camera->res_rect);
    sfView_setSize(camera->view, scale);
    camera->position = (sfVector2f){LEFT, UP};
    return camera;
}

static player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->sprite = sfSprite_create();
    player->tex = sfTexture_createFromFile("visu/player.png", NULL);
    player->pos = (sfVector2f){184, 205};
    player->rec_pos = (sfFloatRect){184, 205, 4, 11};
    sfSprite_setTexture(player->sprite, player->tex, 1);
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setScale(player->sprite, (sfVector2f){0.008, 0.008});
    return player;
}

ingame_t *init_ingame(void)
{
    ingame_t *ingame = malloc(sizeof(ingame_t));

    ingame->back = sfSprite_create();
    ingame->tex = sfTexture_createFromFile("visu/house.png", NULL);
    sfSprite_setTexture(ingame->back, ingame->tex, 1);
    ingame->camera = init_camera();
    ingame->player = init_player();
    ingame->walls = init_walls();
    return ingame;
}

void clear_ingame(ingame_t *ingame)
{
    sfSprite_destroy(ingame->back);
    sfTexture_destroy(ingame->tex);
    sfView_destroy(ingame->camera->view);
    free(ingame->camera);
    sfSprite_destroy(ingame->player->sprite);
    sfTexture_destroy(ingame->player->tex);
    free(ingame->player);
    for (int i = 0; ingame->walls[i] != NULL; i++)
        free(ingame->walls[i]);
    free(ingame->walls);
    free(ingame);
}
