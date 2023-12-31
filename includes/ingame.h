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
    sfSoundBuffer *buff;
    sfSound *sound;
}player_t;

typedef struct unit_s {
    sfTexture *tex;
    sfSprite *sprite;
    sfFloatRect *rec;
    sfBool alive;
}unit_t;

typedef struct police_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfFloatRect *rect;
    double speed;
    sfSoundBuffer *buff;
    sfSound *sound;
    sfBool called;
}police_t;

typedef struct ingame_s {
    sfSprite *back;
    sfTexture *tex;
    camera_t *camera;
    sfMusic *music;
    player_t *player;
    unit_t **family;
    sfFloatRect **walls;
    sfClock *clock;
    sfClock *move;
    int time;
    int kills;
    sfBool ath;
    police_t *police;
    sfClock *stop;
    sfSound *shout;
    sfSoundBuffer *buffsh;
    sfSound *timer;
    sfSoundBuffer *bufft;
}ingame_t;

#endif /* !INGAME_H */
