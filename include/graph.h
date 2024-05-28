/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT BOOTSTRAP
** File description:
** my.h for the graph structures
*/

#ifndef GRAPH_H_
    #define GRAPH_H_
    #include "my.h"
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>

typedef struct matrix {
    int **matrix;
    int size;
    int **enter;
} matrix_t;

typedef struct rooms {
    bool start;
    bool end;
    char *name;
    int xy[2];
    struct rooms *next;
} rooms_t;

typedef struct tunnel {
    char *tunnel;
    int connection1;
    int connection2;
    struct tunnel *next;
} tunnels_t;

typedef struct program {
    tunnels_t *tunnel;
    rooms_t *rooms;
    int nbr_rooms;
    int nbr_tunnels;
    int n_robots;
    bool start;
    bool end;
} parse_t;

typedef struct amazed {
    matrix_t matrix;
    char **rooms;
    int **xy;
    int **tunnels;
    int size_tun;
    int start;
    int end;
    int nbr_robots;
} amazed_t;

int parsing(amazed_t *info);
void clean_comment(char *buffer);
int get_nat_nbr(char const *str);

int check_rooms(char **array, parse_t *parse);
int check_robots(char *buffer);
int check_tunnels(char const *buffer, parse_t *parse);
int check_start_end(char *buffer, parse_t *parse);
int check_room(char const *buffer, parse_t *parse);

int get_nat_nbr(char const *str);
void free_array(char **array);

void add_room(char **array, parse_t *parse, bool start, bool end);
void add_tunnels(char **array, parse_t *parse, char *tunnel);

void print_robot_num(int robot_num);
void print_rooms(rooms_t *rooms);
void print_tunnels(tunnels_t *tunnels);

void print_all_rooms(char **rooms, int start, int end, int **xy);
void print_all_tunnels(int **tunnels, int size);
void print_matrix(int **matrix, int size);

int fill_amazed(parse_t *parse, amazed_t *info);

int dijisktra(amazed_t *info, int row);
int search_for_smallest_one(int *array, int size);
int algorithm(amazed_t *info);

int *copy_array(int *array);
void print_moves(amazed_t *info, int **connections, int num_paths);
#endif
