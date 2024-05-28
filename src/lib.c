/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** lib functions
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_strlen(char const *str)
{
    int number_array = 0;

    while (str[number_array] != '\0') {
        number_array = number_array + 1;
    }
    return (number_array);
}

int my_put_nbr(int nb)
{
    int num = 0;

    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48);
    if (nb < 0) {
        my_putchar('-');
        num = -1 * nb;
        my_put_nbr(num);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        num = nb % 10 + 48;
        my_putchar(num);
    }
    return (0);
}

int get_num(char *str)
{
    int num = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        i++;
        sign = -1;
    }
    for (i = i; str[i] != '\0'; i++)
        if (str[i] >= '0' && str[i] <= '9')
            num = (num * 10) + (str[i] - '0');
    num *= sign;
    return num;
}
