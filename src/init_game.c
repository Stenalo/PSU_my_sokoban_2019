/*
** EPITECH PROJECT, 2019
** init_game
** File description:
** init all game parts
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>

void init_game(char **map, pos_t *pos)
{
    int i;
    char **array = map;

    initscr();
    clear();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    display_map(map);
    while (1) {
        i = getch();
        manage_keys(map, i, pos);
        if (i == ' ') {
            display_map(pos->map);
        }
    }
    endwin();
}

pos_t *init_position(char *map)
{
    pos_t *pos = malloc(sizeof(pos_t));

    if (!pos)
        return (NULL);
    pos->map = init_map(map);
    pos->x = 0;
    pos->y = 0;
    return (pos);
}