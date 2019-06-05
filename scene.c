/*
** EPITECH PROJECT, 2019
** scene.c
** File description:
** scene gestion
*/

#include "include/my.h"

list_t *create_title(void)
{
    list_t *list = malloc(sizeof(*list));

    if (list != NULL) {
        list->first = create_object();
        create_back("assets/bg3.png", (VEC){0, 0}, list->first);
        list->clocks = get_clocks();
        create_title_btn(list);
        list->btn_nbr = 3;
        list->volume = 50;
        list->music = NULL;
    }
    return (list);
}

list_t *create_game(void)
{
    list_t *list = malloc(sizeof(*list));

    if (list != NULL) {
        list->first = create_object();
        create_map("assets/map1.png", (VEC){0, 0}, list->first);
        create_para("assets/forest/para3.png", (VEC){0, 0}, list->first);
        create_para("assets/forest/para2.png", (VEC){0, 0}, list->first);
        create_para("assets/forest/para1.png", (VEC){0, 0}, list->first);
        create_para("assets/forest/para4.png", (VEC){0, 0}, list->first);
        create_character(list);
        create_items(list);
        list->buttons = NULL;
        list->clocks = get_clocks();
        list->btn_nbr = 0;
        list->text = NULL;
        list->volume = 50;
        list->music = NULL;
    }
    return (list);
}

list_t *create_pause(void)
{
    list_t *list = malloc(sizeof(*list));

    if (list != NULL) {
        list->first = create_object();
        create_back("assets/bg3.png", (VEC){0, 0}, list->first);
        create_pause_button(list);
        list->btn_nbr = 3;
        list->text = NULL;
        list->clocks = get_clocks();
        list->volume = 50;
        list->music = NULL;
    }
    return (list);
}

list_t *create_option(void)
{
    list_t *list = malloc(sizeof(*list));

    if (list != NULL) {
        list->first = create_object();
        create_back("assets/bg3.png", (VEC){0, 0}, list->first);
        create_option_btn(list);
        list->btn_nbr = 3;
        list->clocks = NULL;
        list->text = option_text();
        list->volume = 50;
        list->music = NULL;
    }
    return (list);
}

list_t *create_inventory(void)
{
    list_t *list = malloc(sizeof(*list));

    if (list != NULL) {
        list->first = create_object();
        create_back("assets/inventory.png", (VEC){0, 0}, list->first);
        create_character(list);
        sfSprite_setTextureRect(list->first->player->sprite, \
        (REC){0, 120, 40, 40});
        list->first->player->scale = (sfVector2f){8, 8};
        list->first->player->position = (VEC){400, 500};
        list->buttons = NULL;
        list->clocks = get_clocks();
        list->btn_nbr = 0;
        list->text = NULL;
        list->volume = 50;
        list->music = NULL;
    }
    return (list);
}
