/*
** EPITECH PROJECT, 2019
** help
** File description:
** disp help
*/

#include "../include/sokoban.h"
#include "../include/my.h"

void help(void)
{
    my_putstr("USAGE\n\n     ./my_sokoban map\nDESCRIPTION\n     ");
    my_putstr("map  file representing the warehouse map, containing '#' for ");
    my_putstr("walls, \n           'p' for the layer, 'X' for boxes and 'O'");
    my_putstr(" for storage locations.\n");
}
