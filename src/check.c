/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** headerfile
*/

#include "../include/graph.h"

int check_robots(char *buffer)
{
    int nbr_robots = get_nat_nbr(buffer);

    if (nbr_robots == ERROR)
        return ERROR;
    return nbr_robots;
}

int check_rooms(char **array, parse_t *parse)
{
    int x = (array[1] != NULL) ? get_nat_nbr(array[1]) : ERROR;
    int y = (array[2] != NULL) ? get_nat_nbr(array[2]) : ERROR;

    for (rooms_t *rooms = parse->rooms; rooms != NULL; rooms = rooms->next)
        if (my_strcmp(rooms->name, array[0]) == 0) {
            return ERROR;
        }
    if (x == -1 || y == -1)
        return ERROR;
    return 0;
}

int check_letter(char const *str, char letter)
{
    int num = 0;

    for (int i = 0; str[i] != 0; i++)
        if (str[i] == letter)
            num++;
    return num;
}

int check_tunnels(char const *buffer, parse_t *parse)
{
    char **array = NULL;
    char **tunnels = NULL;

    if (check_letter(buffer, '-') != 1)
        return ERROR;
    array = my_str_to_word_array(buffer, ' ');
    tunnels = my_str_to_word_array(array[0], '-');
    if (tunnels[0] == NULL || tunnels[1] == NULL)
        return ERROR;
    if (get_nat_nbr(tunnels[0]) == ERROR || get_nat_nbr(tunnels[1]) == ERROR)
        return ERROR;
    add_tunnels(tunnels, parse, array[0]);
    free_array(array);
    free_array(tunnels);
    return 0;
}

int check_room(char const *buffer, parse_t *parse)
{
    char **array = 0;

    array = my_str_to_word_array(buffer, ' ');
    if (array[0] == NULL || array[1] == NULL || array[2] == NULL)
        return ERROR;
    if (get_nat_nbr(array[1]) == ERROR || get_nat_nbr(array[2]) == ERROR)
        return ERROR;
    add_room(array, parse, false, false);
    free(array);
    return 0;
}
