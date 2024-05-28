/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** my str to word array
*/

#include "../include/graph.h"

void clean_comment(char *buffer)
{
    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '#' && buffer[i + 1] != '#') {
            buffer[i] = 0;
            return;
        }
        if (buffer[i] == '#' && buffer[i + 1] == '#')
            i += 1;
    }
}

static void init_parse(parse_t *parsing)
{
    parsing->n_robots = 0;
    parsing->rooms = NULL;
    parsing->tunnel = NULL;
    parsing->end = false;
    parsing->start = false;
}

static int save_information(parse_t *parse, char *buffer)
{
    char **array = my_str_to_word_array(buffer, ' ');

    if (array[0] == NULL) {
        free(array);
        return 0;
    }
    free_array(array);
    if (parse->n_robots == 0) {
        parse->n_robots = check_robots(buffer);
        if (parse->n_robots != -1) {
            print_robot_num(parse->n_robots);
            my_putstr("#rooms\n");
            return 0;
        }
        return ERROR;
    }
    if (check_start_end(buffer, parse) == 0 ||
        check_tunnels(buffer, parse) == 0)
        return 0;
    return ERROR;
}

static int get_context(parse_t *parsing)
{
    char *buffer = NULL;
    size_t size = 0;
    ssize_t nread = 0;
    int status = 0;

    nread = getline(&buffer, &size, stdin);
    if (nread == -1)
        return 1;
    buffer[nread - 1] = (buffer[nread -1] == '\n') ? 0 : buffer[nread - 1];
    clean_comment(buffer);
    status = save_information(parsing, buffer);
    free(buffer);
    return status;
}

int parsing(amazed_t *info)
{
    int status = 0;
    parse_t *parse = malloc(sizeof(parse_t));

    init_parse(parse);
    while (1) {
        status = get_context(parse);
        if (status != 0)
            break;
    }
    if (parse->tunnel == NULL || parse->rooms == NULL)
        return ERROR;
    status = (status == 1) ? fill_amazed(parse, info) : status;
    return status;
}
