/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/


#include "include/my.h"

unsigned    my_atoui(char *str)
{
  unsigned  res;

  res = 0;
  while ((*str >= '0') && (*str <= '9'))
    {
      res *= 10;
      res += *str - '0';
      str++;
    }
  return (res);
}

int my_atoi(char *str)
{
  int   neg;

  neg = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
    neg = !neg;
      str++;
    }
  if (neg)
    return (-((int) my_atoui(str)));
  else
    return ((int) my_atoui(str));
}




void my_error(array_t *array_char, char **av)
{
    if (array_char->number_atoi <= 0)
        return (84);
}

int my_str_isnum(char const *str)
{
    if (*str == '-')
        str++;
    while (*str) {
        if (*str < '0' || '9' < *str)
            return (0);
      str++;
    }
  return (1);
}

int main (int ac, char **av)
{
    array_t *array = malloc(sizeof(array_t));



    array->nb_line = my_atoi(av[1]);
    array->nbcolumn = array->nb_line * 2;
    int i = 1;
    int e = 0;
    array->counter = 0;
    array->map = complete_map(array->nb_line, array->nbcolumn);
    char *line = NULL;
    size_t len = 0;

    if (ac != 3)
        return (84);

    if (array->nb_line < 2 || array->nb_line > 99)
        return(84);

    while (i != ac) {
        if (my_str_isnum(av[i]) != 1)
            return (84);
        i++;
    }

    for (int i = 0; i != array->nb_line + 2; i++)
        printf("%s\n", array->map[i]);
    printf("Your turn:\n");
    while (1) {
        if (getline(&line, &len, stdin) == -1) {
            printf("Error");
            return (84);
        } else {
            array->number_line = my_atoi(line);
            if (array->number_line > array->nb_line) {
              getline(&line, &len, stdin);
              array->number_line = my_atoi(line);
            }

            if (getline(&line, &len, stdin) == -1) {
                printf("Error");
              } else {
                  array->number_match = my_atoi(line);

                }
            printf("Line = %d\n", array->number_line);
            printf("Matche = %d\n", array->number_match);
            erase_stick(array);
            print_map(array);
        }
    }
    return (0);
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
                printf("%s\n", array->map[i]);
}
