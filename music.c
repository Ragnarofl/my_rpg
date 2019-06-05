/*
** EPITECH PROJECT, 2018
** option.c
** File description:
** option gestion
*/

#include "include/my.h"

void manage_music(list_t *list)
{
    if (list->music)
        sfMusic_setVolume(list->music, list->volume);
}

void play_music(list_t *list)
{
    sfMusic_play(list->music);
    sfMusic_setLoop(list->music, sfTrue);
    sfMusic_setVolume(list->music, list->volume);
}
