/*
** EPITECH PROJECT, 2019
** Game objects related function for csfml project
** File description:
** object
*/

#include "../include/object.h"

void enemies_interactions(list_t **list)
{
    enemy_t *enemy_list = list[2]->first->enemy_list;

    for (enemy_t *tmp = enemy_list; tmp != NULL; tmp = tmp->next) {
        set_agro(list[2], tmp);
        update_clocks(list[2], tmp);
    }
}

void update_clocks(list_t *list, enemy_t *enemy)
{
    if (enemy->state == E_HURT) {
        enemy->state = E_INVICIBLE;
        //DEBUG
        //printf("ENEMY INVICIBLE.\n");
    }
    if (enemy->state == E_INVICIBLE) {
        if (list->clocks[C_INV]->seconds >= enemy->inv_duration) {
            enemy->state = IDLE;
        }
        //DEBUG
        //printf("IM INVICIBLE !!!\n");
    }
}

void enemy_spawn_at_mpos(list_t **l, window_t *window)
{
        VEC mouse_pos = {0};

        //printf("BUTTON PRESSED.\n");
        /*printf("Mouse pos x: %d, Mouse pos y: %d\n", sfMouse_getPosition((sfWindow *)window->win).x,
        sfMouse_getPosition((sfWindow *)window->win).y);*/
        mouse_pos.x = sfMouse_getPosition((sfWindow *)window->win).x;
        mouse_pos.y = sfMouse_getPosition((sfWindow *)window->win).y;
        l[2]->first->enemy_list = add_enemy(mouse_pos, l[2]->first->enemy_list);
}

void enemy_spawn_at_grab(list_t **l, window_t *window)
{
    int pos_x = 400;
    int pos_y = 500;
    VEC enemy_pos = {pos_x, pos_y};

    for (int i = 0; i < 6; i++) {
        enemy_pos.x += 150;
        l[2]->first->enemy_list = add_enemy(enemy_pos, l[2]->first->enemy_list);
    }
}
