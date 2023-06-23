/*
** EPITECH PROJECT, 2023
** jam
** File description:
** play sound
*/

#include "jam.h"

void play_sound(game_t *game, sfSound *sound)
{
    if (SETTINGS->sound)
        sfSound_play(sound);
}
