/*
** EPITECH PROJECT, 2018
** viking_setup2.c
** File description:
** viking setup file 2
*/

#include "my.h"

void viking_setup_dash(char_t *character)
{
    character->action = DASH;
    if (character->dir == LEFT)
        character->rect.top = 560;
    else
        character->rect.top = 520;
    sfSprite_setTextureRect(character->sprite, character->rect);
}

void viking_setup_block(char_t *character)
{
    character->action = BLOCK;
    if (character->dir == LEFT)
        character->rect.top = 480;
    else
        character->rect.top = 440;
    sfSprite_setTextureRect(character->sprite, character->rect);

}

void viking_setup_gethit(char_t *character)
{
    character->action = GET_HIT;
    if (character->dir == LEFT)
        character->rect.top = 400;
    else
        character->rect.top = 360;
    character->rect.left = 0;
    sfSprite_setTextureRect(character->sprite, character->rect);
}

void viking_setup_death(char_t *character)
{
    sfIntRect death_rect = {0, 0, 45, 40};

    character->rect = death_rect;
    character->action = DIE;
    if (character->dir == LEFT)
        character->rect.top = 658;
    else
        character->rect.top = 610;
    character->rect.left = 0;
    sfSprite_setTextureRect(character->sprite, character->rect);
}
