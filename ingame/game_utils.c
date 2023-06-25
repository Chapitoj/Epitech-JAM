/*
** EPITECH PROJECT, 2023
** jam
** File description:
** game utils
*/

#include "jam.h"
#include "ingame.h"
#include <time.h>

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

static void generate_vect(player_t *player, sfFloatRect **walls)
{
    sfFloatRect *tmp = malloc(sizeof(sfFloatRect));

    player->rec_pos.left = (rand() % (PRIGHT - PLEFT + 1)) + PLEFT;
    player->rec_pos.top = (rand() % (PDWON - PUP + 1)) + PUP;
    tmp->height = player->rec_pos.height;
    tmp->left = player->rec_pos.left;
    tmp->top = player->rec_pos.top;
    tmp->width = player->rec_pos.width;
    while (is_in_wall(tmp, walls)) {
        player->rec_pos.left = (rand() % (PRIGHT - PLEFT + 1)) + PLEFT;
        player->rec_pos.top = (rand() % (PDWON - PUP + 1)) + PUP;
        tmp->left = player->rec_pos.left;
        tmp->top = player->rec_pos.top;
    }
    free(tmp);
}

static player_t *init_player(sfFloatRect **walls)
{
    player_t *player = malloc(sizeof(player_t));

    player->sprite = sfSprite_create();
    player->tex = sfTexture_createFromFile("visu/player.png", NULL);
    player->rec_pos = (sfFloatRect){0, 0, 4, 11};
    generate_vect(player, walls);
    player->pos = (sfVector2f){player->rec_pos.left, player->rec_pos.top};
    player->buff = sfSoundBuffer_createFromFile("visu/kill.wav");
    player->sound = sfSound_create();
    sfSound_setBuffer(player->sound, player->buff);
    sfSprite_setTexture(player->sprite, player->tex, 1);
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setScale(player->sprite, (sfVector2f){0.008, 0.008});
    return player;
}

ingame_t *init_ingame(void)
{
    ingame_t *ingame = malloc(sizeof(ingame_t));

    srand(time(NULL));
    ingame->back = sfSprite_create();
    ingame->tex = sfTexture_createFromFile("visu/house.png", NULL);
    sfSprite_setTexture(ingame->back, ingame->tex, 1);
    ingame->camera = init_camera();
    ingame->walls = init_walls();
    ingame->player = init_player(ingame->walls);
    ingame->family = init_family(ingame->walls);
    ingame->clock = sfClock_create();
    ingame->move = sfClock_create();
    ingame->time = 0;
    ingame->ath = sfTrue;
    ingame->kills = 0;
    ingame->police = init_police();
    init_sounds(ingame);
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
    sfSound_destroy(ingame->player->sound);
    sfSoundBuffer_destroy(ingame->player->buff);
    free(ingame->player);
    for (int i = 0; ingame->walls[i] != NULL; i++)
        free(ingame->walls[i]);
    free(ingame->walls);
    for (int i = 0; ingame->family[i] != NULL; i++) {
        sfSprite_destroy(ingame->family[i]->sprite);
        sfTexture_destroy(ingame->family[i]->tex);
        free(ingame->family[i]->rec);
        free(ingame->family[i]);
    }
    free(ingame->family);
    free(ingame);
}
