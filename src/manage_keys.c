/*
** EPITECH PROJECT, 2019
** manage
** File description:
** keys
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>

void manage_keys(char **map, int i, pos_t *pos)
{
    get_player(map, pos);
    if (i == KEY_DOWN)
        move_down(map, pos);
    if (i == KEY_UP)
        move_up(map, pos);
    if (i == KEY_LEFT)
        move_left(map, pos);
    if (i == KEY_RIGHT)
        move_right(map, pos);
}
