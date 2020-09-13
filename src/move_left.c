/*
** EPITECH PROJECT, 2019
** move left
** File description:
** all the left movement of the player
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>

void move_box_left(char **map, pos_t *pos)
{
    if ((map[pos->x][pos->y - 2] == '#') ||
    (map[pos->x][pos->y - 2] == 'X')) {
        return;
    } else {
        map[pos->x][pos->y - 1] = 'P';
        map[pos->x][pos->y] = ' ';
        map[pos->x][pos->y - 2] = 'X';
    }
}

void solo_move_left1(char **map, pos_t *pos)
{
    map[pos->x][pos->y] = 'O';
    map[pos->x][pos->y - 1] = 'P';
}

void solo_move_left(char **map, pos_t *pos)
{
    map[pos->x][pos->y] = ' ';
    map[pos->x][pos->y - 1] = 'P';
}

void move_left(char **map, pos_t *pos)
{
    if (map[pos->x][pos->y - 1] != '#') {
        if (map[pos->x][pos->y - 1] == 'X') {
            move_box_left(map, pos);
        }
        else if (pos->map[pos->x][pos->y] == 'O'
        && map[pos->x][pos->y] == 'P') {
            solo_move_left1(map, pos);
        } else {
            solo_move_left(map, pos);
        }
    }
    display_map(map);
}
