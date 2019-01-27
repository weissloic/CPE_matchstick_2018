/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

char **stars_print(int nb_line, int nbcolumn)
{
    char **map = malloc(sizeof(char *) * nb_line + 3);

    for (int i = 0; i < nb_line + 2; i++)
        map[i] = malloc(sizeof(char) * (nbcolumn + 1));

    for (int i = 0; i < nb_line + 2; i++) {
        for (int y = 0; y < nbcolumn + 1; y++) {
            if (i == 0 || i == nb_line + 1)
                map[i][y] = '*';
            if (i != 0 && i != nb_line + 1) {
                map[i][0] = '*';
                map[i][y] = ' ';
                map[i][nbcolumn] = '*';
            }
        }
    }
    return (map);
}

char **print_my_pipe(int nb_line, char **map)
{
    int pipe = nb_line;
    int space = nb_line;
    int total = nb_line * 2;
    int a = nb_line;

    for (int j = 1; j != nb_line + 1; j++) {
        for (int y = 0; y != total + 1; y++) {
            if (y >= space && y <= pipe)
                map[j][y] = '|';
        }
        pipe++;
        space--;
    }
    return (map);
}

char **complete_map(int nb_line, int nbcolumn)
{
    char **map = stars_print(nb_line, nbcolumn);
    map = print_my_pipe(nb_line, map);
    return (map);
}