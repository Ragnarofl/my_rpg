/*
** EPITECH PROJECT, 2018
** gravity.c
** File description:
** Gravity gestion
*/

#include "include/my.h"

void enemy_gravity(list_t *list, col_t *col)
{
    enemy_t *enemy = list->first->enemy_list;

    for (; enemy; enemy = enemy->next) {
        enemy->position.y += 12;
        enemy->position.y -= (enemy_collisions(col, enemy, list)) ? 12 : 0;
    }
}

void gravity(list_t *list, col_t *col)
{
    char_t *character = list->first->player;

    if (list->clocks[2]->seconds >= 0.001 && character) {
        if (character->jump == 1)
            return;
        character->position.y += 12;
        if (!check_collisions(col, list)) {
            character->jump = -1;
            if (character->dir == 0)
                character->rect.top = 280;
            if (character->dir == 1)
                character->rect.top = 320;
            character->rect.left = 80;
            sfSprite_setTextureRect(character->sprite, character->rect);
        } else {
            character->position.y -= 12;
            character->jump = 0;
        }
    }
}
