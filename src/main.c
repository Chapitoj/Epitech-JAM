/*
** EPITECH PROJECT, 2023
** jam
** File description:
** main
*/

#include "jam.h"

int main(int ac, char **av)
{
    game_t *game = NULL;

    if (ac != 1 || av[0] == NULL)
        return 84;
    game = init_game();
    sfRenderWindow_setMouseCursorVisible(WINDOW, sfFalse);
    menu_handler(game);
    clear_game(game);
    return 0;
}
