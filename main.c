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
    //array_t *array = malloc(sizeof(array_t));



    int nb_line = my_atoi(av[1]);
    int nbcolumn = nb_line * 2;
    int i = 1;

    if (ac != 3)
        return (84);

    if (nb_line < 2 || nb_line > 99)
        return(84);

    while (i != ac) {
        if (my_str_isnum(av[i]) != 1)
            return (84);
        i++;
    }

    char **map = complete_map(nb_line, nbcolumn);
    char *line = NULL;
    size_t len = 0;

    for (int i = 0; i != nb_line + 2; i++)
        printf("%s\n", map[i]);

    if (getline(&line, &len, stdin) == -1) {
        printf("Error");
        return (84);

    } else {
        int y = my_atoi(line);
        //if (my_str_isnum(line) != 1)
        //    return (84);
        printf("%d\n", y);
    }
    return (0);
}