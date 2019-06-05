/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** inventory manage functions
*/

#include "my.h"

int can_grab(list_t *list, item_t *tmp)
{
    sfVector2f pos_char = list->first->player->position;

    if ((pos_char.x > tmp->position.x - 70 && pos_char.x < \
    tmp->position.x + 165 + 70) && (pos_char.y > tmp->position.y))
        return (1);
    return (0);
}

item_t *grab_object(list_t *list)
{
    item_t *tmp_item = list->first->items;
    item_t *prev_item = tmp_item;
    item_t *grabbed_item = malloc(sizeof(item_t));

    for (; tmp_item->next != NULL; tmp_item = tmp_item->next) {
        if (can_grab(list, tmp_item)) {
            if (prev_item == tmp_item) {
                list->first->items = tmp_item->next;
                grabbed_item = tmp_item;
                grabbed_item->next = NULL;
            } else {
                prev_item->next = tmp_item->next;
                grabbed_item = tmp_item;
                grabbed_item->next = NULL;
            }
            return (grabbed_item);
        }
        prev_item = tmp_item;
    }
    return (NULL);
}

void add_in_inventory(list_t *list, item_t *item)
{
    item_t *first_inv_item = list->first->player->inv->items;
    item_t *tmp_inv_item = first_inv_item;

    if (first_inv_item == NULL) {
        list->first->player->inv->items = item;
    } else {
        for (; tmp_inv_item->next != NULL; tmp_inv_item = tmp_inv_item->next);
        tmp_inv_item->next = item;
    }
}

void draw_inventory(sfRenderWindow *window, list_t **l, item_t *list)
{
    int i = 0;
    back_t *bg = l[4]->first->back;
    char_t *player = l[4]->first->player;
    sfVector2f pos[] = {{1035, 160}, {1470, 160}, {1035, 460}, {1470, 460}};

    sfSprite_setScale(bg->sprite, bg->scale);
    sfRenderWindow_drawSprite(window, bg->sprite, NULL);
    sfSprite_setPosition(bg->sprite, bg->position);
    sfSprite_setScale(player->sprite, player->scale);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    sfSprite_setPosition(player->sprite, player->position);
    for (item_t *tmp = list; tmp; tmp = tmp->next, i++) {
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        sfSprite_setPosition(tmp->sprite, pos[i]);
        sfSprite_setTextureRect(tmp->sprite, (REC){330, 195, 165, 195});
        sfSprite_setScale(tmp->sprite, (VEC){1.7, 1.7});
    }
}