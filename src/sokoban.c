/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** main function
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <unistd.h>

void free_memory(char *map, char **array, pos_t *pos)
{
    if (map != NULL)
        free(map);
    if (array != NULL)
        free(array);
    if (pos != NULL)
        free(pos);
}

int sokoban(int ac, char **av)
{
    char *map;
    char **array;
    pos_t *pos;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
        return (0);
    }
    if (parse_map(av) == false) {
        return (EXIT_ERROR);
    }
    map = load_map(av[1]);
    pos = init_position(map);
    array = init_map(map);
    init_game(array, pos);
    free_memory(map, array, pos);
    return (0);
}