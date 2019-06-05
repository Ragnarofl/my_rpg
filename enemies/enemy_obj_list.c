/*
** EPITECH PROJECT, 2019
** Game objects related function for csfml project
** File description:
** object
*/

#include "../include/object.h"

enemy_t *add_enemy(sfVector2f position, enemy_t *enemy_list)
{
    enemy_t *new_enemy = set_enemy(position);
    enemy_t *tmp = NULL;

    new_enemy->next = NULL;
    if (!enemy_list)
        enemy_list = new_enemy;
    else {
        for (tmp = enemy_list; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_enemy;
    }
    return (enemy_list);
}

void update_enemy_list(enemy_t *enemies, sfRenderWindow *window)
{
    for (enemy_t *tmp = enemies; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        sfSprite_setPosition(tmp->sprite, tmp->position);
        update_hit_box_pos(tmp->hit_box, tmp->position);
        sfRectangleShape_setPosition(tmp->focus_zone->zone, tmp->position);
        sfRectangleShape_setPosition(tmp->hit_zone->zone, tmp->position);
        sfRectangleShape_setPosition(tmp->hurt_box->zone, tmp->position);
        sfRectangleShape_setPosition(tmp->hit_box_r->zone, tmp->hit_box[E_HIT_BOX_R]);
        sfRectangleShape_setPosition(tmp->hit_box_l->zone, tmp->hit_box[E_HIT_BOX_L]);
    }
}

VEC *update_hit_box_pos(VEC *hit_box, VEC player)
{
    VEC *new_hit_box_pos = hit_box;
    
    if (new_hit_box_pos) {
        new_hit_box_pos[E_HIT_BOX_R].x = (player.x + 35);
        new_hit_box_pos[E_HIT_BOX_R].y = player.y;
        new_hit_box_pos[E_HIT_BOX_L].x = (player.x - 35);
        new_hit_box_pos[E_HIT_BOX_L].y = player.y;
    }
    return (new_hit_box_pos);
}

clocki_t *get_clock_time(clocki_t *clocki)
{
    clocki_t *new_clock = clocki;

    if (new_clock) {
        new_clock->time = sfClock_getElapsedTime(clocki->clock);
        new_clock->seconds = clocki->time.microseconds / 1000000.0;
        return (new_clock); 
    }
    //DEBUG
    printf("DEBUG: No Invicibility clock found.\n");
    return (NULL);
}