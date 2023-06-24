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

ingame_t *init_ingame(void)
{
    ingame_t *ingame = malloc(sizeof(ingame_t));

    ingame->back = sfSprite_create();
    ingame->tex = sfTexture_createFromFile("visu/house.png", NULL);
    sfSprite_setTexture(ingame->back, ingame->tex, 1);
    ingame->camera = init_camera();
    return ingame;
}

void clear_ingame(ingame_t *ingame)
{
    sfSprite_destroy(ingame->back);
    sfTexture_destroy(ingame->tex);
    sfView_destroy(ingame->camera->view);
    free(ingame->camera);
    free(ingame);
}
