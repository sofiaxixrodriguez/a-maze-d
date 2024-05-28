/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** headerfile
*/

#include "../include/graph.h"

void free_amazed(amazed_t *amazed)
{
    for (int i = 0; amazed->rooms[i] != NULL; i++)
        free(amazed->xy[i]);
    for (int i = 0; i < amazed->size_tun; i++)
        free(amazed->tunnels[i]);
    for (int i = 0; amazed->rooms[i] != NULL; i++)
        free(amazed->rooms[i]);
    free(amazed->rooms);
    free(amazed->tunnels);
    free(amazed);
}

int main(int ac, char **av)
{
    amazed_t *info = malloc(sizeof(amazed_t));
    int status = 0;

    (void)av;
    if (ac != 1 || parsing(info) == ERROR)
        return 84;
    status = algorithm(info);
    free_amazed(info);
    return (status == ERROR) ? 84 : 0;
}
