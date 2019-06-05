/*
** EPITECH PROJECT, 2018
** particles.c
** File description:
** particles
*/

#include "include/particles.h"

void drawPartBufer(partBuffer *buffer, sfRenderWindow *window)
{
    sfRenderWindow_drawPrimitives(window,\
         buffer->vertex, buffer->size * 4, sfQuads, NULL);
}
