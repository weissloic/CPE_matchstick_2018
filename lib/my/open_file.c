/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "my.h"

char *open_file(char *path)
{
    init_map_t *init_map = malloc(sizeof(init_map_t));

    init_map->buffer = NULL;
    init_map->file = NULL;

    init_map->fd = open(path, O_RDONLY);
    if (init_map->fd == -1)
        return (84);
    init_map->buffer = malloc(sizeof(char) * 10000);
    while ((init_map->ret = read(init_map->fd, init_map->buffer, 10000)) != 0) {
        init_map->buffer[init_map->ret] = '\0';
        init_map->file = my_strcat(init_map->file, init_map->buffer);
    }
    return (init_map->file);
}