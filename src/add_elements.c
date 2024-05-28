/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** headerfile
*/

#include "../include/graph.h"

void add_to_end_rooms(rooms_t *new, parse_t *parse)
{
    rooms_t *prev = NULL;

    for (rooms_t *room = parse->rooms; room != NULL; room = room->next)
        prev = room;
    if (prev == NULL) {
        parse->rooms = new;
    } else {
        prev->next = new;
    }
    my_putstr(new->name);
    my_putchar(' ');
    my_put_nbr(new->xy[0]);
    my_putchar(' ');
    my_put_nbr(new->xy[1]);
    my_putchar('\n');
}

void add_to_end_tunnels(tunnels_t *new, parse_t *parse)
{
    tunnels_t *prev = NULL;

    for (tunnels_t *tunnel = parse->tunnel;
        tunnel != NULL; tunnel = tunnel->next)
        prev = tunnel;
    if (prev == NULL) {
        my_putstr("#tunnels\n");
        parse->tunnel = new;
    } else
        prev->next = new;
    my_putstr(new->tunnel);
    my_putchar('\n');
}

void add_room(char **array, parse_t *parse, bool start, bool end)
{
    rooms_t *rooms = malloc(sizeof(rooms_t));

    if (rooms == NULL)
        return;
    rooms->start = start;
    rooms->end = end;
    rooms->name = my_strdup(array[0]);
    rooms->xy[0] = get_nat_nbr(array[1]);
    rooms->xy[1] = get_nat_nbr(array[2]);
    rooms->next = NULL;
    parse->nbr_rooms++;
    add_to_end_rooms(rooms, parse);
}

void add_tunnels(char **array, parse_t *parse, char *tunnel)
{
    tunnels_t *new = malloc(sizeof(tunnels_t));

    if (new == NULL)
        return;
    new->tunnel = my_strdup(tunnel);
    new->connection1 = get_nat_nbr(array[0]);
    new->connection2 = get_nat_nbr(array[1]);
    new->next = NULL;
    parse->nbr_tunnels++;
    add_to_end_tunnels(new, parse);
}
