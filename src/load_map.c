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

char *load_map(char const *path)
{
    int fd = 0;
    struct stat info;
    char *map = NULL;

    fd = open(path, O_RDONLY);
    if (fd < 0 || stat(path, &info) < 0)
        return (false);
    map = malloc(sizeof(char) * (info.st_size) + 1);
    if (!map) {
        close(fd);
        return (false);
    }
    read(fd, map, info.st_size + 1);
    map[info.st_size] = '\0';
    return (map);
}

char **create_map(char *map)
{
    int nb_lines = get_nb_lines(map);
    char **array = malloc(sizeof(char *) * nb_lines + 1);
    int i = 0;

    if (!array)
        return (NULL);
    for (i = 0; i < nb_lines; i++) {
        array[i] = malloc(sizeof(char) * get_nb_col(map, i) + 1);
        if (!array[i])
            return (NULL);
    }
    array[i] = 0;
    return (array);
}

void copy_str_to_array(char **array, char *str)
{
    int k = 0;

    for (int i = 0, j = 0; str && str[i]; i++) {
        if ((str[i]) == '\n') {
            array[k][j] = '\n';
            k++;
            j = 0;
        }
        else {
            array[k][j] = str[i];
            j++;
        }
    }
    array[k + 1] = NULL;
}

char **init_map(char *map)
{
    char **array = create_map(map);

    if (!array)
        return (NULL);
    copy_str_to_array(array, map);
    return (array);
}
