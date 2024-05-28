/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** headerfile
*/

#include "../include/graph.h"

static int count_solutions_path(int **matrix, int matrix_size, int pos)
{
    int cont = 0;

    for (int i = 0; i < matrix_size; i++)
        if (matrix[pos][i] == 1)
            cont++;
    return cont;
}

static void init_connections(int **array, int size, int wanted)
{
    for (int i = 0; i < size; i++) {
        array[i] = malloc(sizeof(int) * ((wanted * wanted) + 1));
        for (int j = 0; j < (wanted * wanted); j++)
            array[i][j] = -1;
    }
}

int get_shortest_pos(int *array, int size)
{
    int cont = 0;
    int value = 0;

    if (array == NULL)
        return 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == 0)
            continue;
        if (cont == 0) {
            value = array[i];
            cont = i;
        }
        if (value > array[i]) {
            value = array[i];
            cont = i;
        }
    }
    return cont;
}

static int *create_path(int **matrix, int matrix_size, int start)
{
    int path_len = search_for_smallest_one(matrix[start], matrix_size);
    int row = start;
    int *array = malloc(sizeof(int) * (path_len + 1));
    int cont = 0;

    if (path_len == 0)
        return NULL;
    for (int i = 0; i < path_len; i++) {
        array[cont] = get_shortest_pos(matrix[row], matrix_size);
        row = array[cont];
        cont++;
    }
    array[path_len] = -1;
    return array;
}

void clear_matrix(amazed_t *info, int **matrix_enter, int **matrix,
    int *array)
{
    if (array == NULL)
        return;
    for (int i = 0; i < info->matrix.size; i++)
        for (int j = 0; j < info->matrix.size; j++)
            matrix_enter[i][j] = 0;
    if (array == NULL)
        return;
    for (int i = 0; array[i] != info->end; i++) {
        for (int j = 0; j < info->matrix.size; j++) {
            matrix[array[i]][j] = 0;
            matrix[j][array[i]] = 0;
        }
    }
}

int *copy_array(int *array)
{
    int length = 0;
    int *new = NULL;

    for (int i = 0; array[i] != -1; i++)
        length++;
    new = malloc(sizeof(int) * (length + 1));
    for (int i = 0; array[i] != -1; i++) {
        new[i] = array[i];
    }
    new[length] = -1;
    return new;
}

int algorithm(amazed_t *info)
{
    int pos_paths = count_solutions_path(info->matrix.matrix,
        info->matrix.size, info->end);
    int **connections = malloc(sizeof(int *) * (pos_paths + 1));
    int cont = 0;

    connections[pos_paths] = NULL;
    init_connections(connections, pos_paths, info->matrix.size);
    for (int i = 0; i < pos_paths; i++) {
        dijisktra(info, info->end);
        connections[cont] = create_path(info->matrix.enter,
            info->matrix.size, info->start);
        clear_matrix(info, info->matrix.enter, info->matrix.matrix,
            connections[cont]);
        cont += (connections[cont] != NULL) ? 1 : 0;
    }
    if (connections[0] == NULL)
        return ERROR;
    clear_matrix(info, info->matrix.enter, info->matrix.matrix, NULL);
    print_moves(info, connections, cont);
    return 0;
}
