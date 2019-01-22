/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmpr(char *s1, char *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}