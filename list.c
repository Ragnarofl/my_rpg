/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** list gestion
*/

#include "include/my.h"

void draw_player(char_t *player, sfRenderWindow *window)
{
    sfSprite_setScale(player->sprite, player->scale);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    sfSprite_setPosition(player->sprite, player->position);
    update_hit_box_pos(player->hit_box, player->position);
    sfRectangleShape_setPosition(player->hurt_box->zone, player->position);
    sfRectangleShape_setPosition(player->hit_box_r->zone, player->hit_box[E_HIT_BOX_R]);
    sfRectangleShape_setPosition(player->hit_box_l->zone, player->hit_box[E_HIT_BOX_L]);
}

void draw_items(item_t *item_list, sfRenderWindow *window)
{
    for (item_t *tm = item_list; tm; tm = tm->next) {
        sfRenderWindow_drawSprite(window, tm->sprite, NULL);
        sfSprite_setPosition(tm->sprite, tm->position);
    }
}

void draw_object(sfRenderWindow *window, list_t *l)
{
    for (back_t *new = l->first->back; new; new = new->next) {
        sfSprite_setScale(new->sprite, new->scale);
        sfRenderWindow_drawSprite(window, new->sprite, NULL);
        sfSprite_setPosition(new->sprite, new->position);
    }
    if (l->first->npc) {
        sfSprite_setScale(l->first->npc->sprite, l->first->npc->scale);
        sfRenderWindow_drawSprite(window, l->first->npc->sprite, NULL);
        sfSprite_setPosition(l->first->npc->sprite, l->first->npc->position);
    }
    if (l->first->items)
        draw_items(l->first->items, window);
    if (l->first->player)
        draw_player(l->first->player, window);
    if (l->first->enemy_list)
        update_enemy_list(l->first->enemy_list, window);
}

void draw_list(sfRenderWindow *window, list_t *list)
{
    button_t **buttons = list->buttons;

    if (list->first)
        draw_object(window, list);
    draw_text(window, list);
    for (int d = 0; d < list->btn_nbr; d++) {
        sfRenderWindow_drawSprite(window, buttons[d]->sprite, NULL);
        sfSprite_setPosition(buttons[d]->sprite, buttons[d]->position);
        sfRenderWindow_drawText(window, buttons[d]->text, NULL);
    }
}

list_t **create_list_array(void)
{
    list_t **list_array = malloc(sizeof(list_t *) * 5);

    list_array[0] = create_title();
    list_array[1] = create_option();
    list_array[2] = create_game();
    list_array[3] = create_pause();
    list_array[4] = create_inventory();
    return (list_array);
}
