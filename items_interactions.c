/*
** EPITECH PROJECT, 2018
** object2.c
** File description:
** npc
*/

#include "include/my.h"
#include "include/particles.h"

void items_interactions(list_t *list, partBuffer *buff)
{
    sfVector2f pos_char = list->first->player->position;
    sfVector2f pos_item = list->first->items->position;

    (void)buff;
    if (pos_char.x > pos_item.x - 70 && pos_char.x < pos_item.x + 70) {
        my_printf("in item zone\n");
    }
}
