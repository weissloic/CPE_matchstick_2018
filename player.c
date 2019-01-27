/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

void function_turn1(array_t *array)
{
    if (getline(&array->line, &array->len, stdin) == -1) {
        my_printf("Error");
        return (84);
    }
    else if (array->line == NULL) {
        my_printf("zizi");
        return (0);
    }
    else if (my_str_isnum(array->line) != 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        function_turn(array);
        return;
    }
}

void function_turn2(array_t *array)
{
    if (array->number_match == 0) {
        my_printf("Error: you have to remove at least one match\n");
        function_turn(array);
        return;
    }
    else if (array->number_match > array->nb_stick) {
        my_printf("Error: not enough matches on this line\n");
        function_turn(array);
        return;
    }
    else if (array->number_match > array->stick_max) {
        (my_printf("Error: you cannot remove more than %d matches per turn\n",
        array->stick_max));
        function_turn(array);
        return;
    }
}

void function_turn3(array_t *array)
{
    if (array->number_line > array->nb_line) {
        my_printf("Error: this line is out of range\n");
        function_turn(array);
        return;
    }
    else if (array->number_line == 0) {
        my_printf("Error: this line is out of range\n");
        function_turn(array);
        return;
    }
    check_stick(array);
    my_printf("Matches: ");
    if (getline(&array->line, &array->len, stdin) == -1) {
        my_printf("Error");
        return (84);
    }
}

void function_turn(array_t *array)
{
    array->number_line = 0;
    array->number_match = 0;
    array->nb_stick = 0;
    my_printf("Line: ");
    function_turn1(array);
    array->number_line = my_atoi(array->line);
    function_turn3(array);
    array->number_match = my_atoi(array->line);
    if (my_str_isnum(array->line) != 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        function_turn(array);
        return;
    }
    else if (array->line == NULL) {
        my_printf("zizi");
        return (0);
    }
    array->nb_match_stock = array->number_match;
    function_turn2(array);
}

void player_turn2(array_t *array)
{
    if (getline(&array->line, &array->len, stdin) == -1) {
        my_printf("Error");
        return (84);
    }
    if (array->line == NULL) {
        my_printf("zizi");
        return (0);
    }
    array->number_line = my_atoi(array->line);
    if (my_str_isnum(array->line) != 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        function_turn(array);
        return;
    }
}