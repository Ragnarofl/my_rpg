/*
** EPITECH PROJECT, 2018
** viking_setup.c
** File description:
** viking setup
*/

#include "my.h"

void viking_setup_run(char_t *character, int dir)
{
    character->dir = dir;
    character->action = RUN;
    if (character->dir == LEFT)
        character->rect.top = 240;
    else
        character->rect.top = 200;
    character->rect.height = 40;
    character->rect.width = 40;
    sfSprite_setTextureRect(character->sprite, character->rect);
}

void viking_setup_jump(char_t *character)
{
    sfClock_restart(character->clock->clock);
    character->jump = 1;
    if (character->dir == LEFT)
        character->rect.top = 320;
    else
        character->rect.top = 280;
    sfSprite_setTextureRect(character->sprite, character->rect);
}

void viking_setup_attack(char_t *character)
{
    sfIntRect attack_rect = {0, 0, 49, 43};

    character->rect = attack_rect;
    character->action = L_ATTACK;
    if (character->dir == LEFT)
        character->rect.top = 43;
    else
        character->rect.top = 0;
    sfSprite_setTextureRect(character->sprite, character->rect);
}

void viking_setup_heavy_attack(char_t *character)
{
    sfIntRect heavy_attack_rect = {0, 0, 85, 40};

    character->rect = heavy_attack_rect;
    character->action = H_ATTACK;
    if (character->dir == LEFT)
        character->rect.top = 760;
    else
        character->rect.top = 720;
    sfSprite_setTextureRect(character->sprite, character->rect);
}
