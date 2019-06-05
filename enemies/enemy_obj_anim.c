/*
** EPITECH PROJECT, 2019
** Enemy Object Animation related Functions
** File description:
** enemy_obj_anim
*/

#include "../include/object.h"

void move_rect_b(sfIntRect *rect, int max_value, int start_at_maxv)
{
    if (!start_at_maxv) {
        if (rect->left >= (max_value - rect->width)) {
            rect->left = 0;
    }
        else
            rect->left += rect->width;
    }
    else {
        if (rect->left > 0) {
            rect->left -= rect->width;
        }
        else
            rect->left = (max_value - rect->width);
    }
}

void set_avaible_state(enemy_t *enemy, int anim)
{
    if (enemy->rect_tab[anim].left <= 0 && enemy->state == BUSY) {
        enemy->state = AVAIBLE;
        //printf("ENEMY AVAIBLE\n");
    }
}

void animate_object(list_t *game, enemy_t *enemy,  int anim, int max_value, int start_at_maxv)
{
    //printf("time: %f\n", game->clocks[0]->seconds);
    //printf("rect_left: %d\n", enemy->rect_tab[anim].left);
    if ((game->clocks[3]->seconds >= enemy->dexterity)) {
        move_rect_b(&enemy->rect_tab[anim],  max_value, start_at_maxv);
        set_avaible_state(enemy, anim);
        sfSprite_setTextureRect(enemy->sprite, enemy->rect_tab[anim]);
    }
}
