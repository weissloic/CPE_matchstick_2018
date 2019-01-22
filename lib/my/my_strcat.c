/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *s1, char *s2)
{
    int i = 0;
    int a = 0;
    char *new = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    if (s1 != NULL) {
        while (s1[i] != '\0') {
            new[i] = s1[i];
            i++;
        }
    }
    if (s2 != NULL) {
        while (s2[a] != '\0') {
            new[i] = s2[a];
            i++;
            a++;
        }
    }
    return (new);
}