/*
** EPITECH PROJECT, 2017
** callback.c
** File description:
** callbacks gestion
*/

#include "include/my.h"

void close_window(sfRenderWindow *window, int *i, list_t **list)
{
    (void)i;
    (void)list;
    sfRenderWindow_close(window);
}

void back_menu(sfRenderWindow *window, int *i, list_t **list)
{
    (void)window;
    (void)list;
    *i = 0;
}

void option_page(sfRenderWindow *window, int *i, list_t **list)
{
    (void)window;
    (void)list;
    *i = 1;
}

void play(sfRenderWindow *window, int *i, list_t **list)
{
    (void)window;
    (void)list;
    *i = 2;
}
