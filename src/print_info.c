/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** print information
*/

#include "../include/graph.h"

void print_matrix(int **matrix, int size)
{
    my_putstr("matrix\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            my_put_nbr(matrix[i][j]);
        my_putchar('\n');
    }
}

void print_all_tunnels(int **tunnels, int size)
{
    my_putstr("#tunnels\n");
    for (int i = 0; i < size; i++) {
        my_put_nbr(tunnels[i][0]);
        my_putchar('-');
        my_put_nbr(tunnels[i][1]);
        my_putchar('\n');
    }
}

void print_all_rooms(char **rooms, int start, int end, int **xy)
{
    my_putstr("#rooms\n");
    for (int i = 0; rooms[i] != NULL; i++) {
        if (i == start)
            my_putstr("##start\n");
        if (i == end)
            my_putstr("##end\n");
        my_putstr(rooms[i]);
        my_putchar(' ');
        my_put_nbr(xy[i][0]);
        my_putchar(' ');
        my_put_nbr(xy[i][1]);
        my_putchar('\n');
    }
}

void print_robot_num(int robot_num)
{
    my_putstr("#number_of_robots\n");
    my_put_nbr(robot_num);
    my_putstr("\n");
}

static int print_player_move(amazed_t *info, int **paths, int end)
{
    int j = 0;
    int start = 0;

    for (int i = 0; i < info->nbr_robots; i++) {
        for (j = 0; paths[i][j] == -2; j++);
        if ((i + 1) == info->nbr_robots && paths[i][j] == -1)
            return 1;
        if (paths[i][j] != -1 && info->matrix.enter[paths[i][j]][0] == 0) {
            info->matrix.enter[paths[i][j]][0] = (paths[i][j] == end) ? 0 : 1;
            my_putstr((start == 0) ? "P" : " P");
            my_put_nbr(i + 1);
            my_putchar('-');
            my_putstr(info->rooms[paths[i][j]]);
            start = 1;
            paths[i][j] = -2;
        }
    }
    my_putchar('\n');
    return 0;
}

void print_moves(amazed_t *info, int **connections, int num_paths)
{
    int **array = malloc(sizeof(int *) * (info->nbr_robots + 1));
    int cont = 0;
    int status = 0;

    for (int i = 0; i < info->nbr_robots; i++) {
        array[i] = copy_array(connections[cont]);
        cont = (cont + 1 < num_paths) ? cont + 1 : 0;
    }
    array[info->nbr_robots] = NULL;
    my_putstr("#moves\n");
    while (status == 0) {
        status = print_player_move(info, array, info->end);
        for (int i = 0; i < info->matrix.size; i++)
            info->matrix.enter[i][0] = 0;
    }
}
