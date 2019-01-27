/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

void ai_turn(array_t *array)
{
    int i = 0;
    array->number_stick = 0;
    time_t t;
    time_t stick;
    my_printf("AI's turn...\n");
    srand((unsigned) time(&t));

    array->choose_line = rand() % array->nb_line + 1;

    if (array->choose_line == 0) {
        array->choose_line = rand() % array->nb_line + 1;
    }
    array->number_line = array->choose_line;
    check_stick(array);
    ai_turn2(array);
}

void check_stick(array_t *array)
{
    int i = 1;
    array->nb_stick = 0;
    while (array->map[array->number_line][i] != '*') {
        if (array->map[array->number_line][i] == '|') {
            array->nb_stick++;
        }
    i++;
    }
}

void check_stick_victory(array_t *array)
{
    int i = 1;
    array->victory = 0;
    array->number_line = 1;
    while (array->number_line != array->nb_line + 1) {
        while (array->map[array->number_line][i] != '*') {
            if (array->map[array->number_line][i] == '|') {
                array->victory++;
            }
        i++;
        }
    i = 1;
    array->number_line++;
    }
}

void erase_stick(array_t *array)
{
    while (array->map[array->number_line][array->nbcolumn] != '|')
        array->nbcolumn--;
    while (array->number_match != 0) {
        array->map[array->number_line][array->nbcolumn] = ' ';
        array->nbcolumn--;
        array->number_match--;
    }
    array->nbcolumn = array->nb_line * 2;
}

void print_map(array_t *array)
{
    for (int i = 0; i != array->nb_line + 2; i++)
        my_printf("%s\n", array->map[i]);
}