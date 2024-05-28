/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** my str to word array
*/

#include "../include/graph.h"

int fill_rooms(parse_t *parse, amazed_t *info)
{
    int cont = 0;

    info->end = -1;
    info->start = -1;
    for (rooms_t *rooms = parse->rooms; rooms != NULL; rooms = rooms->next) {
        if (rooms->start == true && info->start != -1)
            return ERROR;
        if (rooms->end == true && info->end != -1)
            return ERROR;
        if (rooms->start == true && info->start == -1)
            info->start = cont;
        if (rooms->end == true && info->end == -1)
            info->end = cont;
        info->rooms[cont] = my_strdup(rooms->name);
        info->xy[cont] = malloc(sizeof(int) * 2);
        info->xy[cont][0] = rooms->xy[0];
        info->xy[cont][1] = rooms->xy[1];
        cont++;
    }
    return 0;
}

int name_pos(char **names, int name)
{
    for (int i = 0; names[i] != NULL; i++)
        if (get_nat_nbr(names[i]) == name)
            return i;
    return -1;
}

int fill_tunnels(parse_t *parse, amazed_t *info)
{
    int cont = 0;
    int x = 0;
    int y = 0;

    info->size_tun = parse->nbr_tunnels;
    for (tunnels_t *tun = parse->tunnel; tun != NULL; tun = tun->next) {
        info->tunnels[cont] = malloc(sizeof(int) * 2);
        info->tunnels[cont][0] = tun->connection1;
        info->tunnels[cont][1] = tun->connection2;
        x = name_pos(info->rooms, tun->connection1);
        y = name_pos(info->rooms, tun->connection2);
        if (x == -1 || y == -1)
            return ERROR;
        info->matrix.matrix[x][y] = 1;
        info->matrix.matrix[y][x] = 1;
        cont++;
    }
    return 0;
}

int fill_enter(amazed_t *info)
{
    info->matrix.enter = malloc(sizeof(int *) * (info->matrix.size + 1));
    for (int j = 0; j < info->matrix.size; j++) {
        info->matrix.enter[j] = malloc(sizeof(int) * (info->matrix.size + 1));
        for (int k = 0; k < info->matrix.size; k++)
            info->matrix.enter[j][k] = 0;
    }
    return 0;
}

int fill_amazed(parse_t *parse, amazed_t *info)
{
    int status = 0;

    info->nbr_robots = parse->n_robots;
    info->rooms = malloc(sizeof(char *) * (parse->nbr_rooms + 1));
    info->xy = malloc(sizeof(int *) * parse->nbr_rooms);
    status = fill_rooms(parse, info);
    if (status != 0 || info->start == -1 || info->end == -1)
        return ERROR;
    info->tunnels = malloc(sizeof(int *) * parse->nbr_tunnels);
    info->matrix.matrix = malloc(sizeof(int *) * (parse->nbr_rooms));
    info->matrix.size = parse->nbr_rooms;
    for (int i = 0; i < parse->nbr_rooms && info->matrix.matrix != NULL; i++) {
        info->matrix.matrix[i] = malloc(sizeof(int) * parse->nbr_rooms);
        for (int j = 0; j < parse->nbr_rooms; j++)
            info->matrix.matrix[i][j] = 0;
    }
    status = (status == 0) ? fill_tunnels(parse, info) : status;
    status = (status == 0) ? fill_enter(info) : status;
    return status;
}
