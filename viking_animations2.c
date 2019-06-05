/*
** EPITECH PROJECT, 2018
** viking_animations2.c
** File description:
** viking animations file 2
*/

#include "include/player.h"

void viking_block(list_t *list, char_t *character)
{
    static int x = 0;

    if (list->clocks[0]->seconds >= 0.1) {
        x += 1;
        move_rect(&character->rect, 40, 120);
        sfSprite_setTextureRect(character->sprite, character->rect);
    }
    if (x == 3) {
        x = 0;
        character->action = IDLE;
    }
}

void viking_gethit(list_t *list, char_t *character)
{
    static int x = 0;
    static int c = 0;

    if (list->clocks[0]->seconds >= 0.1) {
        c += 1;
        if (c == 2) {
            move_rect(&character->rect, 40, 120);
            sfSprite_setTextureRect(character->sprite, character->rect);
            x += 1;
            c = 0;
        }
    }
    if (x == 2) {
        x = 0;
        character->action = IDLE;
    }
}

void viking_death(list_t *list, char_t *character)
{
    static int x = 0;
    sfIntRect default_rect = {0, 0, 40, 40};

    if (list->clocks[0]->seconds >= 0.1) {
        x += 1;
        move_rect(&character->rect, 45, 225);
        sfSprite_setTextureRect(character->sprite, character->rect);
    }
    if (x == 4) {
        x = 0;
        character->rect = default_rect;
        character->action = IDLE;
    }
}

void viking_heavy_attack(list_t *list, char_t *character)
{
    static int x = 0;
    sfIntRect default_rect = {0, 0, 40, 40};

    if (list->clocks[0]->seconds >= 0.1) {
        x += 1;
        move_rect(&character->rect, 85, 340);
        sfSprite_setTextureRect(character->sprite, character->rect);
    }
    if (x == 3) {
        x = 0;
        character->rect = default_rect;
        character->action = IDLE;
    }
}

void viking_jump(list_t *list, char_t *character, col_t *col)
{
    character->clock->time = sfClock_getElapsedTime(character->clock->clock);
    character->clock->seconds = character->clock->time.microseconds / 1000000.0;
    if (character->clock->seconds <= 0.5) {
        if ((check_collisions(col, list))) {
            character->jump = 0;
            return;
        }
        if (character->dir == 0)
            character->rect.top = 280;
        if (character->dir == 1)
            character->rect.top = 320;
        character->rect.left = 0;
        sfSprite_setTextureRect(character->sprite, character->rect);
        if (list->clocks[2]->seconds >= 0.001)
            character->position.y -= 12;
    }
    if (character->clock->seconds >= 0.5)
        character->jump = 0;
}
