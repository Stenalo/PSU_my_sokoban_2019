/*
** EPITECH PROJECT, 2019
** get_player
** File description:
** get player position
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>

void check_player(int i, int j, pos_t *pos, char **map)
{
    if (map[i][j] == 'P') {
        pos->x = i;
        pos->y = j;
    }
}

void get_player(char **map, pos_t *pos)
{
    int i = 0;
    int j = 0;

    for (i = 0; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\n'; j++) {
            check_player(i, j, pos, map);
        }
    }
}