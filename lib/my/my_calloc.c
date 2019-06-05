/*
** EPITECH PROJECT, 2018
** paolo reant libmy
** File description:
** my_calloc
*/

#include <stdlib.h>

void *memcheck(char *str, char **arr, int size, int nb)
{
    if (size != 8) {
        for (int i = 0; i < nb; i++)
            str[i] = 0;
        return (str);
    } else {
        for (int i = 0; i < nb; i++)
            arr[i] = NULL;
        return (arr);
    }
}

void *my_calloc(int nb, int size)
{
    char *str = NULL;
    char **arr = NULL;

    if (size == 1) {
        str = malloc(size * (nb + 1));
        str[nb] = 0;
    } else if (size == 8) {
        arr = malloc(size * (nb + 1));
        arr[nb] = NULL;
    } else
        str = malloc(size * nb);

    if (size != 8 && !str)
        return (NULL);
    else if (size == 8 && !arr)
        return (NULL);
    return (memcheck(str, arr, size, nb));
}
