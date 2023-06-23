/*
** EPITECH PROJECT, 2023
** jam
** File description:
** set struct
*/

#ifndef SETTINGS_STRUCT_H
    #define SETTINGS_STRUCT_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "utils.h"

typedef struct settings_s {
    background_t *back;
    button_t *music_b;
    button_t *sound_b;
    sfBool sound;
    sfBool music;
    sfBool leave;
}settings_t;

#endif /* !SETTINGS_STRUCT_H */
