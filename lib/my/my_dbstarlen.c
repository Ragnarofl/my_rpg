/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_dbstarlen
*/

#include <unistd.h>

int my_dbstarlen(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++);
    return (i);
}
