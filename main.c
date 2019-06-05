/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main rpg
*/

#include "include/my.h"
#include "include/particles.h"

void  analyse_events(window_t *window, list_t **l, int *i, partBuffer *buffer)
{
    sfEvent eve = window->eve;

    if (eve.type == sfEvtKeyPressed) {
        if (eve.key.code == sfKeyEscape && *i == 0)
            sfRenderWindow_close(window->win);
        else if (eve.key.code == sfKeyEscape && (*i == 2))
            *i = 3;
    }
    if (eve.type == sfEvtKeyPressed) {
        if (eve.key.code == sfKeyI && *i == 2)
            *i = 4;
        else if ((eve.key.code == sfKeyI || eve.key.code == sfKeyEscape)\
        && *i == 4)
            *i = 2;
    }
    if (eve.type == sfEvtClosed)
        sfRenderWindow_close(window->win);
    if (eve.type == sfEvtMouseButtonReleased && l[*i]->buttons != NULL)
        check_buttons_click(window->win, eve, l, i);
    if (eve.type == sfEvtKeyPressed)
        key_pressed(window, l, i, buffer);
    if (eve.type == sfEvtKeyReleased)
        key_released(window, l, i, buffer);
    if (eve.type == sfEvtMouseButtonPressed && (*i) == 2)
        enemy_spawn_at_mpos(l, window);
}

void manage_window(window_t *window, list_t **list)
{
    int i = 0;
    partBuffer *buffer = newPartBuffer(250000);
    col_t *col = get_file("assets/map.json");

    while (sfRenderWindow_isOpen(window->win)) {
        while (sfRenderWindow_pollEvent(window->win, &window->eve))
            analyse_events(window, list, &i, buffer);
        sfRenderWindow_display(window->win);
        sfRenderWindow_clear(window->win, sfBlack);
        check_buttons_hoover(window->win, list[i], &i);
        get_time(list[i]->clocks);
        manage_music(list[0]);
        if (i == 2) {
            enemy_gravity(list[i], col);
            enemies_interactions(list);
            move_char(list[i], list[i]->first->player, col);
            item_animation(list[i], list[i]->first->items);
            gravity(list[i], col);
        }
        if (i == 4) {
            viking_idle(list[i], list[i]->first->player);
            draw_inventory(window->win, list, list[2]->first->player->inv->items);
        }
        updatePartBuffer(buffer);
        if (i != 4)
            draw_list(window->win, list[i]);
        drawPartBufer(buffer, window->win);
        if (list[i]->clocks)
            restart_clocks(list[i]->clocks);
    }
    free(buffer);
}

int main(void)
{
    char c;
    long int random_test = (long int)&c;
    window_t *win = malloc(sizeof(*win));
    sfVideoMode mode = {1920, 1080, 32};
    list_t **list_array = create_list_array();

    srand((unsigned int)random_test);
    win->win = sfRenderWindow_create(mode, "my_rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win->win, 60);
    manage_window(win, list_array);
    return (0);
}
