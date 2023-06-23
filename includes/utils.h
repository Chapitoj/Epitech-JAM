/*
** EPITECH PROJECT, 2023
** jam
** File description:
** utils
*/

#ifndef UTILS_H
    #define UTILS_H

    #include <SFML/Graphics.h>

enum button_state {
    NONE = 0 ,
    HOVER ,
    PRESSED
};

typedef struct dimensions_s {
    sfVector2f size;
    sfVector2f pos;
}dimensions_t;

typedef struct button_s {
    sfRectangleShape *r;
    sfTexture *t;
    sfTexture *hover_t;
    sfVector2f size;
    sfVector2f pos;
    enum button_state state;
}button_t;

typedef struct background_s {
    sfTexture *t;
    sfSprite *s;
}background_t;

typedef struct cursor_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSoundBuffer *buffer;
    sfSound *sound;
}cursor_t;

#endif /* !UTILS_H */
