/*
** EPITECH PROJECT, 2018
** my_get_nbr.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

int is_char_present(char c, char *cmp)
{
    for (int i = 0; cmp[i]; i++) {
        if (c == cmp[i])
            return (1);
    }
    return (0);
}

long my_getnbr(char *str)
{
    int i = 0;
    int a = 1;
    long res = 0;

    for (; str[i] == '-' || str[i] == '+'; i++)
        a = (str[i] == '-') ? a * -1 : a;
    for (; str[i] > 47 && str[i] < 58; i++)
        res = res * 10 + (str[i] - 48);
    return (a * res);
}
