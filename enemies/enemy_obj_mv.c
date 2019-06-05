/*
** EPITECH PROJECT, 2019
** Enemy Object Movement Functions
** File description:
** enemy_obj_mv
*/

#include "../include/object.h"

void move_enemy(sfVector2f player_pos, enemy_t *enemy, clocki_t **clock_tab)
{
    enemy->position = sfSprite_getPosition(enemy->sprite);
    if (player_pos.x > enemy->position.x) {
        if  (clock_tab[2]->seconds >= 0.001) {
            //printf("moved forward.\n");
            enemy->position.x += enemy->speed;
        }
    }
    else {
        if  (clock_tab[2]->seconds >= 0.001) {
            //printf("moved backward.\n");
            enemy->position.x -= enemy->speed;
        }
    }
    //sfVector2f new_enemy_pos = sfSprite_getPosition(enemy->sprite);
    //printf("enemy pos: x= %f, y= %f\n", new_enemy_pos.x, new_enemy_pos.y);
    //printf("mouse pos: x= %d, y= %d\n", m_pos.x, m_pos.y);
}
