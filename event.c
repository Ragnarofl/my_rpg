/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** event gestion
*/

#include "include/my.h"
#include "include/player.h"
#include "include/particles.h"

void setup_actions(char_t *character)
{
    if (character->tab[0] == 0 && character->tab[1] == 0) {
        character->rect.left = 0;
        character->action = 0;
    }
    if (character->tab[0] == 1 && character->tab[1] == 0) {
        viking_setup_run(character, RIGHT);
        character->action = RUN;
    } else if (character->tab[0] == 0 && character->tab[1] == 1) {
        viking_setup_run(character, LEFT);
        character->action = RUN;
    } else
        character->action = IDLE;
    if (character->tab[2] == 1)
        viking_setup_attack(character);
    if (character->tab[3] == 1 && character->tab[2] != 1)
        viking_setup_heavy_attack(character);
}

void check_move_key_pressed(char_t *character) {
    if (sfKeyboard_isKeyPressed(sfKeyD))
        character->tab[0] = 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        character->tab[1] = 1;
    if (sfKeyboard_isKeyPressed(sfKeyJ))
        character->tab[2] = 1;
    if (sfKeyboard_isKeyPressed(sfKeyK))
        character->tab[3] = 1;
    if (character->action != L_ATTACK && character->action != H_ATTACK)
        setup_actions(character);
}

void check_move_key_released(window_t *win, char_t *character) {
    if (win->eve.key.code == sfKeyD)
        character->tab[0] = 0;
    if (win->eve.key.code == sfKeyQ)
        character->tab[1] = 0;
    if (win->eve.key.code == sfKeyJ)
        character->tab[2] = 0;
    if (win->eve.key.code == sfKeyK)
        character->tab[3] = 0;
    if (character->action != L_ATTACK && character->action != H_ATTACK)
        setup_actions(character);
}

void key_pressed(window_t *win, list_t **list, int *i, partBuffer *buffer)
{
    char_t *c = NULL;

    (void)win;
    if (*i == 2 && list[2]->first->player->action != L_ATTACK) {
        c = list[2]->first->player;
        check_move_key_pressed(c);
        if (sfKeyboard_isKeyPressed(sfKeyZ) && c->jump == 0)
            viking_setup_jump(c);
        if (sfKeyboard_isKeyPressed(sfKeyK) \
        && (c->action == IDLE || c->action == RUN))
            viking_setup_heavy_attack(c);
        if (sfKeyboard_isKeyPressed(sfKeyE) \
        && items_interactions(list[2], list[2]->first->items)) {
            add_in_inventory(list[2], grab_object(list[2]));
            create_particles(c->position, buffer, sfWhite);
            enemy_spawn_at_grab(list, win);
        }
    }
}

void key_released(window_t *win, list_t **list, int *i, partBuffer *buffer)
{
    char_t *character = NULL;

    (void)buffer;
    if (*i == 2) {
        character = list[2]->first->player;
        check_move_key_released(win, character);
    }
}
