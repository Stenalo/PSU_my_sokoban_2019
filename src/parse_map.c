/*
** EPITECH PROJECT, 2019
** parse_map
** File description:
** all map check
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>

int char_is_correct(char c)
{
    if (c == ' ' || c == '\n' || c == '#'
        || c == 'X' || c == 'O' || c == 'P')
        return (1);
    return (0);
}

bool check_map(char *map)
{
    int i = 0;
    int col = 0;

    for (int line = 1; map && map[i]; i++) {
        if (char_is_correct(map[i]) == 0)
            return (false);
        if (map[i] == '\n')
            line += col;
    }
    if (i == 0)
        return (false);
    return (true);
}

bool parse_map(char **av)
{
    int fd = 0;
    struct stat info;
    char *map;

    fd = open(av[1], O_RDONLY);
    if (fd < 0 || stat(av[1], &info) < 0)
        return (false);
    map = malloc(sizeof(char) * (info.st_size) + 1);
    if (!map) {
        close(fd);
        return (false);
    }
    read(fd, map, info.st_size + 1);
    map[info.st_size] = '\0';
    return (check_map(map));
}
