/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** convert a int to a string
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *my_itoa(int nb)
{
    int i = 0;
    char *str = NULL;
    int size = 0;
    int sign = 0;

    if (nb < 0) {
        nb = -nb;
        sign = 1;
    }
    size = nbr_len(nb);
    str = malloc(sizeof(char) * (size + 2));
    for (i = 0; i != size; i++) {
        str[i] = (nb % 10 + '0');
        nb /= 10;
    }
    if (sign == 1)
        str[i++] = '-';
    str = my_revstr(str);
    return (str);
}
