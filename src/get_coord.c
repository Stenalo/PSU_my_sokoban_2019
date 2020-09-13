/*
** EPITECH PROJECT, 2019
** load map
** File description:
** in 2d
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>

int get_nb_lines(char *map)
{
    int count = 0;
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == '\n')
            count++;
        i++;
    }
    return (count);
}

int get_nb_col(char *map, int i)
{
    int count = 0;

    while (map[i] != '\n') {
        count++;
        i++;
    }
    return (count);
}
