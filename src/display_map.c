/*
** EPITECH PROJECT, 2019
** display_map
** File description:
** just display the map
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>

void display_map(char **map)
{
    erase();
    for (int i = 0; map[i]; i++) {
        printw(map[i]);
    }
    refresh();
}