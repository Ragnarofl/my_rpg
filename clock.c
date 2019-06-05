/*
** EPITECH PROJECT, 2018
** clock.c
** File description:
** Clock gestion
*/

#include "include/my.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (offset != max_value)
        rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

clocki_t *create_clock(void)
{
    clocki_t *clock = malloc(sizeof(*clock));

    clock->clock = sfClock_create();
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    return (clock);
}

void get_time(clocki_t **clocks)
{
    if (!clocks)
        return;
    for (int i = 0; i < 5; i++) {
        clocks[i]->time = sfClock_getElapsedTime(clocks[i]->clock);
        clocks[i]->seconds = clocks[i]->time.microseconds / 1000000.0;
    }
}

clocki_t **get_clocks(void)
{
    clocki_t **clocks = malloc(sizeof(clocki_t *) * 5);

    clocks[0] = create_clock();
    clocks[1] = create_clock();
    clocks[2] = create_clock();
    clocks[3] = create_clock();
    clocks[4] = create_clock();
    return (clocks);
}

void manage_clock(clocki_t **clocks, list_t *list, int *i)
{
    (void)list;
    (void)i;
    get_time(clocks);
}

void restart_clocks(clocki_t **clocks)
{
    float e_inv_duration = 0.2;

    if (clocks[0]->seconds >= 0.1)
        sfClock_restart(clocks[0]->clock);
    if (clocks[3]->seconds >= 0.08)
        sfClock_restart(clocks[3]->clock);
    if (clocks[1]->seconds >= 0.01)
        sfClock_restart(clocks[1]->clock);
    if (clocks[2]->seconds >= 0.001)
        sfClock_restart(clocks[2]->clock);
    if (clocks[C_INV]->seconds >= e_inv_duration)
        sfClock_restart(clocks[C_INV]->clock);
}
