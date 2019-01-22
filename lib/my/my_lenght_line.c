/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "my.h"

int len_line(char *map)
{
    int i = 0;
    while (map[i] != '\n')
        i++;
    return (i);
}