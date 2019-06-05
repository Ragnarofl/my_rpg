/*
** EPITECH PROJECT, 2018
** object2.c
** File description:
** item animation
*/

#include "include/my.h"
#include "include/particles.h"

void item_animate(list_t *list, item_t *item)
{
    static int x = 0;

    if (can_grab(list, item))
        item->rect.top = 0;
    else
        item->rect.top = 195;
    if (list->clocks[0]->seconds >= 0.1) {
        x += 1;
        if (x == 1) {
            move_rect(&item->rect, 165, 660);
            sfSprite_setTextureRect(item->sprite, item->rect);
            x = 0;
        }
    }
}

void item_animation(list_t *list, item_t *list_item)
{
    item_t *tmp = list_item;

    for (; tmp; tmp = tmp->next)
        item_animate(list, tmp);
}

int items_interactions(list_t *list, item_t *tmp)
{
    sfVector2f pos_char = list->first->player->position;

    for (item_t *tmp_item = tmp; tmp_item; tmp_item = tmp_item->next)
        if ((pos_char.x > tmp_item->position.x - 70 && pos_char.x < \
        tmp_item->position.x + 165 + 70) && (pos_char.y > tmp_item->position.y))
            return (1);
    return (0);
}
