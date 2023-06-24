/*
** EPITECH PROJECT, 2023
** jam
** File description:
** convert time
*/

#include "jam.h"

static void add_min(char *time, int min)
{
    if (min >= 10) {
        time[0] = (min / 10) % 10 + '0';
        time[1] = min - (time[3] - '0') * 10 + '0';
    } else {
        time[0] = '0';
        time[1] = min + '0';
    }
}

static void add_sec(char *time, int sec)
{
    if (sec >= 10) {
        time[3] = (sec / 10) % 10 + '0';
        time[4] = sec - (time[3] - '0') * 10 + '0';
    }else {
        time[3] = '0';
        time[4] = sec + '0';
    }
}

char *convert_time(int seconds)
{
    char *time = malloc(sizeof(char) * 6);
    int sec = seconds % 60;
    int min = seconds / 60;

    add_min(time, min);
    time[2] = ':';
    add_sec(time, sec);
    time[5] = '\0';
    return time;
}
