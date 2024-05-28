/*
** EPITECH PROJECT, 2024
** EPITECH PROJECT BOOTSTRAP
** File description:
** my.h for the graph structures
*/

#ifndef MY_H_
    #define MY_H_
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>
    #define ERROR -1

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);

void *my_calloc(size_t num_elems, size_t elem);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);

int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *str, char delim);
int my_strlen(char const *str);
#endif
