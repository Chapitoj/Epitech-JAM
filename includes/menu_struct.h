/*
** EPITECH PROJECT, 2023
** jam
** File description:
** menu struct
*/

#ifndef MENU_STRUCT_H
    #define MENU_STRUCT_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "utils.h"

typedef struct menu_s {
    sfBool leave;
    background_t *back;
    button_t *play_b;
    button_t *settings_b;
    button_t *quit_b;
    sfMusic *music;
}menu_t;

#endif /* !MENU_STRUCT_H */
