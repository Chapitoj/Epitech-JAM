/*
** EPITECH PROJECT, 2023
** jam
** File description:
** init_walls
*/

#include "jam.h"

static sfFloatRect *init_wall(int left, int top, int width, int height)
{
    sfFloatRect *wall = malloc(sizeof(sfFloatRect));

    wall->left = left;
    wall->top = top;
    wall->width = width;
    wall->height = height;
    return wall;
}

static void add_walls(sfFloatRect **walls)
{
    walls[15] = init_wall(809, 155, 84, 57);
    walls[16] = init_wall(467, 459, 219, 59);
    walls[17] = init_wall(414, 505, 58, 30);
    walls[18] = init_wall(434, 356, 5, 110);
    walls[19] = init_wall(405, 334, 2, 77);
    walls[20] = init_wall(316, 334, 90, 3);
    walls[21] = init_wall(313, 334, 8, 68);
    walls[22] = init_wall(314, 401, 73, 2);
    walls[23] = init_wall(255, 526, 216, 9);
    walls[24] = init_wall(314, 422, 72, 4);
    walls[25] = init_wall(176, 413, 136, 46);
    walls[26] = init_wall(255, 459, 10, 74);
    walls[27] = init_wall(412, 447, 14, 60);
    walls[28] = init_wall(295, 251, 44, 12);
    walls[29] = init_wall(248, 323, 24, 55);
    walls[30] = init_wall(458, 395, 18, 21);
    walls[31] = init_wall(538, 339, 22, 27);
    walls[32] = init_wall(566, 358, 34, 35);
    walls[33] = init_wall(540, 367, 12, 41);
    walls[34] = init_wall(591, 306, 86, 3);
}

sfFloatRect **init_walls(void)
{
    sfFloatRect **walls = malloc(sizeof(sfFloatRect) * NB_WALLS + 1);

    walls[NB_WALLS] = NULL;
    walls[0] = init_wall(181, 316, 47, 174);
    walls[1] = init_wall(143, 328, 39, 58);
    walls[2] = init_wall(181, 279, 87, 12);
    walls[3] = init_wall(222, 222, 46, 70);
    walls[4] = init_wall(266, 222, 109, 14);
    walls[5] = init_wall(342, 211, 33, 15);
    walls[6] = init_wall(342, 162, 87, 22);
    walls[7] = init_wall(426, 162, 156, 51);
    walls[8] = init_wall(367, 214, 25, 62);
    walls[9] = init_wall(371, 272, 46, 4);
    walls[10] = init_wall(435, 272, 28, 4);
    walls[11] = init_wall(460, 215, 83, 58);
    walls[12] = init_wall(526, 275, 187, 18);
    walls[13] = init_wall(675, 336, 38, 182);
    walls[14] = init_wall(675, 273, 38, 35);
    add_walls(walls);
    return walls;
}
