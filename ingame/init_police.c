/*
** EPITECH PROJECT, 2023
** jam
** File description:
** init_police
*/

#include "jam.h"

void init_sounds(ingame_t *ingame)
{
    ingame->buffsh = sfSoundBuffer_createFromFile("visu/stop.wav");
    ingame->bufft = sfSoundBuffer_createFromFile("visu/clock.wav");
    ingame->shout = sfSound_create();
    ingame->timer = sfSound_create();
    ingame->stop = sfClock_create();
    sfSound_setBuffer(ingame->shout, ingame->buffsh);
    sfSound_setBuffer(ingame->timer, ingame->bufft);
}

police_t *init_police(void)
{
    police_t *p = malloc(sizeof(police_t));

    p->texture = sfTexture_createFromFile("visu/police.png", NULL);
    p->sprite = sfSprite_create();
    p->speed = 100000.0;
    p->buff = sfSoundBuffer_createFromFile("visu/police.wav");
    p->sound = sfSound_create();
    p->rect = malloc(sizeof(sfFloatRect));
    p->rect->height = 10;
    p->rect->width = 5;
    p->rect->left = rand() % 1000;
    p->rect->top = 50;
    p->called = sfFalse;
    sfSprite_setTexture(p->sprite, p->texture, 1);
    sfSprite_setScale(p->sprite, (sfVector2f){0.01, 0.009});
    sfSprite_setPosition(p->sprite, (sfVector2f){100, 50});
    sfSound_setBuffer(p->sound, p->buff);
    sfSound_setVolume(p->sound, 70);
    return p;
}
