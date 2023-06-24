/*
** EPITECH PROJECT, 2023
** jam
** File description:
** game
*/

#ifndef INGAME_H
    #define INGAME_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct camera_s {
    sfVector2f position;
    sfView *view;
    sfFloatRect res_rect;
}camera_t;

typedef struct player_s {
    sfTexture *tex;
    sfSprite *sprite;
    sfVector2f pos;
    sfFloatRect rec_pos;
}player_t;

typedef struct ingame_s {
    sfSprite *back;
    sfTexture *tex;
    camera_t *camera;
    sfMusic *music;
    player_t *player;
    sfFloatRect **walls;
}ingame_t;

#endif /* !INGAME_H */
