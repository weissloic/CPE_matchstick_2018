/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

int main (int ac, char **av)
{
    array_t *array = malloc(sizeof(array_t));
    norm_correct2(array);
    if (ac != 3)
        return (84);
    for (int i = 1; i != ac; i++) {
        if (my_str_isnum(av[i]) != 1)
            return (84);
    }
    game(array, av);
    while (1) {
        if (array->victory == 0 && array->player == 1) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return (1);
        } else if (array->victory == 0 && array->ai == 1) {
            my_printf("You lost, too bad...\n");
            return (2);
        }
        norm_correct(array);
    }
    return (0);
}

int game(array_t *array, char **av)
{
    array->counter = 0;
    array->nb_line = my_atoi(av[1]);
    array->stick_max = my_atoi(av[2]);
    array->nbcolumn = array->nb_line * 2;
    array->map = complete_map(array->nb_line, array->nbcolumn);
    array->line = NULL;
    array->len = 0;

    if (array->nb_line < 2 || array->nb_line > 99)
        return (84);

    if (array->stick_max < 1)
        return (84);

    print_map(array);
    check_stick_victory(array);
}

void player_or_ai(array_t *array)
{
    if (array->ai == 1) {
        ai_turn(array);
        array->ai = 0;
        erase_stick(array);
        print_map(array);
        array->player = 1;
        check_stick_victory(array);
    }
    else if (array->player == 1) {
        player_turn(array);
        (my_printf("Player removed %d match(es) from line %d\n",
        array->number_match, array->number_line));
        array->player = 0;
        erase_stick(array);
        print_map(array);
        check_stick_victory(array);
        array->ai = 1;
    }
}

void norm_correct(array_t *array)
{
    player_or_ai(array);
    array->number_match = 0;
    array->number_line = 0;
    array->nb_stick = 0;
}

void norm_correct2(array_t *array)
{
    array->player = 1;
    array->ai = 0;
}