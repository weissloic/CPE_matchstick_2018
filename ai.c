/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

void player_turn3(array_t *array)
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

void player_turn4(array_t *array)
{
    check_stick(array);
    my_printf("Matches: ");
    if (getline(&array->line, &array->len, stdin) == -1) {
        printf("\nError: this line is out of range\n");
        return (84);
        function_turn(array);
        
    }
    else if (array->line == NULL) {
        my_printf("zizi");
        return (0);
    }
    if (my_str_isnum(array->line) != 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        return;
        function_turn(array);
    }
}

void player_turn(array_t *array)
{
    array->number_line = 0;
    array->number_match = 0;
    my_printf("Your turn:\n");
    my_printf("Line: ");
    player_turn2(array);
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
    player_turn4(array);
    array->number_match = my_atoi(array->line);
    array->nb_match_stock = array->number_match;
    player_turn3(array);
    return;
}

int function_line_sticknull(array_t *array)
{
    if (array->nb_stick == 0) {
        array->choose_line = rand() % array->nb_line + 1;
        array->number_line = array->choose_line;
        check_stick(array);
        function_line_sticknull(array);
    }
}

void ai_turn2(array_t *array)
{
    if (array->nb_stick == 0) {
        function_line_sticknull(array);
    }
    array->number_line = array->choose_line;
    if (array->number_stick == 0) {
        array->number_stick = rand() % array->stick_max + 1;
        if (array->number_stick > array->nb_stick)
            array->number_stick = array->nb_stick;
    }
    array->number_match = array->number_stick;
    array->nb_match_stock = array->number_match;
    (my_printf("AI removed %d match(es) from line %d\n",
    array->number_match, array->number_line));
}