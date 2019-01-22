/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "my.h"

void conevrt_intchar(int nb, char *str)
{
    int i = 0;
    int sign = nb;

    if (sign < 0)
        nb = -nb;
    str[i++] = nb % 10 + '0';
    while ((nb /= 10) > 0){
        str[i++] = nb % 10 + '0';
    }
    str[i] = '\0';
    my_revstr(str);
}