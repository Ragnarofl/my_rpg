/*
** EPITECH PROJECT, 2018
** viking_animations.c
** File description:
** viking animations gestion
*/

#include "include/player.h"
#include "include/my.h"

void setup_actions(char_t *);

void viking_idle(list_t *list, char_t *character)
{
    static int x = 0;

    if (character->dir == LEFT)
        character->rect.top = 160;
    else
        character->rect.top = 120;
    if (list->clocks[0]->seconds >= 0.1) {
        x += 1;
        if (x == 2) {
            move_rect(&character->rect, 40, 160);
            x = 0;
        }
        character->rect.height = 40;
        character->rect.width = 40;
        sfSprite_setTextureRect(character->sprite, character->rect);
    }
}

void shift_object(list_t *list, int dir)
{
    float shift = dir / 5;

    for (back_t *back = list->first->back; back->next; back = back->next) {
        if (back->position.x >= 1920)
            back->position.x = 0;
        back->position.x -= shift;
        shift *= 1.5;
        sfSprite_setTextureRect(back->sprite, back->rect);
    }
    for (enemy_t *e = list->first->enemy_list; e; e = e->next)
        e->position.x -= dir * 0.8;
    for (item_t *item = list->first->items; item; item = item->next)
        item->position.x -= dir * 0.8;
    for (npc_t *npc = list->first->npc; npc; npc = npc->next)
        npc->position.x -= dir * 0.8;
}

void move_viking(list_t *list, char_t *c, col_t *col, int dir)
{
    back_t *back = list->first->back;

    for (; back->next; back = back->next);
    if (c->position.x >= 900 && dir > 0 && back->rect.left < 1920 / 4) {
        back->rect.left += dir / 3;
        if (check_collisions(col, list))
            back->rect.left -= dir / 3;
        else
            shift_object(list, dir);
        sfSprite_setTextureRect(back->sprite, back->rect);
    } else if (c->position.x <= 900 && dir < 0 && back->rect.left > 0) {
        back->rect.left += dir / 3;
        if (check_collisions(col, list))
            back->rect.left -= dir / 3;
        else
            shift_object(list, dir);
        sfSprite_setTextureRect(back->sprite, back->rect);
    } else {
        c->position.x += dir;
        c->position.x -= (check_collisions(col, list)) ? dir : 0;
    }
}

void viking_run(list_t *list, char_t *character, col_t *col)
{
    if (character->jump == 0) {
        if (list->clocks[0]->seconds >= 0.1) {
            move_rect(&character->rect, 40, 320);
            sfSprite_setTextureRect(character->sprite, character->rect);
        }
    }
    if (list->clocks[2]->seconds >= 0.001) {
        if (character->dir == 0) {
            move_viking(list, character, col, 5);
        } else
            move_viking(list, character, col, -5);
    }
    sfSprite_setPosition(character->sprite, character->position);
}

void viking_light_attack(list_t *list, char_t *character)
{
    static int x = 0;
    sfIntRect default_rect = {0, 0, 40, 40};

    if (list->clocks[0]->seconds >= 0.1) {
        x += 1;
        move_rect(&character->rect, 49, 245);
        sfSprite_setTextureRect(character->sprite, character->rect);
    }
    if (x == 4) {
        x = 0;
        character->rect = default_rect;
        character->action = IDLE;
    }
}
