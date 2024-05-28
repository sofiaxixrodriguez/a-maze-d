/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** headerfile
*/

#include "../include/graph.h"

int search_for_smallest_one(int *array, int size)
{
    int cont = 0;

    if (array == NULL)
        return 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == 0)
            continue;
        if (cont == 0)
            cont = array[i];
        if (cont > array[i])
            cont = array[i];
    }
    return cont;
}

void change_matrix_enter(int **matrix, int value, int x, int y)
{
    matrix[x][y] = value;
    matrix[y][x] = value;
}

void change_enter(amazed_t *info, int row, int i, int value)
{
    change_matrix_enter(info->matrix.enter, value, row, i);
    change_matrix_enter(info->matrix.matrix, 0, row, i);
    dijisktra(info, i);
    change_matrix_enter(info->matrix.matrix, 1, row, i);
}

int dijisktra(amazed_t *info, int row)
{
    int sh = search_for_smallest_one(info->matrix.enter[row],
        info->matrix.size);
    int value = 0;

    if (row == info->start)
        return 0;
    if (row != info->end && sh == 0)
        return 0;
    for (int i = 0; i < info->matrix.size; i++) {
        if (info->matrix.matrix[row][i] == 1 && row == info->end)
            change_enter(info, row, i, 1);
        if (row != info->end && info->matrix.matrix[row][i] == 1) {
            value = info->matrix.enter[row][i];
            value = (value != 0 && value < sh + 1) ? value : sh + 1;
            change_enter(info, row, i, value);
        }
    }
    return 0;
}
