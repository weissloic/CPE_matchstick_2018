/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** my_revstr
*/

#include "my.h"

int my_strlen2(char const *str)
{
    int counter = 0;

    while (str[counter])
        counter++;
    return (counter);
}

char *my_revstr(char *str)
{
    int counter = my_strlen2(str) - 1;
    int i = 0;
    char temp;

    while (i < counter) {
        temp = str[i];
        str[i] = str[counter];
        str[counter] = temp;
        counter--;
        i++;
    }
    return (str);
}