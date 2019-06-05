/*
** EPITECH PROJECT, 2019
** pause.c
** File description:
** pause gestion
*/

#include "include/my.h"

void create_pause_button(list_t *list)
{
    list->buttons = malloc(sizeof(button_t *) * 3);
    list->buttons[0] = c_btn((VEC){800, 400}, (VEC){-890, -420}, "Continue");
    list->buttons[0]->callback = &play;
    list->buttons[1] = c_btn((VEC){800, 550}, (VEC){-900, -570}, "Menu");
    list->buttons[1]->callback = &back_menu;
    list->buttons[2] = c_btn((VEC){800, 700}, (VEC){-905, -720}, "Quit");
    list->buttons[2]->callback = &close_window;
}
