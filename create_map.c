/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

/*void create_char(array_t *array)
{
    for (int u = 0; u <  (array->number_atoi * 2) + 1; u++) {
        array->first_line[0][u] = '*';
        my_printf("%c", array->first_line[0][u]);
    }
    my_printf("\n");
}

void create_char_horizontaly(array_t *array)
{
    int test = 0;
    int e = 2;
    int temp = ((array->number_atoi * 2 + 2) / 2);
    int incrementation = 0;
    int temp_up = ((array->number_atoi * 2 + 2) / 2);
    int h = 0;
    int max_value = 0;

    for (int p = 1; p <  (array->number_atoi + 1); p++) {
        for (int u = 1; u <  (array->number_atoi * 2 + 1)  ; u++) {
            array->first_line[p][u] = ' ';
            array->first_line[p][temp] = '|';
            max_value = temp + incrementation;

            //////DROIIITTTEEE
            array->first_line[e + 1][max_value] = '|';
            /////GGGAAAUUUCHHEEE
            array->first_line[e + 1][temp - incrementation] = '|';

            array->first_line[p][1] = '*';
            //array->first_line[p][incrementation] = 'o';
            my_printf("%c", array->first_line[p][u]);
            array->lenght_array = u;
            test = array->lenght_array;
        }
        array->first_line[p][test] = '*';
        e = p;colul
        my_printf("%c", array->first_line[p][test]);
        incrementation++;
        my_printf("\n");
    }
}

void create_char_two(array_t *array)
{
    for (int u = 0; u <  (array->number_atoi * 2) + 1 ; u++) {
        array->first_line[0][u] = '*';
        my_printf("%c", array->first_line[0][u]);
    }
    my_printf("\n");
}*/

char **stars_print(int nb_line, int nbcolumn)
{
    char **map = malloc(sizeof(char *) * nb_line + 3);

    int a = 0;
    int b = 0;

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

    for (int j = 1; j!= nb_line + 1; j++) {
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