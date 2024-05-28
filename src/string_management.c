/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** lib function string management
*/

#include "../include/my.h"

int get_nat_nbr(char const *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return ERROR;
        nbr = (nbr * 10) + str[i] - '0';
    }
    return nbr;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    for (i = 0; i < len1 && i < len2; i++)
        if (s1[i] != s2[i])
            break;
    return s1[i] - s2[i];
}

char *my_strdup(char const *str)
{
    int str_len = my_strlen(str);
    char *new = malloc(sizeof(char) * (str_len + 1));

    if (new == NULL)
        return NULL;
    for (int i = 0; i < str_len; i++)
        new[i] = str[i];
    new[str_len] = 0;
    return new;
}

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
