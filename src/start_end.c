/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** headerfile
*/

#include "../include/graph.h"

int get_end(parse_t *parse)
{
    char *buffer = NULL;
    size_t size = 0;
    char **array = NULL;
    int status = 0;
    ssize_t nread = 0;

    nread = getline(&buffer, &size, stdin);
    if (nread == -1 || parse->end == true)
        return ERROR;
    buffer[nread - 1] = (buffer[nread -1] == '\n') ? 0 : buffer[nread - 1];
    clean_comment(buffer);
    array = my_str_to_word_array(buffer, ' ');
    if (array[0] != NULL) {
        status = check_rooms(array, parse);
        if (status == 0)
            add_room(array, parse, false, true);
    } else
        status = 1;
    free(array);
    return status;
}

int get_start(parse_t *parse)
{
    char *buffer = NULL;
    size_t size = 0;
    char **array = NULL;
    int status = 0;
    ssize_t nread = 0;

    nread = getline(&buffer, &size, stdin);
    if (nread == -1 || parse->start == true)
        return ERROR;
    buffer[nread - 1] = (buffer[nread -1] == '\n') ? 0 : buffer[nread - 1];
    clean_comment(buffer);
    array = my_str_to_word_array(buffer, ' ');
    if (array[0] != NULL) {
        status = check_rooms(array, parse);
        if (status == 0)
            add_room(array, parse, true, false);
    } else
        status = 1;
    free(array);
    return status;
}

int check_start_end(char *buffer, parse_t *parse)
{
    char **array = my_str_to_word_array(buffer, ' ');
    int status = 1;

    if (my_strcmp(array[0], "##start") == 0 && parse->start == false) {
        my_putstr("##start\n");
        while (status == 1)
            status = get_start(parse);
        parse->start = (status == 0) ? true : false;
        return status;
    }
    if (my_strcmp(array[0], "##end") == 0 && parse->end == false) {
        my_putstr("##end\n");
        while (status == 1)
            status = get_end(parse);
        parse->end = (status == 0) ? true : false;
        return status;
    }
    return check_room(buffer, parse);
}
