/*
** EPITECH PROJECT, 2019
** enemy_obj_agro1.c
** File description:
** Check Object Agro
*/

#include "../include/object.h"

int is_obj_in_zone(sfVector2f position, enemy_t *enemy, zone_t *zone)
{
    enemy->focus_zone->bounds = sfRectangleShape_getGlobalBounds(zone->zone);

    if (sfFloatRect_contains(&enemy->focus_zone->bounds, (position.x + 20), (position.y + 10)))
        return (1);
    else
        return (0);
}

int focus_mouse(list_t *game, enemy_t *enemy)
{
    sfVector2f player_pos = game->first->player->position;

        if ((sfSprite_getPosition(enemy->sprite).x) < player_pos.x) {
            if (enemy->state != BUSY) {
                enemy->dir = E_RIGHT;
                //printf("RIGHT\n");
                animate_object(game, enemy, MOVE_R, 1120, 0);
                move_enemy(player_pos, enemy, game->clocks);
            }
        }
        else if ((sfSprite_getPosition(enemy->sprite).x) > player_pos.x) {
            if (enemy->state != BUSY) {
                enemy->dir = E_LEFT;
                //printf("LEFT\n");
                animate_object(game, enemy, MOVE_L, 1120, 1);
                move_enemy(player_pos, enemy, game->clocks);
            }
        }
        return (1);
}

int hit_zone(list_t *game, enemy_t *enemy)
{
    sfVector2f player_pos = game->first->player->position;

        if ((sfSprite_getPosition(enemy->sprite).x) < player_pos.x || (enemy->dir == E_RIGHT && enemy->state == BUSY)) {
            if (enemy->state == AVAIBLE)
                enemy->dir = E_RIGHT;
            if (enemy->state != BUSY)
                enemy->state = BUSY;
            if (enemy->dir == E_RIGHT)
                animate_object(game, enemy, ATTACK_R, 1120, 0);
            else if (enemy->dir == E_LEFT)
                enemy->dir = E_RIGHT;
        }
        if ((sfSprite_getPosition(enemy->sprite).x) > player_pos.x || (enemy->dir == E_LEFT && enemy->state == BUSY)) {
            if (enemy->state == AVAIBLE)
                enemy->dir = E_LEFT;
            if (enemy->state != BUSY)
                enemy->state = BUSY;
            if (enemy->dir == E_LEFT)
                animate_object(game, enemy, ATTACK_L, 1120, 1);
            else if (enemy->dir == E_RIGHT)
                enemy->dir = E_LEFT;
        }
        return (1);
}
