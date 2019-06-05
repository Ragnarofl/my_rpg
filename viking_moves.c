/*
** EPITECH PROJECT, 2018
** viking_moves.c
** File description:
** character moving functions
*/

#include "include/my.h"

void action_char(list_t *list, char_t *character, col_t *col)
{
    if (character->jump == 1)
        viking_jump(list, character, col);
    if (character->action == L_ATTACK)
        viking_light_attack(list, character);
    if (character->action == H_ATTACK)
        viking_heavy_attack(list, character);
    if (character->action == BLOCK)
        viking_block(list, character);
    if (character->action == GET_HIT)
        viking_gethit(list, character);
    if (character->action == DIE)
        viking_death(list, character);
}

void move_char(list_t *list, char_t *character, col_t *col)
{
    if (character->action == IDLE && character->jump == 0)
        viking_idle(list, character);
    if (character->action == RUN)
        viking_run(list, character, col);
    if (character->action == JUMP)
        viking_jump(list, character, col);
    else
        action_char(list, character, col);
}
