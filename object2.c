/*
** EPITECH PROJECT, 2018
** object2.c
** File description:
** object gestion
*/

#include "include/my.h"

void create_npc(list_t *list)
{
    sfIntRect rect = {0, 0, 40, 40};
    sfVector2f pos = {240, 643};
    sfVector2f scale = {3, 3};
    npc_t *npc = malloc(sizeof(*npc));

    npc->scale = scale;
    npc->rect = rect;
    npc->position = pos;
    npc->action = 0;
    npc->dir = 0;
    npc->sprite = sfSprite_create();
    npc->texture = sfTexture_createFromFile("assets/viking3.png", NULL);
    sfSprite_setTexture(npc->sprite, npc->texture, sfTrue);
    sfSprite_setTextureRect(npc->sprite, rect);
    sfSprite_setPosition(npc->sprite, pos);
    npc->text = NULL;
    sfSprite_setScale(npc->sprite, scale);
    npc->next = NULL;
    list->first->npc = npc;
}

item_t *create_item(int name, sfVector2f pos)
{
    item_t *items = malloc(sizeof(*items));
    char *path = my_strcat(my_strcat("assets/item", my_itoa(name + 1)), ".png");

    items->rect = (sfIntRect){0, 0, 165, 195};
    items->position = pos;
    items->sprite = sfSprite_create();
    items->texture = sfTexture_createFromFile(path, NULL);
    items->next = NULL;
    sfSprite_setTexture(items->sprite, items->texture, sfTrue);
    sfSprite_setTextureRect(items->sprite, (sfIntRect){0, 195, 165, 195});
    sfSprite_setPosition(items->sprite, (sfVector2f){600, 643});
    return (items);
}

item_t *add_item(item_t *item_list, int name, sfVector2f pos)
{
    item_t *items = create_item(name, pos);
    item_t *tmp = NULL;

    if (!item_list)
        return (items);
    for (tmp = item_list; tmp->next != NULL; tmp = tmp->next);
    tmp->next = items;
    return (item_list);
}

void create_para(char *ssh, sfVector2f pos, object_t *obj)
{
    back_t *new = malloc(sizeof(*new));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_create(768, 224);
    new->texture = sfTexture_createFromFile(ssh, NULL);
    new->position = pos;
    new->rect = (REC){0, 0, 768, 224};
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, new->rect);
    new->map = 1;
    new->scale = (sfVector2f){5, 4.8};
    new->next = obj->back;
    obj->back = new;
}

void create_items(list_t *list)
{
    int item_number = 5;
    sfVector2f pos[] = {{500, 575}, {950, 820}, {1150, 820}, {1550, 820}, \
    {3600, 510}};

    for (int i = 0; i < item_number; i++)
        list->first->items = add_item(list->first->items, i, pos[i]);
}
