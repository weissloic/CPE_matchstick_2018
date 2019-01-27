/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

unsigned my_atoui(char *str)
{
    unsigned  res;

    res = 0;
    while ((*str >= '0') && (*str <= '9')) {
        res *= 10;
        res += *str - '0';
        str++;
    }
    return (res);
}

int my_atoi(char *str)
{
    int neg;

    neg = 0;
    while (*str == '-' || *str == '+') {
        if (*str == '-')
            neg = !neg;
        str++;
    }
    if (neg)
        return (-((int) my_atoui(str)));
    else
        return ((int) my_atoui(str));
}

int my_str_isnum(char const *str)
{
    if (*str == '-')
        str++;
    while (*str) {
        if ((*str < '0' || '9' < *str) && *str != '\n')
            return (0);
        str++;
    }
    return (1);
}