/*
** EPITECH PROJECT, 2019
** enemy_obj_agro.c
** File description:
** Check Object Agro
*/

#include "../include/object.h"

void set_agro(list_t *game, enemy_t *enemy)
{
    if (is_obj_in_zone(game->first->player->position, enemy, enemy->focus_zone)) {
        if (is_obj_in_zone(game->first->player->position, enemy, enemy->hit_zone))
            hit_zone(game, enemy);
            //printf("ENTERED HIT ZONE\n");
        else {
            if (enemy->state == BUSY)
                hit_zone(game, enemy);
                //printf("ENEMY BUSY - FZONE.\n");
            focus_mouse(game, enemy);
        }
    }
    else {
        if (enemy->state == BUSY)
            hit_zone(game, enemy);
            //printf("ENEMY BUSY.\n");
        if (enemy->state != BUSY) {
            if (enemy->dir == E_RIGHT)
                animate_object(game, enemy, IDLE_R, 864, 0);
            else if (enemy->dir == E_LEFT)
                animate_object(game, enemy, IDLE_L, 864, 1);
        }
    }
}
