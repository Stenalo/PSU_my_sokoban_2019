/*
** EPITECH PROJECT, 2019
** move down
** File description:
** all the down movement of the player
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>

void move_box_down(char **map, pos_t *pos)
{
    if ((map[pos->x + 2][pos->y] == '#') ||
    (map[pos->x + 2][pos->y] == 'X')) {
        return;
    } else {
        map[pos->x + 1][pos->y] = 'P';
        map[pos->x][pos->y] = ' ';
        map[pos->x + 2][pos->y] = 'X';
    }
}

void solo_move_down1(char **map, pos_t *pos)
{
    map[pos->x][pos->y] = 'O';
    map[pos->x + 1][pos->y] = 'P';
}

void solo_move_down(char **map, pos_t *pos)
{
    map[pos->x][pos->y] = ' ';
    map[pos->x + 1][pos->y] = 'P';
}

void move_down(char **map, pos_t *pos)
{
    if (map[pos->x + 1][pos->y] != '#') {
        if (map[pos->x + 1][pos->y] == 'X') {
            move_box_down(map, pos);
        } else if (pos->map[pos->x][pos->y] == 'O'
        && map[pos->x][pos->y] == 'P') {
            solo_move_down1(map, pos);
        } else {
            solo_move_down(map, pos);
        }
    }
    display_map(map);
}
